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
-	Custom defined desired parameters to display (e.g.: L_Aeq, L_Ceq)
-	Record each parameter with both PC and Meter timestamps
-	Custom defined keypress for manual interruption
-	Poll data every second
-	Custom defined monitoring duration or Indefinite until manual interruption
-	Exception handling: Attempt to continue monitoring with Bluetooth, if USB is disconnected (with a noticeable delay in refresh/response rate, non-ideal performance)


# Defined Variables: YOU SHOULD CHECK THESE
-	Interrupt_key: Set your desired interrupt key
-	run_time: Set monitoring duration, 'None' for indefinite runtime
-
-	Model number: model number of your sound meter that exported the data, e.g. 821SE
-	Serial number: serial number of your sound meter that exported the data, e.g. 40126
-	Specific file name: ONLY if you want to process ONE specific file, otherwise leave it as ¡§None¡¨
-	Columns to skip: specify which columns you want to discard from the data
	
# Wishlist:
-	User defined port number as a backup measure
-	Reconnect with different port automatically / switch back to USB as soon as it is again available.
-	Backend logging as csv


# Notes:
-	Status page to see the values we need: http://127.0.0.1:2567/sdk?func=getpagestatus
-	If USB is connected, Bluetooth port no longer shows the readings, everything has to be read from the USB itself.
-	USB is disconnected, everything can be read from Bluetooth.

