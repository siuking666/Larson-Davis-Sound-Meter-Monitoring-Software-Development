### (TEMPORARY) Upload live monitoring output CSV into database
### For testing purpose; since normally we will not use live monitoring data logs
### Benchmark: Upload to local SSD - 0.01s per row; Upload to WAL-NAS - 0.05-0.1s per row;

import sqlite3
import pandas as pd
import os
import sys
import time

# Define model number and serial number
model_number = "821SE"
serial_number = "40126"

# Define the paths
csv_path = r"C:\Users\WAL01\Desktop\test_output\monitoring_test_6 dec_700 entries.csv"
db_directory = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase"

# Construct the path to your SQLite database
db_name = f"{model_number}_{serial_number}_live-monitoring.db"
db_path = os.path.join(db_directory, db_name)

try:
    # Connect to the SQLite database
    conn = sqlite3.connect(db_path)
    cursor = conn.cursor()

    # Read the CSV file, skipping the first two rows
    data = pd.read_csv(csv_path, skiprows=2, header=None)

    # Rename columns according to your database structure, adding a placeholder for response_time
    data.columns = ['pc_date', 'pc_time', 'unix_time', 'meter_date', 'meter_time', 'LAeq']
    
    # Add a column for response_time with a default value (0.0)
    data['response_time'] = 0.0

    # Insert data into the Measurements table with feedback
    for index, row in data.iterrows():
        start_time = time.perf_counter()  # Start timing

        unix_time = row['unix_time']
        pc_date = row['pc_date']
        pc_time = row['pc_time']
        meter_date = row['meter_date']
        meter_time = row['meter_time']
    
        # Check if the entry already exists based on unix_time
        cursor.execute("SELECT COUNT(*) FROM LiveMonitoring WHERE unix_time = ?", (unix_time,))
        exists = cursor.fetchone()[0]

        if exists:
            elapsed_time = time.perf_counter() - start_time
            print(f"Entry with unix_time={unix_time} already exists. Skipping row {index}. Time taken: {elapsed_time:.3f} seconds.")

        else:
            # Insert row into the LiveMonitoring table
            row[['pc_date', 'pc_time', 'unix_time', 'meter_date', 'meter_time', 'LAeq', 'response_time']].to_frame().T.to_sql('LiveMonitoring', conn, if_exists='append', index=False)

            end_time = time.perf_counter()  # End timing after insertion
            elapsed_time = end_time - start_time  # Calculate elapsed time
        
            # Print the appended message with elapsed time
            print(f"Appended row {index}: PC Date={pc_date}, PC Time={pc_time}, Unix Time={unix_time}, Meter Date={meter_date}, Meter Time={meter_time}, LAeq={row['LAeq']}. Time taken: {elapsed_time:.3f} seconds.")

    # Commit changes
    conn.commit()
    print("Data imported successfully!")

except FileNotFoundError:
    print(f"Error: The file {csv_path} was not found.")
except pd.errors.EmptyDataError:
    print("Error: The CSV file is empty.")
except sqlite3.Error as e:
    print(f"SQLite error: {e}")
except Exception as e:
    print(f"An unexpected error occurred: {e}")
finally:
    # Ensure the connection is closed
    if 'conn' in locals() and conn:
        conn.close()
    # Exit the program
    sys.exit()