# IT MUST BE RUN AS ADMINISTRATOR TO WORK.
import psutil
import requests
import json
from datetime import datetime, timedelta
import time
import threading
import keyboard
import os
import csv
import pandas as pd

# Define the interrupt key & monitoring duration here
interrupt_key = 'a'  # Desired interrupt key here
run_time = 20  # seconds; 'None' for indefinite runtime

# Define port numbers if known, otherwise leave as "None"
usb_port = None
bluetooth_port = None

# For output logging
# output_directory_path = r"C:\Users\remote\Desktop\241120 Max's Larson Davis Data Extraction Programming\Test Output" # set output folder
# base_output_file = "time_history" # name of output file will have date as prefix and version number as suffix
# output_file_extension = ".csv" # Currently ONLY support .csv

device_name = None
device_serial = None
running = True

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
        return True

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
        meter_time = content.get("Time") # in Unix time
        LAeq = content.get("LAeq")

        # Current time
        current_time = datetime.now().strftime("%Y/%m/%d %H:%M:%S")
        # Meter time converted from Unix time to UTC+8 time zone
        if meter_time is not None:
            # If the meter is outputting UTC time (i.e. 8 hours behind HK time), use the next line
            meter_time_hk = datetime.utcfromtimestamp(meter_time) # + timedelta(hours=8)
            meter_time_hk_str = meter_time_hk.strftime("%Y/%m/%d %H:%M:%S")  # Format for printing
        else:
            meter_time_hk_str = "Meter time not available"

        # Print the extracted values with timestamp
        if LAeq is not None:
            print(f"PC Time: {current_time}; Meter Time: {meter_time_hk_str}; LAeq: {LAeq}")
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
    if usb_port is None:
        find_LD_meter_ports()  # This will start finding usb_port and bluetooth_port
    else:
        print("USB port defined by user, skipping port search.")
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
    device_info_success = get_device_info(current_port)

    # Also checks if the given/found port is correct
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

        # Retry retrieving device info after switching ports
        max_retries = 3  # Set maximum number of retries
        for attempt in range(max_retries):
            print(f"Attempting to retrieve device info from {current_port} (Attempt {attempt + 1}/{max_retries})")
            device_info_success = get_device_info(current_port)
            if device_info_success:
                print(f"Device: {device_name} - {device_serial}")
                break  # Exit the retry loop on success
            else:
                print("Failed to retrieve device info. Retrying...")
                time.sleep(1)
        
        if not device_info_success:
            print("Still unable to retrieve device info from USB. Exiting...")
            exit()

    else:
        # Successful retrieval of device info
        print(f"Device: {device_name} - {device_serial}")

#-------------------------------------------------------------------

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
                    elif bluetooth_port != current_port and usb_port is None:
                        print(f"Switching to new Bluetooth Port: {bluetooth_port}")
                        current_port = bluetooth_port

                    # Exit program if no valid ports found
                    if usb_port is None and bluetooth_port is None:
                        print("No valid ports found. Exiting...")
                        running = False

                next_poll_time += 1 # next polling time is 1 second later

            if run_time is not None and (current_time - start_time) >= run_time:
                print("User-defined duration has elapsed. Exiting...")
                running = False # set running to False to stop the loop

    except KeyboardInterrupt:
        print("Interrupted by user. Stopping the program.")
