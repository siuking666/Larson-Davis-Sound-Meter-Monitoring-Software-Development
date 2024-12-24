### Upload exported LD data CSV into database

import sqlite3
import pandas as pd
import os
import sys

# Define model number and serial number
model_number = "821SE"
serial_number = "40126"

# Define the directory for the SQLite databases
database_directory = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase"

# Construct the database file name
database_name = f"{model_number}_{serial_number}_exported_csv_data.db"

# Define the path to your SQLite database
database_path = os.path.join(database_directory, database_name)

# Define the path to your CSV file
csv_file_path = r"C:\Users\WAL01\Desktop\test_output\241120_time_history.csv"

# Function to upload CSV data to the SQLite database
def upload_csv_to_database(csv_path, db_path):
    # Read the CSV file into a DataFrame
    df = pd.read_csv(csv_path)

    # Separate the 'Date/Time' into 'meter_date' and 'meter_time' columns using two spaces
    df[['meter_date', 'meter_time']] = df['Date/Time'].str.split('  ', expand=True)

    # Drop the original 'Date/Time' column
    df.drop(columns=['Date/Time'], inplace=True)

    # Rename columns to match the database format
    df.columns = df.columns.str.replace('1/3 LAeq ', 'one_third_octave_LAeq_').str.replace('.', '_')

    # Connect to the SQLite database
    conn = sqlite3.connect(db_path)

    # Create a cursor object
    cursor = conn.cursor()

    # Insert data into the ExportedData table with feedback
    for index, row in df.iterrows():
        # Check if the primary key already exists
        meter_date = row['meter_date']
        meter_time = row['meter_time']
        cursor.execute("SELECT COUNT(*) FROM ExportedData WHERE meter_date = ? AND meter_time = ?", (meter_date, meter_time))
        exists = cursor.fetchone()[0]

        if exists:
            print(f"Entry with meter_date={meter_date} and meter_time={meter_time} already exists. Skipping row {index}.")
        else:
            row.to_frame().T.to_sql('ExportedData', conn, if_exists='append', index=False)
            print(f"Appended row {index}: meter_date={meter_date}, meter_time={meter_time}, data={row.to_dict()}")

    # Commit the transaction and close the connection
    conn.commit()
    conn.close()
    print(f"All data from {csv_path} uploaded to {db_path} successfully.")

# Call the function to upload the CSV
try:
    upload_csv_to_database(csv_file_path, database_path)
except Exception as e:
    print(f"An error occurred: {e}")
finally:
    sys.exit()