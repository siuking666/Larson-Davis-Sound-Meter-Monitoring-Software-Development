# SQLite Databases Creation Code Documentation
# 23/12/2024 by Ken Cheung

The code creates two SQLite Databases per sound meter,
The sound meters should be listed in a text file in the format: {model_number} {serial_number}
- one for storing live monitoring data, 
- one for storing CSV data exported from the meter

# Pre-requisites:
- Python 3.11.9
- All imported packages installed in the Python Environment
- For uncompiled code: any IDE (e.g. Jupyter / Visual Studio) installed

# Current Features:
- Can handle a space or tab-space and empty lines in the sound meter listing text file
- Create a database if it does not exist
- Existing database of the same name will not be overwritten, a feedback message will be printed
- For the live monitoring data database, the table is structured as follows:
    - Table name: LiveMeasurements; the name is NOT case sensitive unless double quoted
    - Columns: pc_date, pc_time, meter_date, meter_time, LAeq, response_time
    - primary key / unique identifier = combination of meter date & time
- For the exported data database, the table is structured as follows:
    - Table name: ExportedData; the name is NOT case sensitive unless double quoted
    - Columns: meter_date, meter_time, LAeq, the rest of the "one_third_octave_LAeq_{number}"
    - primary key / unique identifier = combination of meter date & time
- An entry with a duplicate/existing primary key will be rejected by the database

# Defined Variables:
- Define the directory for the SQLite databases
- Define the directory of the text file with sound meters


