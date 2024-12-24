### (TEMPORARY) Upload live monitoring output CSV into database
### For testing purpose; since normally we will not use live monitoring data logs

import sqlite3
import pandas as pd

# Define the paths
csv_path = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\Test Data Sets - Monitoring\20241206 Over Weekend Monitoring\test_weekend_6 dec.csv"
db_path = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase\821SE_40126_live-monitoring.db"

try:
    # Connect to the SQLite database
    conn = sqlite3.connect(db_path)
    cursor = conn.cursor()

    # Read the CSV file, skipping the first two rows
    data = pd.read_csv(csv_path, skiprows=2, header=None)

    # Rename columns according to your database structure, adding a placeholder for response_time
    data.columns = ['pc_date', 'pc_time', 'meter_date', 'meter_time', 'LAeq']
    
    # Add a column for response_time with a default value (0.0)
    data['response_time'] = 0.0

    # Insert data into the Measurements table with feedback
    for index, row in data.iterrows():
        meter_date = row['meter_date']
        meter_time = row['meter_time']
        
        # Check if the entry already exists based on meter_date and meter_time
        cursor.execute("SELECT COUNT(*) FROM LiveMeasurements WHERE meter_date = ? AND meter_time = ?", (meter_date, meter_time))
        exists = cursor.fetchone()[0]

        if exists:
            print(f"Entry with meter_date={meter_date} and meter_time={meter_time} already exists. Skipping row {index}.")
        else:
            row.to_frame().T.to_sql('LiveMeasurements', conn, if_exists='append', index=False)
            print(f"Appended row {index}: meter_date={meter_date}, meter_time={meter_time}, LAeq={row['LAeq']}")

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