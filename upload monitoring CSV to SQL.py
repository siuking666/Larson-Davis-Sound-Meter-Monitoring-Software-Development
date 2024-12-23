### Upload live monitoring output CSV into database
### For testing purpose; since normally we will not use live monitoring data logs

import sqlite3
import pandas as pd

# Define the paths
csv_path = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\Test Data Sets - Monitoring\20241206 Over Weekend Monitoring\test_weekend_6 dec.csv"
db_path = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase\821SE_40126_live-monitoring.db"

try:
    # Connect to the SQLite database
    conn = sqlite3.connect(db_path)

    # Read the CSV file, skipping the first two rows
    data = pd.read_csv(csv_path, skiprows=2, header=None)

    # Rename columns according to your database structure, adding a placeholder for response_time
    data.columns = ['pc_date', 'pc_time', 'meter_date', 'meter_time', 'LAeq']
    
    # Add a column for response_time with a default value (0.0)
    data['response_time'] = 0.0

    # Insert data into the Measurements table
    data.to_sql('LiveMeasurements', conn, if_exists='append', index=False)

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
    if conn:
        conn.close()