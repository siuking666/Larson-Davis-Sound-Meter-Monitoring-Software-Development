# Larson Davis Sound Meter Real-Time Monitoring Software Documentation
# 27/12/2024 by Ken Cheung

**Important: RUN AS ADMINISTRATOR or the software may fail to read the USB and Bluetooth ports used by the sound meter.**

# Pre-requisites:
- Python 3.11.9
- All imported packages installed in the Python Environment
- G4 LD Utility 5.1.2 installed
- For uncompiled code: any IDE (e.g. Jupyter / Visual Studio) installed
- Administrator rights / Run as Administrator
- SQLite database file present in the user-specified directory with the correct naming format
- Optional: Larson Davis Official SDK
- For safety, close debug and output files before using this software, and do not open them during monitoring to prevent possible data loss

# Current Features:
- GitHub Version Control (along with this documentation)
- Auto detect & display dynamic port numbers = plug-and-play
	- User can define known port numbers to speed up the process
	- Auto detect the correct port number if user-defined port number is wrong
	- Prioritizes USB port for data retrieval over Bluetooth
	- Exception handling: Attempt to continue monitoring with Bluetooth, if USB is disconnected
- Auto detect sound meter model and serial number
- Data Polling every second
	- Custom defined desired parameters to display (e.g.: L_Aeq, L_Ceq)
	- Record each parameter with both PC and Meter timestamps
- User defined monitoring duration or Indefinite duration until manual interruption
- Debugging for measuring response time & computing time of each poll
	- Typical response time: 0.11 sec
	- Typical computing time: 0.0004 sec
- Debug logging as a separate file
	- Current structure: everything is passed to the logger and the console display pulls data from it to display (More centralized logging, flexible and optimized)
	- both print() statements and logging statements will effectively behave in a similar manner; all print statements will be displayed and logged; and all log statements will also be displayed.
- Data logging output as a CSV file with versioning support, no overwrites
	- If data is unavailable, i.e. due to disconnect, an empty placeholder is written to ensure consistency
- User defined keypress for manual interruption
	- Designs for graceful exit of the program instead of force-stop
- Code auto clean up after interrupting or ending
	- Ensures resources are released, files are closed properly when the program exits.
- Proper Shutdown of Python.exe in Background Processes upon completion or user interruption
	- Except when run with debugger attached
- No data loss (both logs and CSV data) when the program is exited ungracefully - e.g. abrupt process termination, crashes, power outages
- Real time monitoring data is written to a SQLite database continuously
- Corresponding database filename is polled directly from device status HTTP page
- Error handling if database cannot be connected to, or if the connection is broken during monitoring
- Existing duplicate entry detection in the database and write rejection

# Defined Variables: YOU SHOULD CHECK THESE
- Interrupt_key: Set your desired interrupt key
- run_time: Set monitoring duration, 'None' for indefinite runtime
- usb_port and bluetooth_port: Set the current port if known, otherwise leave it as "None" for auto search
- output_directory: set output folder
	- one will be created if it does not exist
- output_filename: set data logging output file name
	- if already exists, will be saved with versioning
	- if none given, it will be defaulted as 'output.csv'
	- correctly handles empty filename such as '.csv'
- Database directory: set the directory for the SQLite database
	
# Wishlist:
- console shows nothing with logging redirect module enabled
- Reconnect with different port automatically / switch back to USB as soon as it is again available.
- Append date/"device_name" and "device_serial" retrieved from get_device_info as prefix to my output filename (currently the output file is created AFTER get_device_info is called and "device_name" and "device_serial" are retrieved)


# Known Issues:
- data-polled meter time is 1 second ahead of the LD Utility exported-data meter time
	- even when PC clock is synced to internet time, meter clock is synced with LD G4 Utility; both the PC and meter clocks are confirmed to be perfectly in sync on the display.
	- probably meter bug due to meter internal unix time conversion
- data-polled LAeq is 0.1 dB different from the exported csv LAeq, very rarely
	- probably error due to meter internal rounding

# Notes:
- Status page to see the values we need: http://127.0.0.1:{port_number}/sdk?func=getpagestatus
- If USB is connected, Bluetooth port no longer shows the readings, everything has to be read from the USB itself.
- USB is disconnected, everything can be read from Bluetooth.
- Bluetooth communications come with a noticeable delay in refresh/response rate, non-ideal performance

# How it works:
About find_LD_meter_ports() and the variables usb_port & bluetooth_port:
Cases:
1. the user defines "none" for the ports, the code checks these variables and sees that they are None. It then calls the find_LD_meter_ports() function. It finds the ports, returning them as global variables, continues as normal.
2. the user defines the wrong values for ports, the code checks and finds it inaccessible, calls the find_LD_meter_ports() function. It finds the correct ports, returning them as global variables, continues as normal.
3. the user defines the correct ports, the code checks and finds them valid, then skips running the find_LD_meter_ports() function.

Port handling logic: 
Cases:
1. usb port given correctly - print given port - find_LD_meter_ports() not run - print final usb port
2. usb port given wrongly - print given port - find_LD_meter_ports() not run - print final usb port
3. usb port not given - run find_LD_meter_ports() - usb port found - print final usb and/or bluetooth port
4. usb port not given - run find_LD_meter_ports() - usb port not found, but bluetooth port found - print final bluetooth port
5. usb port not given - run find_LD_meter_ports() - both ports not found - print warning message about privilege

Output_file handling logic:
Cases:
1. if output_filename already exists, a new one will be written to, with versioning
2. if no output_filename is given, it will be defaulted as 'output.csv'
3. if an empty string or '.csv' is given, goes to default 'output.csv'
4. if the file extension .csv is missing, it is appended
5. if the debug_log is locked and cannot be written, it is warned to the user & logging unavailable
6. if the output_file is locked, it means it exists, default to case #1