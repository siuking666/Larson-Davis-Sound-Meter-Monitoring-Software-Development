# Export SQLite Database to CSV Code Documentation
# 27/12/2024 by Ken Cheung

The code is designed to handle the export of two specific SQLite databases associated with sound meters:
- Live monitoring database
- Processed data database

## Pre-requisites
- Python 3.11.9
- The following packages installed in the Python Environment:
  - `sqlite3`
  - `pandas`
- SQLite databases exist in the specified directory, and named according to defined format from the database creation program
- Appropriate directory access permissions for reading from the SQLite databases and writing to the output directory.

## Current Features
- Connects to specified SQLite databases using model and serial numbers.
- Reads data from the specified tables in the databases:
  - Live monitoring data from the `LiveMeasurements` table.
  - Exported data from the `ExportedData` table.
- Exports the retrieved data into CSV format with appropriate error handling.
- Provides feedback on successful export or error messages.

## User Defined Variables: YOU NEED TO CHECK THESE FOR THE CODE TO RUN
- model_number: Model number of the sound meter that exported the data
- serial_number: Serial number of the sound meter that exported the data
- database_directory: Path where the SQLite databases are stored
- output_directory: Path where the exported CSV files will be saved

