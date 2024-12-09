import psutil

# IT MUST BE RUN AS ADMINISTRATOR TO WORK.
# Function to search for HttpLD.exe process & extract the USB port number
def find_LD_meter_ports():
    usb_port = None
    bluetooth_port = None
    
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

    return usb_port, bluetooth_port

# Get the USB port number
usb_port, bluetooth_port = find_LD_meter_ports()
print("---------------------------------")
if usb_port is None and bluetooth_port is None:
    print("Cannot find any ports, RUN THIS AS ADMINISTRATOR")
if usb_port is not None:
    print(f"Final USB Port: {usb_port}")
if bluetooth_port is not None:
    print(f"Final Bluetooth Port: {bluetooth_port}")