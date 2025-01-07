### Upload exported LD data CSV into database
### Benchmark: Upload to local SSD - 0.01s per row; Upload to WAL-NAS - 0.05-0.1s per row;

import sqlite3
import pandas as pd
import os
import sys
import time
from datetime import datetime

# Define model number and serial number
model_number = "821SE"
serial_number = "40126"

# Define the path to your CSV file & directory for the SQLite databases
csv_file_path = r"C:\Users\WAL01\Desktop\test_output\241223_time_history_ExportedData.csv"
database_directory = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase"

# Construct the database file name
database_name = f"{model_number}_{serial_number}_exported_csv_data.db"

# Define the path to your SQLite database
database_path = os.path.join(database_directory, database_name)

# Function to upload CSV data to the SQLite database
def upload_csv_to_database(csv_path, db_path):
    # Read the CSV file into a DataFrame
    df = pd.read_csv(csv_path)

    # Separate the 'Date/Time' into 'meter_date' and 'meter_time' columns using two spaces
    df[['meter_date', 'meter_time']] = df['Date/Time'].str.split('  ', expand=True)

    # Calculate unix_time from meter_date and meter_time
    df['unix_time'] = df.apply(lambda row: int(datetime.strptime(f"{row['meter_date']} {row['meter_time']}", '%Y-%m-%d %H:%M:%S').timestamp()), axis=1)

    # Drop the original 'Date/Time' column
    df.drop(columns=['Date/Time'], inplace=True)

    # Rename columns to match the database format
    df.columns = df.columns.str.replace('1/3 LAeq ', 'one_third_octave_LAeq_').str.replace('.', '_')

    # Reorder columns to place 'unix_time' first
    cols = ['unix_time'] + [col for col in df.columns if col != 'unix_time']
    df = df[cols]

    # Connect to the SQLite database
    conn = sqlite3.connect(db_path)

    # Create a cursor object
    cursor = conn.cursor()

    # Insert data into the ExportedData table with feedback
    for index, row in df.iterrows():
        start_time = time.perf_counter()  # Start timing the insertion

        # Check if the primary key already exists
        meter_date = row['meter_date']
        meter_time = row['meter_time']
        unix_time = row['unix_time']
        cursor.execute("SELECT COUNT(*) FROM ExportedData WHERE unix_time = ?", (unix_time,))
        exists = cursor.fetchone()[0]

        if exists:
            elapsed_time = time.perf_counter() - start_time
            print(f"Entry with unix_time={unix_time}, meter_date={meter_date} and meter_time={meter_time} already exists. Skipping row {index}. Time taken: {elapsed_time:.3f} seconds.")
        else:
            row.to_frame().T.to_sql('ExportedData', conn, if_exists='append', index=False)
            end_time = time.perf_counter()  # End timing after insertion
            elapsed_time = end_time - start_time  # Calculate elapsed time

            # Print the appended message with elapsed time
            print(f"Appended row {index}: unix_time={unix_time}, meter_date={meter_date}, meter_time={meter_time}, data={row.to_dict()}. Insertion Time: {elapsed_time:.3f} seconds.")

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