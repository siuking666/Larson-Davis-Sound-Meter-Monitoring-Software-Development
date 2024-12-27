### Larson Davis Sound Meter Monitoring Software
### IT MUST BE RUN AS ADMINISTRATOR TO WORK.
### Originally written in Python 3.9

import psutil
import requests
import json
from datetime import datetime, timedelta
import time
import threading
import keyboard
import csv
import os
import logging
import sys
import sqlite3

#--------------------------------------------------------------------------------------------
# SQL functionality integration part

# Create database names
database_directory = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase"

# Function to connect to the SQLite database
def connect_to_database(db_path, max_retries=3, delay=1):
    """Connect to the database with a specified number of retries."""
    for attempt in range(max_retries):
        try:
            conn = sqlite3.connect(db_path)
            print("Connection to database successful.")
            return conn  # Return the connection if successful
        except sqlite3.Error as e:
            print(f"Error connecting to database: {e}. Retrying in {delay} second(s)... (Attempt {attempt + 1}/{max_retries})")
            time.sleep(delay)  # Wait before retrying
    print("Failed to connect to the database after multiple attempts.")
    return None  # Return None if connection fails

# Function to insert monitoring data into the database
def insert_measurement_data(conn, pc_date, pc_time, meter_date, meter_time, LAeq, response_time):
    cursor = conn.cursor()
    try:
        cursor.execute('''
            INSERT INTO LiveMeasurements (pc_date, pc_time, meter_date, meter_time, LAeq, response_time)
            VALUES (?, ?, ?, ?, ?, ?)
        ''', (pc_date, pc_time, meter_date, meter_time, LAeq, response_time))
        conn.commit()  # Commit the changes
    except sqlite3.IntegrityError:
        print(f"Duplicate entry for meter_date: {meter_date} and meter_time: {meter_time}. Entry not added.")
    finally:
        cursor.close()

#--------------------------------------------------------------------------------------------

# Define the interrupt key & monitoring duration here
interrupt_key = 'z'  # Desired interrupt key here
run_time = 300  # seconds; 'None' for indefinite runtime

# Define port numbers if known, otherwise leave as "None"
usb_port = None
bluetooth_port = None

# Define the output directory and file path for output logging
output_directory = r"C:\Users\WAL01\Desktop\test_output" # set output folder
output_filename = "test.csv" # Wishlist: name will have date as prefix and version number as suffix

device_full_name = None
device_model = None
device_serial = None
running = True

# Create the output directory if it doesn't exist
os.makedirs(output_directory, exist_ok=True)

# Ensure that the output filename is valid
if not output_filename or output_filename == ".csv":
    output_filename = "output.csv"  # Fallback to a default name
output_file_path = os.path.join(output_directory, output_filename)
log_file_path = os.path.join(output_directory, "debug_log.txt")

# Function to verify output file does not already exist and prevent overwrite with versioning
def get_unique_filename(base_path, default_filename="output.csv"):
    # Check if the base path is just an extension or empty
    base_name = os.path.basename(base_path)
    
    # Set a default filename if the base name is empty or matches specific conditions
    if not base_name or base_name == ".csv":
        base_path = os.path.join(os.path.dirname(base_path), default_filename)

    # Ensure the filename has the correct extension
    if not base_path.endswith('.csv'):
        base_path += '.csv'  # Default to .csv for output files

    # Initialize versioning
    version = 0
    # Base name for versioning
    name, ext = os.path.splitext(base_path)

    # Increment version number until a unique filename is found
    while os.path.exists(base_path):
        version += 1
        base_path = f"{name}_v{version}{ext}"

    return base_path

# Define a global variable for the CSV file handle
csvfile = None

# Function to search for running HttpLD.exe process & extract the USB/Bluetooth port number
# manual interruption check is included
def find_LD_meter_ports():
    global usb_port, bluetooth_port
    # Loop through all background processes running
    for process in psutil.process_iter(['pid', 'name', 'cmdline']):
        if not running:
            print("port search interrupted")
            return
        try:
            # Execute on HttpLD.exe processes
            if process.info['name'] == 'HttpLD.exe':
                cmdline = process.info['cmdline']
                print(f"Found HttpLD.exe - Command Line: {cmdline}")  # Debug exact process as output

                if cmdline:
                    # Check if 'USB' is in any command line arguments
                    if any('USB' in arg for arg in cmdline):  # Loop and check each argument
                        # port
                        if '-p' in cmdline:
                            USB_process = str(cmdline)  # Capture the command line
                            print(f"USB_process: {USB_process}")  # Print the USB process command line
                            port_index = cmdline.index('-p') + 1
                            # Ensure the index is valid
                            if port_index < len(cmdline):
                                usb_port = cmdline[port_index]
                                print(f"Detected USB port: {usb_port}")  # Debug output
                    # Check if 'BLE' is in the command line for bluetooth
                    if any('BLE' in arg for arg in cmdline):
                        if '-p' in cmdline:
                            BLUETOOTH_process = str(cmdline)
                            print(f"BLE_process: {BLUETOOTH_process}")  # Print the BLE process command line
                            port_index = cmdline.index('-p') + 1
                            # Ensure the index is valid
                            if port_index < len(cmdline):
                                bluetooth_port = cmdline[port_index]
                                print(f"Detected Bluetooth port: {bluetooth_port}")  # Debug output

        except psutil.NoSuchProcess:
            print('Error: No such process found.')
            continue
        except psutil.AccessDenied:
            print('Error: Access denied to process.')
            continue

    # Inform if no port was found
    if usb_port is None:
        print('Error: No USB port found for HttpLD.exe.')
    if bluetooth_port is None:
        print('Error: No Bluetooth port found for HttpLD.exe.')
    return usb_port, bluetooth_port

# Function to connect to HTTP status page, check response time, check for JSON format & extract device info (device model & serial)
# Typical response time: 0.11 sec
def get_device_info(port):
    global device_full_name, device_model, device_serial
    url = f"http://127.0.0.1:{port}/sdk?func=getpagestatus"
    try:
        ### DEBUG: Start measuring total request time
        request_start_time = time.perf_counter()  # Start the timer for the request

        # Send the GET request with a timeout to prevent hanging
        device_status = requests.get(url, timeout=5)
        device_status.raise_for_status()  # Raise an error for bad responses

        ### DEBUG: stop measuring total request time
        request_end_time = time.perf_counter()  # End the timer for the request
        request_duration = request_end_time - request_start_time
        print(f"Response Time: {request_duration:.6f} seconds")

        ### returns the entire HTTP status page for debugging
        # print("Response from device:", device_status.text)

        # Check if response is JSON format and parse
        # Process time: 0.0004 seconds
        if device_status.headers.get('Content-Type') == 'application/json':
            device_status_json = device_status.json()
        else:
            print("Error: Expected JSON response but received:", device_status.headers.get('Content-Type'))
            return False, None, None  # Return None for device info

        # Extract device info
        content = device_status_json.get("Status", {})
        device_full_name = content.get("Device")
        device_model = content.get("Model")
        device_serial = content.get("Serial Number")
        return True, device_full_name, device_model, device_serial  # Return success and extracted info

    except requests.exceptions.Timeout:
        print("Error: The request timed out.")
        return False, None, None  # Return None for device info
    except requests.exceptions.RequestException as e:
        print(f"Error accessing the device: {e}")
        return False, None, None  # Return None for device info
    except json.JSONDecodeError:
        print("Error: Response is not valid JSON.")
        return False, None, None  # Return None for device info

# Function to connect HTTP status page, check for JSON format & poll device status
# Typical function runtime (response + compute): 0.11 + 0.0004 sec
def get_device_status(port):
    url = f"http://127.0.0.1:{port}/sdk?func=getpagestatus"
    try:
        ### DEBUG: Start timing the data poll loop (request, JSON check & parameters extraction)
        start_time = time.perf_counter()

        # PC time at the time of requesting status refresh
        pc_datetime = datetime.now()
        pc_date = pc_datetime.strftime("%Y/%m/%d")
        pc_time = pc_datetime.strftime("%H:%M:%S")  # Get time with milliseconds
        # pc_time = pc_datetime.strftime("%H:%M:%S.%f")[:-5]  # Get time with milliseconds

        device_status = requests.get(url, timeout=5)
        device_status.raise_for_status()  # Raise an error for bad responses 
  
        ### Mark down response time
        end_time_response = time.perf_counter()  # End the timer for the response
        response_time = end_time_response - start_time  # Calculate response time
        response_time_str = f"{response_time:.3f}" # 3 decimal places

        # Check if response is JSON format and parse
        if device_status.headers.get('Content-Type') == 'application/json':
            device_status_json = device_status.json()
        else:
            print("Error: Expected JSON response but received:", device_status.headers.get('Content-Type'))
            return False, None, None, None, None, None, None  # Return None for all values

        # Extract specific values from status page, add more if needed
        content = device_status_json.get("Status", {})
        meter_datetime = content.get("Time") # in Unix time
        LAeq = content.get("LAeq")

        # Meter time converted from Unix time to UTC+8 time zone
        if meter_datetime is not None:
        # If the meter is outputting UTC time (i.e. 8 hours behind HK time), use the next line
            meter_datetime_hk = datetime.utcfromtimestamp(meter_datetime) # + timedelta(hours=8)
            meter_date = meter_datetime_hk.strftime("%Y/%m/%d")  # Extract date
            meter_time = meter_datetime_hk.strftime("%H:%M:%S")  # Extract time
        else:
            meter_date = "Unavailable"
            meter_time = "Unavailable"

        if LAeq is None:
            LAeq = "Unavailable"

        ### DEBUG: End timing of the whole loop
        # end_time = time.perf_counter()  # End the timer
        # total_duration = end_time - start_time

        # Print the extracted values with both timestamps
        print(f"PC Time: {pc_date} {pc_time}; Meter Time: {meter_date} {meter_time}; LAeq: {LAeq} dB; "
              f"Response Time: {response_time_str}s")

    except requests.exceptions.Timeout:
        print("Error: The request timed out.")
        return False, None, None, None, None, None, None  # Return None for all values
    except requests.exceptions.RequestException as e:
        print(f"Error accessing the device: {e}")
        return False, None, None, None, None, None, None  # Return None for all values

    # success, return PC time, meter time, LAeq, response time for data logging
    return True, pc_date, pc_time, meter_date, meter_time, LAeq, response_time_str

# Function to listen for the interrupt key
def listen_for_interrupt(interrupt_key):
    global running
    keyboard.wait(interrupt_key)  # Wait for the specified key press
    print(f"\n'{interrupt_key}' key pressed. Exiting...")
    running = False # running to False to prevent infinite loop when run_time = None

# Function to initialize the CSV file and write headers
# Also makes sure that the file is properly CLOSED and FLUSHED to prevent formatting bug at the end
def initialize_csv(filename, device_model, device_serial):
    if not os.path.exists(filename):
        with open(filename, mode='w', newline='') as file:
            writer = csv.writer(file)
            # Structure: [Sound Meter Model, device_model, Serial Number, device_serial, empty]
            writer.writerow(["Sound Meter Model", device_model, "Serial Number", device_serial, ""])
            writer.writerow(["PC Date", "PC Time", "Meter Date", "Meter Time", "LAeq"])

# Function to log data and export as CSV
def log_data(pc_date, pc_time, meter_date, meter_time, LAeq, filename):
    try:
        with open(filename, mode='a', newline='') as file:
            writer = csv.writer(file)
            # Ensure all fields are correctly logged
            writer.writerow([
                pc_date,
                pc_time,
                meter_date if meter_date is not None and meter_date != "Unavailable" else "",
                meter_time if meter_time is not None and meter_time != "Unavailable" else "",
                LAeq if LAeq is not None and LAeq != "Unavailable" else ""
            ])
            #print(f"Logged: {pc_date}, {pc_time}, {meter_date}, {meter_time}, {LAeq}")  # Debug print
    except Exception as e:
        print(f"Error writing to CSV: {e}")  # Print any errors encountered

# Function to clean up the program after finishing or interruptions
# Add any additional cleanup tasks, logics here; e.g. close files, release resources, etc.
def cleanup():
    logging.info("Performing cleanup tasks...")

    # Close the CSV file if it's open
    global csvfile
    if csvfile is not None:
        try:
            csvfile.close()
            logging.info("CSV file closed.")
        except Exception as e:
            logging.error(f"Error closing CSV file: {e}")

    # Call shutdown to flush and close all logging handlers
    logging.shutdown()

def is_file_locked(file_path):
    # Check if the specified file is read-only
    if not os.path.exists(file_path):
        return False  # File does not exist, so it isn't locked
        
    # Check if the file is read-only
    if os.access(file_path, os.W_OK):
        return False  # File is writable
    else:
        return True  # File is read-only or locked by another process

# Set up debug logging configuration before main code
# Check if the log file is locked
if is_file_locked(log_file_path):
    logging.warning(f"The file '{log_file_path}' cannot be written to, LOGGING DISABLED")

# Generate a unique output filename if it exists
if os.path.exists(output_file_path):
    print(f"Warning: The output file '{output_file_path}' already exists. Switching to a new file.")
    output_file_path = get_unique_filename(output_file_path)

# Store the original stdout
original_stdout = sys.stdout

# Redirect stdout to logger
# Captures all print statements in the log, redirect standard output to a logging function 
class StreamToLogger:
    def __init__(self, logger, level=logging.INFO):
        self.logger = logger
        self.level = level

    def write(self, message):
        if message.strip():  # Avoid logging empty messages
            self.logger.log(self.level, message.strip())
            # Ensure a newline at the end of the message when writing to console
            if not message.endswith('\n'):
                message += '\n'
            original_stdout.write(message)  # Write to the original stdout (console)

    def flush(self):
        pass  # Needed for compatibility with flush method

# Set up the logging configuration with the (possibly new) log file
logging.basicConfig(
    filename=log_file_path,
    filemode='w',  # Use 'w' to overwrite the log file each time
    level=logging.DEBUG,
    format='%(asctime)s - %(levelname)s - %(message)s'
)

# Redirect standard output to the logger
sys.stdout = StreamToLogger(logging.getLogger(), logging.INFO)

# Example of logging to console and file
logging.info("Starting data extraction...")

# main execution block and other code follows...

#--------------------------------------------------------------------------------------------
#--------------------------------------------------------------------------------------------

# Main execution block
if __name__ == "__main__":
    ### Start a separate thread to listen for the interrupt key
    threading.Thread(target=listen_for_interrupt, args=(interrupt_key,), daemon=True).start()

    ### First, attempt to search for the port numbers if undefined
    # If usb_port has been defined by user, skip search to save time
    if usb_port is None:
        find_LD_meter_ports()  # This will start finding usb_port and bluetooth_port
    else:
        print(f"USB port defined as {usb_port} by user, skipping port search.")
    print("---------------------------------")

    # Handles when none of the ports is found by the program, while device is connected
    # usually due to lack of privilege to read System processes
    # Solution is to run as administrator
    if usb_port is None and bluetooth_port is None:
        print("Cannot find any ports, RUN THIS AS ADMINISTRATOR, exiting...")
        running = False  # running to False to prevent infinite loop when run_time = None

    else:
    # Feedback on ports
        if usb_port is not None:
            print(f"Final USB Port: {usb_port}")
        if bluetooth_port is not None:
            print(f"Final Bluetooth Port: {bluetooth_port}")
        print("---------------------------------")

#-----------------------------------------------------------------------------
    ### retrieve device info with device_info function, i.e. model and serial numbers
    # Start with available port, prioritizes USB
    current_port = usb_port if usb_port is not None else bluetooth_port
    device_info_success = get_device_info(current_port)

    # If device request retrieval fails, search for the ports again for verification
    if not device_info_success:
        print("Failed to retrieve device info. Attempting to find available ports...")
        find_LD_meter_ports()  # Check for available ports again

    # Update current_port based on the newly found ports
        if usb_port != current_port:
            print(f"Switching to new USB Port: {usb_port}")
            current_port = usb_port
        elif bluetooth_port != current_port and usb_port is None:
            print(f"Switching to new Bluetooth Port: {bluetooth_port}")
            current_port = bluetooth_port

    # With updated ports, retry retrieving device info (3 attempts)
        max_retries = 3  # Set maximum number of retries
        for attempt in range(max_retries):
            # user interruption check during each attempt
            if not running:
                break
            print(f"Attempting to retrieve device info from {current_port} (Attempt {attempt + 1}/{max_retries})")
            device_info_success = get_device_info(current_port)

            # If successful during retries, print the info and exit the retry logic
            if device_info_success:
                print(f"Device: {device_full_name} - {device_model} - {device_serial}")
                break  # Exit the retry loop on success
            else:
            # If failed during retries, try again in 1 second
                print("Failed to retrieve device info. Retrying...")
                time.sleep(1)
        
        # If all retries exhausted and still fails, show feedback and stops the program
        if not device_info_success:
            print("Still unable to retrieve device info from USB. Exiting...")
            running = False  # running to False to prevent infinite loop when run_time = None

    else:
        # Successful retrieval of device info
        print(f"Device: {device_full_name} - {device_model} - {device_serial}")

#-------------------------------------------------------------------
    # Connect to the live monitoring database
    if device_info_success:
        live_monitoring_db = os.path.join(database_directory, f"{device_model}_{device_serial}_live-monitoring.db")
        conn = connect_to_database(live_monitoring_db)
    else:
        print("Device information not available, exiting...")
        running = False
        sys.exit()
#-------------------------------------------------------------------
### Being loop to poll data from status page every second
    start_time = time.time()
    next_poll_time = start_time + 1  # Set the time for the next poll

    try:
        # Function to initialize the CSV file and write headers
        # Also makes sure that the file is properly CLOSED and FLUSHED to prevent formatting bug at the end
        initialize_csv(output_file_path, device_model, device_serial)
        # while the program has not been interrupted, loop data logging
        while running: 
            # trigger the poll if current time matches the next poll time
            current_time = time.time()  # Record the time now
            if current_time >= next_poll_time:
                success, pc_date, pc_time, meter_date, meter_time, LAeq, response_time_str = get_device_status(current_port)
                # which returns True, pc_date, pc_time, meter_date, meter_time, LAeq, response_time_str
                # Reopen the CSV file and append data 
                if success:
                    log_data(pc_date, pc_time, meter_date, meter_time, LAeq, output_file_path)  # Call the new log_data function
                    #-------------------------------------------------------------------
                    # Check if the database connection is still valid
                    try:
                        cursor = conn.cursor()
                        cursor.execute("SELECT 1")  # Simple query to check connection
                    except sqlite3.Error:
                        print("Database connection lost. Attempting to reconnect...")
                        conn = connect_to_database(live_monitoring_db)  # Attempt to reconnect

                    # Continue to query the SQL for duplicate/existing entry. If not, append the data
                    if conn:
                        cursor = conn.cursor()
                        cursor.execute("SELECT COUNT(*) FROM LiveMeasurements WHERE meter_date = ? AND meter_time = ?", (meter_date, meter_time))
                        exists = cursor.fetchone()[0]

                        if exists:
                            print(f"Entry with meter_date={meter_date} and meter_time={meter_time} already exists. Skipping entry.")
                        else:
                            insert_measurement_data(conn, pc_date, pc_time, meter_date, meter_time, LAeq, response_time_str)
                            print(f"Inserted data: pc_date={pc_date}, pc_time={pc_time}, meter_date={meter_date}, meter_time={meter_time}, LAeq={LAeq}, response_time={response_time_str}")
                    else:
                        print("Database connection lost. Exiting...")
                        running = False
                    #-------------------------------------------------------------------
            # This should not happen, but if the device cannot be accessed, retry searching for ports
                if not success:
                    print("Failed to get device status, attempting to update ports...")
                    find_LD_meter_ports()  # Check for available ports again
                    # Update current_port based on the newly found ports
                    # if USB port is found to be the same, current_port is unchanged
                    # if USB port is found to be different, current_port gets updated
                    if usb_port != current_port:
                        print(f"Switching to new USB Port: {usb_port}")
                        current_port = usb_port
                    # If USB port is absent, check the Bluetooth port
                    # If bluetooth port is the same as current_port, it is unchanged
                    # If bluetooth port is found to be different, switch from old USB/BLU to new bluebooth port
                    elif bluetooth_port != current_port and usb_port is None:
                        print(f"Switching to new Bluetooth Port: {bluetooth_port}")
                        current_port = bluetooth_port
                    # Exit program if no valid ports found
                    if usb_port is None and bluetooth_port is None:
                        print("No valid ports found. Exiting...")
                        running = False  # running to False to prevent infinite loop when run_time = None

                next_poll_time += 1 # next polling time is 1 second later

        # Handles if monitoring duration is pre-set by user, and stops the program accordingly
            if run_time is not None and (current_time - start_time) >= run_time:
                print("User-defined duration has elapsed. Exiting...")
                running = False  # running to False to prevent infinite loop when run_time = None

    except KeyboardInterrupt:
        logging.info("Interrupted by user. Stopping the program.")
        running = False  # running to False to prevent infinite loop when run_time = None

    finally:
        # Ensure cleanup and close the connection
        if 'conn' in locals() and conn:
            conn.close()
            print("Database connection closed.")
        cleanup()  # Ensure cleanup is called on exit
        sys.exit() # Shutdown Python.exe upon exit