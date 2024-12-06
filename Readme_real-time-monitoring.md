# Larson Davis Sound Meter Real-Time Monitoring Software Documentation
# 6/12/2024 by Ken Cheung

**Important: RUN AS ADMINISTRATOR or the software may fail to read the USB and Bluetooth ports used by the sound meter.**

# Pre-requisites:
-	G4 LD Utility installed
-	Administrator rights / Run as Administrator
-	Python & any IDE (e.g. Jupyter / Visual Studio) installed (for uncompiled code)
-	Optional: Larson Davis Official SDK
-	For safety, close debug and output files before using this software, and do not open them during monitoring to prevent data loss

# Current Features:
-	GitHub Version Control (along with this documentation)
-	Auto detect & display dynamic port numbers = plug-and-play
	- User can define known port numbers to speed up the process
	- Auto detect the correct port number if user-defined port number is wrong
	- Prioritizes USB port for data retrieval over Bluetooth
	- Exception handling: Attempt to continue monitoring with Bluetooth, if USB is disconnected
-	Auto detect sound meter model and serial number
-	Data Polling every second
	- Custom defined desired parameters to display (e.g.: L_Aeq, L_Ceq)
	- Record each parameter with both PC and Meter timestamps
-	User defined monitoring duration or Indefinite duration until manual interruption
-	Debugging for measuring response time & computing time of each poll
	- Typical response time: 0.11 sec
	- Typical computing time: 0.0004 sec
-	Debug logging as a separate file
-	Data logging output as a CSV file with versioning support, no overwrites
-	User defined keypress for manual interruption
	- Designs for graceful exit of the program instead of force-stop
-	Code auto clean up after interrupting or ending
	- Ensures resources are released, files are closed properly when the program exits.

# Defined Variables: YOU SHOULD CHECK THESE
-	Interrupt_key: Set your desired interrupt key
-	run_time: Set monitoring duration, 'None' for indefinite runtime
-	usb_port and bluetooth_port: Set the current port if known, otherwise leave it as "None" for auto search
-   output_directory: set output folder
	- one will be created if it does not exist
-   output_filename: set data logging output file name
	- if already exists, will be saved with versioning
	- if none given, it will be defaulted as 'output.csv'
	- correctly handles empty filename such as '.csv'
	
# Wishlist:
-	Reconnect with different port automatically / switch back to USB as soon as it is again available.
-	Backend logging as csv
-   what happens if the file is opened during monitorig, can it still be continuously written to? or read only?

# Notes:
-	Status page to see the values we need: http://127.0.0.1:2567/sdk?func=getpagestatus
-	If USB is connected, Bluetooth port no longer shows the readings, everything has to be read from the USB itself.
-	USB is disconnected, everything can be read from Bluetooth.
-	Bluetooth communications come with a noticeable delay in refresh/response rate, non-ideal performance


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