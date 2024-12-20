### Create two SQLite Databases per sound meter
### Sound meters should be listed in a text file

import sqlite3
import os

# Define the directory for the SQLite databases
database_directory = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase"

# Define the directory of the text file with sound meters
meters_file_path = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase\sound_meters.txt"

# Function to create a database and its tables
def create_database_live_data(path):
    conn = sqlite3.connect(path)  # Connect to the SQLite database
    print(f"Database created at: {path}")

    # Create a table with the desired structure
    # Table name: Measurements
    # the name is NOT case sensitive unless double quoted
    # Columns: pc_date, pc_time, meter_date, meter_time, LAeq, response_time
    # primary key (unique identifier) = combination of meter date & time; duplicate write will be rejected
    cursor = conn.cursor()
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS Measurements (
            pc_date TEXT,
            pc_time TEXT,
            meter_date TEXT NOT NULL,
            meter_time TEXT NOT NULL,
            LAeq REAL NOT NULL,
            response_time REAL NOT NULL,
            PRIMARY KEY (meter_date, meter_time)  -- Composite primary key
        )
    ''')
    
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
            exported_data_db = os.path.join(database_directory, f"{model_number}_{serial_number}_exported_data.db")
            
            # Create both databases
            create_database_live_data(live_monitoring_db)
            # create_database_exported_data(exported_data_db)


# Create databases from the provided text file
create_databases_from_file(meters_file_path)