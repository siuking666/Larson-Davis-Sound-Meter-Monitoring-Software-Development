### Create two SQLite Databases per sound meter
### Sound meters should be listed in a text file

import sqlite3
import os

# Define the directory for the SQLite databases
database_directory = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase"

# Define the directory of the text file with sound meters
meters_file_path = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase\sound_meters.txt"

# Function to create a database and its tables for live data
def create_database_live_monitoring(path):
    conn = sqlite3.connect(path)  # Connect to the SQLite database
    cursor = conn.cursor()

    # Create a table with the desired structure
    # Table name: LiveMonitoring
    # the name is NOT case sensitive unless double quoted
    # Columns: pc_date, pc_time, meter_date, meter_time, LAeq, response_time
    # primary key (unique identifier) = combination of meter date & time; duplicate write will be rejected
    cursor.execute("SELECT name FROM sqlite_master WHERE type='table' AND name='LiveMonitoring';")
    if cursor.fetchone() is None:  # Table does not exist
        cursor.execute('''
            CREATE TABLE LiveMonitoring (
                pc_date TEXT,
                pc_time TEXT,
                unix_time INTEGER PRIMARY KEY,
                meter_date TEXT NOT NULL,
                meter_time TEXT NOT NULL,
                LAeq REAL NOT NULL,
                response_time REAL NOT NULL
            )
        ''')
        print(f"Live monitoring database created at: {path}")
    else:
        print(f"Live monitoring database already exists at: {path}")
    
    conn.commit()  # Commit changes
    conn.close()  # Close the connection

# Function to create a database and its tables for exported data
def create_database_exported_data(path):
    conn = sqlite3.connect(path)  # Connect to the SQLite database
    cursor = conn.cursor()
    
    # Check if the table already exists
    cursor.execute("SELECT name FROM sqlite_master WHERE type='table' AND name='ExportedData';")
    if cursor.fetchone() is None:  # Table does not exist
        cursor.execute('''
            CREATE TABLE ExportedData (
                unix_time INTEGER PRIMARY KEY,
                meter_date TEXT NOT NULL,
                meter_time TEXT NOT NULL,
                LAeq REAL,
                one_third_octave_LAeq_6_3 REAL,
                one_third_octave_LAeq_8_0 REAL,
                one_third_octave_LAeq_10_0 REAL,
                one_third_octave_LAeq_12_5 REAL,
                one_third_octave_LAeq_16_0 REAL,
                one_third_octave_LAeq_20_0 REAL,
                one_third_octave_LAeq_25_0 REAL,
                one_third_octave_LAeq_31_5 REAL,
                one_third_octave_LAeq_40_0 REAL,
                one_third_octave_LAeq_50_0 REAL,
                one_third_octave_LAeq_63_0 REAL,
                one_third_octave_LAeq_80_0 REAL,
                one_third_octave_LAeq_100 REAL,
                one_third_octave_LAeq_125 REAL,
                one_third_octave_LAeq_160 REAL,
                one_third_octave_LAeq_200 REAL,
                one_third_octave_LAeq_250 REAL,
                one_third_octave_LAeq_315 REAL,
                one_third_octave_LAeq_400 REAL,
                one_third_octave_LAeq_500 REAL,
                one_third_octave_LAeq_630 REAL,
                one_third_octave_LAeq_800 REAL,
                one_third_octave_LAeq_1000 REAL,
                one_third_octave_LAeq_1250 REAL,
                one_third_octave_LAeq_1600 REAL,
                one_third_octave_LAeq_2000 REAL,
                one_third_octave_LAeq_2500 REAL,
                one_third_octave_LAeq_3150 REAL,
                one_third_octave_LAeq_4000 REAL,
                one_third_octave_LAeq_5000 REAL,
                one_third_octave_LAeq_6300 REAL,
                one_third_octave_LAeq_8000 REAL,
                one_third_octave_LAeq_10000 REAL,
                one_third_octave_LAeq_12500 REAL,
                one_third_octave_LAeq_16000 REAL,
                one_third_octave_LAeq_20000 REAL
            )
        ''')
        print(f"Exported data database created at: {path}")
    else:
        print(f"Exported data database already exists at: {path}")
    
    conn.commit()  # Commit changes
    conn.close()  # Close the connection


# Function to read sound meters from a text file and create databases
def create_databases_from_file(file_path):
    with open(file_path, 'r') as file:
        for line in file:
            # Strip whitespace and check for space or tab
            line = line.strip()
            if not line:
                continue

            if ' ' in line:
                model_number, serial_number = line.split(' ', 1)
            else:
                model_number, serial_number = line.split('\t', 1)
                
            # Create database names
            live_monitoring_db = os.path.join(database_directory, f"{model_number}_{serial_number}_live-monitoring.db")
            exported_data_db = os.path.join(database_directory, f"{model_number}_{serial_number}_exported_csv_data.db")
            
            # Create both databases
            create_database_live_monitoring(live_monitoring_db)
            create_database_exported_data(exported_data_db)


# Create databases from the provided text file
create_databases_from_file(meters_file_path)