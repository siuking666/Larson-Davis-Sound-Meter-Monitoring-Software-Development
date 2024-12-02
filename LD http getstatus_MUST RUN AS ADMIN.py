# IT MUST BE RUN AS ADMINISTRATOR TO WORK.
import psutil
import requests
import json
from datetime import datetime
import time
import threading
import keyboard

# Define the interrupt key & monitoring duration here
interrupt_key = 'q'  # Set your desired interrupt key here
run_time = 10  # seconds; 'None' for indefinite runtime
running = True

# unknown port numbers at the beginning
usb_port = None
bluetooth_port = None

device_name = None
device_serial = None

# Function to search for HttpLD.exe process & extract the USB port number
def find_LD_meter_ports():
    global usb_port, bluetooth_port
    # Loop through all background processes running
    for process in psutil.process_iter(['pid', 'name', 'cmdline']):
        try:
            # Execute on HttpLD.exe processes
            if process.info['name'] == 'HttpLD.exe':
                cmdline = process.info['cmdline']
                print(f"Found HttpLD.exe - Command Line: {cmdline}")  # Debug output

                if cmdline:
                    # Check if 'USB' is in any command line arguments
                    if any('USB' in arg for arg in cmdline):  # Check each argument
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

    # Inform if no USB port was found
    if usb_port is None:
        print('Error: No USB port found for HttpLD.exe.')
    if bluetooth_port is None:
        print('Error: No Bluetooth port found for HttpLD.exe.')

# Function to extract device info
def get_device_info(port):
    global device_name
    global device_serial
    url = f"http://127.0.0.1:{port}/sdk?func=getpagestatus"
    try:
        device_status = requests.get(url)
        device_status.raise_for_status()  # Raise an error for bad responses
        # Check if response is JSON format and parse
        if device_status.headers['Content-Type'] == 'application/json':
            device_status_json = device_status.json()
        else:
            print("Error: Expected JSON response but received:", device_status.headers['Content-Type'])
            return False and device_name and device_serial

        # Extract device info
        content = device_status_json.get("Status", {})
        device_name = content.get("Device")
        device_serial = content.get("Serial Number")
    except requests.exceptions.RequestException as e:
        print(f"Error accessing the device: {e}")  # Inform about the error
        return False # Indicate an error occurred
    except json.JSONDecodeError:
        print("Error: Response is not valid JSON.")
        return False # Indicate an error occurred

# Function to get device status
def get_device_status(port):
    url = f"http://127.0.0.1:{port}/sdk?func=getpagestatus"
    try:
        device_status = requests.get(url)
        # print("Response from device:", device_status.text)
        # ^ returns the entire HTTP status page

        device_status.raise_for_status()  # Raise an error for bad responses 
        
        # Check if response is JSON format and parse
        if device_status.headers['Content-Type'] == 'application/json':
            device_status_json = device_status.json()
        else:
            print("Error: Expected JSON response but received:", device_status.headers['Content-Type'])
            return False

        # Extract specific values
        content = device_status_json.get("Status", {})
        LAeq = content.get("LAeq")

        # Current time
        current_time = datetime.now().strftime("%Y/%m/%d %H:%M:%S")
        # Print the extracted values with timestamp
        if LAeq is not None:
            print(f"{current_time} LAeq: {LAeq}")
        else:
            print("L_Aeq and L_Ceq not found in the status page.")

    except requests.exceptions.RequestException as e:
        print(f"Error accessing the device: {e}")  # Inform about the error
        return False # Indicate an error occurred
    except json.JSONDecodeError:
        print("Error: Response is not valid JSON.")
        return False # Indicate an error occurred
    return True

# Function to listen for the interrupt key
def listen_for_interrupt(interrupt_key):
    global running
    keyboard.wait(interrupt_key)  # Wait for the specified key press
    print(f"\n'{interrupt_key}' key pressed. Exiting...")
    running = False

# Main execution block
if __name__ == "__main__":
    # First, attempt to find the port numbers if undefined
    find_LD_meter_ports()  # This will set usb_port and bluetooth_port
    print("---------------------------------")

    # If connected correctly, usually because lack of privilege to read System processes
    # Solution is to run it as administrator
    if usb_port is None and bluetooth_port is None:
        print("Cannot find any ports, RUN THIS AS ADMINISTRATOR")
        exit()

    else:
        if usb_port is not None:
            print(f"Final USB Port: {usb_port}")
        if bluetooth_port is not None:
            print(f"Final Bluetooth Port: {bluetooth_port}")
        print("---------------------------------")

#-----------------------------------------------------------------------------

        # Start with available port
        current_port = usb_port if usb_port is not None else bluetooth_port

        # Start a thread to listen for the interrupt key
        threading.Thread(target=listen_for_interrupt, args=(interrupt_key,), daemon=True).start()

        # retrieve device info with device_info function, does not read L_Aeq
        device_info = get_device_info(current_port)
        print(f"Device: {device_name} - {device_serial}")

        start_time = time.time()
        next_poll_time = start_time + 1  # Set the time for the next poll
        try:
            while running: # continuous loop
                current_time = time.time()  # Record the start time
                if current_time >= next_poll_time:
                    success = get_device_status(current_port)

                    if not success:  # If there was an error accessing the device
                        print("Attempting to find available ports...")
                        find_LD_meter_ports()  # Check for available ports again
                        # Update current_port based on the newly found ports
                        if usb_port != current_port:
                            print(f"Switching to new USB Port: {usb_port}")
                            current_port = usb_port
                        elif bluetooth_port != current_port:
                            print(f"Switching to new Bluetooth Port: {bluetooth_port}")
                            current_port = bluetooth_port

                    next_poll_time += 1 # next polling time is 1 second later

                if run_time is not None and (current_time - start_time) >= run_time:
                    print("User-defined duration has elapsed. Exiting...")
                    running = False # set running to False to stop the loop

        except KeyboardInterrupt:
            print("Interrupted by user. Stopping the program.")
