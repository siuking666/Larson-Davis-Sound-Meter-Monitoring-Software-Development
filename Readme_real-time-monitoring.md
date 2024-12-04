# Larson Davis Sound Meter Real-Time Monitoring Software Documentation
# 3/12/2024 by Ken Cheung

**Important: RUN AS ADMINISTRATOR or the software may fail to read the USB and Bluetooth ports used by the sound meter.**

# Pre-requisites:
-	G4 LD Utility installed
-	Administrator rights / Run as Administrator
-	Python & any IDE (e.g. Jupyter / Visual Studio) installed (for uncompiled code)
-	Optional: Larson Davis Official SDK

# Current Features:
-	GitHub Version Control (along with this documentation)
-	Auto detect & display dynamic port numbers = plug-and-play
-	User can define known port numbers to speed up the process
-	Auto detect the correct port number if user-defined port number is wrong
-	Auto detect sound meter model and serial number
-	Prioritizes USB port for data retrieval over Bluetooth
-	Poll data every second
-	Custom defined desired parameters to display (e.g.: L_Aeq, L_Ceq)
-	Record each parameter with both PC and Meter timestamps
-	Custom defined keypress for manual interruption
-	Custom defined monitoring duration or Indefinite until manual interruption
-	Exception handling: Attempt to continue monitoring with Bluetooth, if USB is disconnected
-	Added debugging for measuring response time & computing time of each poll
	- Typical response time: 0.11 sec
	- Typical computing time: 0.0004 sec


# Defined Variables: YOU SHOULD CHECK THESE
-	Interrupt_key: Set your desired interrupt key
-	run_time: Set monitoring duration, 'None' for indefinite runtime
-	usb_port and bluetooth_port: Set the current port if known, otherwise leave it as "None" for auto search

# output_directory_path = r"C:\Users\remote\Desktop\241120 Max's Larson Davis Data Extraction Programming\Test Output" # set output folder
# base_output_file = "time_history" # name of output file will have date as prefix and version number as suffix
# output_file_extension = ".csv" # Currently ONLY support .csv
	
# Wishlist:
-	Reconnect with different port automatically / switch back to USB as soon as it is again available.
-	Backend logging as csv

# Notes:
-	Status page to see the values we need: http://127.0.0.1:2567/sdk?func=getpagestatus
-	If USB is connected, Bluetooth port no longer shows the readings, everything has to be read from the USB itself.
-	USB is disconnected, everything can be read from Bluetooth.
-	Bluetooth communications come with a noticeable delay in refresh/response rate, non-ideal performance
