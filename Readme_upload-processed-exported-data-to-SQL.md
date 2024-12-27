# Upload Exported LD Data CSV into Database
# 27/12/2024 by Ken Cheung

This code uploads the processed CSV data exported from G4 Utility, into a SQLite database.

## Pre-requisites
- Python 3.11.9
- All imported packages installed in the Python environment (e.g., `sqlite3`, `pandas`).
- CSV Files processed with my other program: `exported data processing.py`
- SQLite database created with my other program: `create SQLite database.py`

## Current Features
- Reads data from a specified CSV file containing sound meter data.
- Uploads the data into an SQLite database while ensuring no duplicate entries are inserted.
- Data column headers are matched
- Provides feedback on the time taken for each row's insertion.
- Handles potential exceptions during the upload process.

## Performance Benchmark
- Upload to Local SSD: Approximately 0.01 seconds per row.
- Upload to WAL-NAS: Approximately 0.05 to 0.1 seconds per row.

## User Defined Variables: YOU NEED TO CHECK THESE FOR THE CODE TO RUN
- model_number: Model number of the sound meter that exported the data
- serial_number: Serial number of the sound meter that exported the data
- csv_file_path: Path to the CSV file to be uploaded
- database_directory: Path where the SQLite databases are stored