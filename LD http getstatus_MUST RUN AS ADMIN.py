# Larson Davis Sound Meter Monitoring Software
# IT MUST BE RUN AS ADMINISTRATOR TO WORK.
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

# Define the interrupt key & monitoring duration here
interrupt_key = 'z'  # Desired interrupt key here
run_time = 10  # seconds; 'None' for indefinite runtime

# Define port numbers if known, otherwise leave as "None"
usb_port = None
bluetooth_port = None

# For output logging
output_file_path = r"C:\Users\remote\Desktop\test_output" # set output folder
user_defined_filename = "output" # name of output file will have date as prefix and version number as suffix

device_name = None
device_serial = None
running = True

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
    global device_name, device_serial
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
        device_name = content.get("Device")
        device_serial = content.get("Serial Number")
        return True, device_name, device_serial  # Return success and extracted info

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
        pc_time = datetime.now().strftime("%Y/%m/%d %H:%M:%S")
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
            return False, None, None, None, None  # Return None for all values

        # Extract specific values from status page, add more if needed
        content = device_status_json.get("Status", {})
        meter_time = content.get("Time") # in Unix time
        LAeq = content.get("LAeq")

        # Meter time converted from Unix time to UTC+8 time zone
        if meter_time is not None:
        # If the meter is outputting UTC time (i.e. 8 hours behind HK time), use the next line
            meter_time_hk = datetime.utcfromtimestamp(meter_time) # + timedelta(hours=8)
            meter_time_hk_str = meter_time_hk.strftime("%Y/%m/%d %H:%M:%S")  # Format for printing
        else:
            meter_time_hk_str = "Meter time not available"

        ### DEBUG: End timing of the whole loop
        # end_time = time.perf_counter()  # End the timer
        # total_duration = end_time - start_time

        # Print the extracted values with both timestamps
        print(f"PC Time: {pc_time}; Meter Time: {meter_time_hk_str}; LAeq: {LAeq} dB; "
              f"Response Time: {response_time_str}s")

    except requests.exceptions.Timeout:
        print("Error: The request timed out.")
        return False, None, None, None, None  # Return None for all values
    except requests.exceptions.RequestException as e:
        print(f"Error accessing the device: {e}")
        return False, None, None, None, None  # Return None for all values

    # success, return PC time, meter time, LAeq, response time for data logging
    return True, pc_time, meter_time_hk_str, LAeq, response_time_str 

# Function to listen for the interrupt key
def listen_for_interrupt(interrupt_key):
    global running
    keyboard.wait(interrupt_key)  # Wait for the specified key press
    print(f"\n'{interrupt_key}' key pressed. Exiting...")
    running = False # running to False to prevent infinite loop when run_time = None

# Function to log data and export as CSV
def log_data(pc_time, meter_time, LAeq, filename="output.csv"):
    with open(filename, mode='a', newline='') as file:
        writer = csv.writer(file)
        writer.writerow([pc_time, meter_time, LAeq])  # Write a new row

# Function to clean up the program after finishing or interruptions
# Add any additional cleanup tasks, logics here; e.g. close files, release resources, etc.
def cleanup():
    print("Performing cleanup tasks...")
    logging.info("Performing cleanup tasks...")

    # Close the CSV file if it's open
    global csvfile
    if csvfile is not None:
        try:
            csvfile.close()
            print("CSV file closed.")
            logging.info("CSV file closed.")
        except Exception as e:
            print(f"Error closing CSV file: {e}")
            logging.error(f"Error closing CSV file: {e}")

    # Close the logging handlers if needed (if you created a custom handler)
    # For default logging configuration, this is usually not necessary
    # but if you had custom handlers, you would loop through them and close here
    for handler in logging.getLogger().handlers:
        try:
            handler.close()
            logging.info(f"Closed log file: {handler.baseFilename}")
        except Exception as e:
            print(f"Error closing log file handler {handler.baseFilename}: {e}")
            logging.error(f"Error closing log file handler {handler.baseFilename}: {e}")


# Set up debug logging configuration before main code
logging.basicConfig(
    filename=os.path.join(output_file_path, "debug_log.txt"),
    level=logging.DEBUG,
    format='%(asctime)s - %(levelname)s - %(message)s'
)

# Redirect stdout to logger
# Captures all print statements in the log, redirect standard output to a logging function 
class StreamToLogger:
    def __init__(self, logger, level=logging.INFO):
        self.logger = logger
        self.level = level

    def write(self, message):
        if message.strip():  # Avoid logging empty messages
            self.logger.log(self.level, message.strip())

    def flush(self):
        pass  # Needed for compatibility with flush method

sys.stdout = StreamToLogger(logging.getLogger(), logging.INFO)

# Example of logging to console and file
print("Starting data extraction...")
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
                print(f"Device: {device_name} - {device_serial}")
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
        print(f"Device: {device_name} - {device_serial}")

#-------------------------------------------------------------------
### Being loop to poll data from status page every second
    start_time = time.time()
    next_poll_time = start_time + 1  # Set the time for the next poll

    try:
        # Create and keep the CSV output file open for data logging
        csvfile = open(output_file_path, mode='w', newline='')
        csv_writer = csv.writer(csvfile)
        csv_writer.writerow([f"Sound Meter Model: {device_name}", f"Serial Number: {device_serial}"])
        csv_writer.writerow(["PC Date", "PC Time", "Meter Date", "Meter Time", "LAeq"])  # Header

        # while the program has not been interrupted
        while running: 
            # trigger the poll if current time matches the next poll time
            current_time = time.time()  # Record the time now
            if current_time >= next_poll_time:
                success = get_device_status(current_port) 
                # which returns True, pc_time, meter_time_hk_str, LAeq, response_time_str
                # Record data to CSV 
                if success:
                    c = pc_time
                    csv_writer.writerow([pc_time, meter_time, LAeq])

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
        print("Interrupted by user. Stopping the program.")
        logging.info("Interrupted by user. Stopping the program.")
        running = False  # running to False to prevent infinite loop when run_time = None

    finally:
        cleanup()  # Ensure cleanup is called on exit