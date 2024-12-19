# Larson Davis Exported Data Processing Python Code Documentation
# 19/12/2024 by Ken Cheung

# Pre-requisites:
-	Python 3.11.9
-	All imported packages installed in the Python Environment
-	G4 LD Utility 5.1.2 installed
-	For uncompiled code: any IDE (e.g. Jupyter / Visual Studio) installed
-	In G4 LD Utility - G4 Options - File Options:
	- Export on Download: "CSV" enabled
	- "Create CSV export folders for each worksheet": enabled
-	Keep filename structure default, i.e. ¡§{model_number} {serial_number}-{date}{index}-{time}.csv¡¨
-	Keep exported .csv file content unchanged

# Current Features:
-	GitHub Version Control (along with this documentation)
-	Define different input directory and output directory separately
-	Name the output file name and extension at will
-	Matches given model and serial number with input data, and only processes matching files 
-	Support processing only 1 specific file
-	Support batch processing entire folder
-	Custom define data columns to discard
-	One output file is created for each date detected
-	Output file has automatic versioning support, if output file of the same name already exists, i.e. from running the code more than once, no overwrites, no conflicts
-	Processed files are copied to sub-folders of each date in output folder, for better organization
-	Specific error messages for troubleshooting
-	Proper Shutdown of Python.exe in Background Processes upon completion, releasing all resources;
	- Except when run with debugger attached

# Defined Variables: YOU NEED TO CHECK THESE FOR THE CODE TO RUN
*Assume the default filename structure: ¡§{model_number} {serial_number}-{date}{index}-{time}.csv¡¨*

-	Input directory: folder where all your files for processing are
-	Output directory: folder where all your processed files go; if not found, one will be created
-	Output file name: will have date as prefix and version number as suffix
-	Output file extension: currently only .csv supported; .xlsx may work¡Kor not
-	Model number: model number of your sound meter that exported the data, e.g. 821SE
-	Serial number: serial number of your sound meter that exported the data, e.g. 40126
-	Specific file name: ONLY if you want to process ONE specific file, otherwise leave it as ¡§None¡¨
-	Columns to skip: specify which columns you want to discard from the data

# Wishlist:
-	Support for SQL auto-upload to database
-	A GUI for frontend
-	Optional:
	- Able to process excel format .xlsx output the same way
	- If ¡§irrelevant¡¨ files, or files without dates/with wrong format in their names are present in the input folder, still process them and throw them into ¡§uncategorized¡¨ output folder?

# Known issue/concern:
-	It does not verify the CSV data structure. If a CSV contains a different data structure, i.e. missing columns, it will be processed and appended to the output as-is.


# Backend operation / How it works:
-	The code starts by checking if input directory exists; if not the program stops.
-	It also checks if the output directory exists, if not, one is created
-	
