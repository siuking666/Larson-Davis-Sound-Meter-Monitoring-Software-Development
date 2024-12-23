### Upload exported LD data CSV into database

import sqlite3
import pandas as pd
import os

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

    # Separate the 'Date/Time' into 'Date' and 'Time' columns using two spaces
    df[['meter_date', 'meter_time']] = df['Date/Time'].str.split('  ', expand=True)

    # Drop the original 'Date/Time' column
    df.drop(columns=['Date/Time'], inplace=True)

    # Rename columns to match the database format
    df.columns = df.columns.str.replace('1/3 LAeq ', 'one_third_octave_LAeq_').str.replace('.', '_')

    # Connect to the SQLite database
    conn = sqlite3.connect(db_path)

    # Insert data into the ExportedData table with feedback
    for index, row in df.iterrows():
        row.to_frame().T.to_sql('ExportedData', conn, if_exists='append', index=False)
        print(f"Appended row {index}: meter_date={row['meter_date']}, meter_time={row['meter_time']}, data={row.to_dict()}")

    # Commit and close the connection
    conn.commit()
    conn.close()
    print(f"All data from {csv_path} uploaded to {db_path} successfully.")

# Call the function to upload the CSV
upload_csv_to_database(csv_file_path, database_path)