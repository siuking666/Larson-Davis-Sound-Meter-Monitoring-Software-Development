Larson Davis Sound Meter Real-Time Monitoring Software Documentation v1
2/12/2024 by Ken Cheung
Important: RUN AS ADMINISTRATOR or the software may fail to read the USB and Bluetooth ports used by the sound meter.
Pre-requisites:
-	G4 LD Utility installed
-	Administrator rights
-	Python & any IDE installed (for uncompiled code)
-	
Current Features:
-	Auto detect & display dynamic port numbers = plug-and-play
-	Custom defined desired parameters to display (e.g.: L_Aeq, L_Ceq)
-	Custom defined keypress for manual interruption
-	Display with timestamps
-	Output desired parameters every second
-	Custom defined monitoring duration
-	Or Indefinite noise monitoring until manual interruption
-	Bluetooth acts as a backup connection to keep it running (with a noticeable delay in refresh/response rate, non-ideal performance)
-	Exception handling if connection is broken during monitoring, the program will continue to run and attempt to reconnect (to the same port) every second
-	Attempt to fall back and reconnect with Bluetooth, to continue monitoring if device is disconnected
-	GitHub Version Control
-	
Wishlist:
-	User defined port number as a backup measure
-	Reconnect with different port automatically / switch back to USB as soon as it is again available.
-	Backend logging as csv
-	
Notes:
-	Status page to see the values we need: http://127.0.0.1:2567/sdk?func=getpagestatus
-	If USB is connected, Bluetooth port no longer shows the readings, everything has to be read from the USB itself.
-	USB is disconnected, everything can be read from Bluetooth.

