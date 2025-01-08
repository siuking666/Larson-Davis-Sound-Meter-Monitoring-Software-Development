### SQLite Database Stress Test
# Write to and Query data from the database 20 times a second
# Benchmark: 0.05s per write operation (time between connection opens and closes)
# Benchmark: 0.1s between write operation (reconnect time)

import sqlite3
import time
import threading
from datetime import datetime
import pandas as pd
import sys
import os

# Path to the SQLite database
db_path = r'\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase\821SE_40126_live-monitoring.db'
csv_export_path = r'\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase\live_data_export.csv'
run_time = 21  # Test duration in seconds
op_per_sec = 1  # Number of operations per second
loop_amount = 1  # Number of times to call insert_data and read_data per second

#------------------------------------------------------------------------------------------

# Function to insert live data
def insert_data(path):
    # conn = sqlite3.connect(path)
    # cursor = conn.cursor()

    # Insert values into the LiveMonitoring table
    for LAeq in range(1, op_per_sec+1):  # Example LAeq values from 1 to 20
        conn = sqlite3.connect(path)

        now = datetime.now()
        print(f"{now} Write: Opened connection.")

        cursor = conn.cursor()
        now = datetime.now()
        pc_date = now.strftime('%Y-%m-%d')
        pc_time = now.strftime('%H:%M:%S.%f')[:-3]  # Format to include milliseconds
        unix_time = int(now.timestamp())  # Get the current Unix timestamp
        meter_date = pc_date  # Use the same date
        meter_time = pc_time   # Use the same time
        response_time = LAeq * 2  # Dummy response time
        
        try:
            cursor.execute('''
                INSERT INTO LiveMonitoring (pc_date, pc_time, unix_time, meter_date, meter_time, LAeq, response_time)
                VALUES (?, ?, ?, ?, ?, ?, ?)
            ''', (pc_date, pc_time, unix_time, meter_date, meter_time, LAeq, response_time))
            # Print the inserted entry as feedback
            print(f"Inserted: (pc_date: {pc_date}, pc_time: {pc_time}, unix_time: {unix_time}, meter_date: {meter_date}, "
                  f"meter_time: {meter_time}, LAeq: {LAeq}, response_time: {response_time})")
        except sqlite3.IntegrityError:
            print(f"Duplicate entry for meter_date: {meter_date}, meter_time: {meter_time}")
        time.sleep(0.001)

        conn.commit()
        conn.close()
        now = datetime.now()
        print(f"{now} Write: Closed Connection.")
    # conn.commit()  # Commit the insertions
    # conn.close()

# Function to read data from the database
def read_data(path):
    conn = sqlite3.connect(path)
    cursor = conn.cursor()
    
    now = datetime.now()
    print(f"{now} Read: Opened connection.")
    
    try:
        cursor.execute("SELECT * FROM LiveMonitoring")
        rows = cursor.fetchall()
        for row in rows:
            print(row)  # Print each row
    except sqlite3.Error as e:
        print(f"An error occurred while reading data: {e}")
    finally:
        conn.close()
        now = datetime.now()
        print(f"{now} Read: Closed connection.")

# Function to export the SQLite database to a CSV file
def export_database_to_csv(db_path, csv_path, table_name):
    try:
        # Connect to the SQLite database
        conn = sqlite3.connect(db_path)

        # Read the data from the specified table into a DataFrame
        df = pd.read_sql_query(f"SELECT * FROM {table_name}", conn)

        # Export the DataFrame to a CSV file
        df.to_csv(csv_path, index=False)
        print(f"Data exported from table '{table_name}' to {csv_path} successfully.")

    except sqlite3.Error as e:
        print(f"An error occurred while accessing the database '{db_path}': {e}")
    except Exception as e:
        print(f"An error occurred while exporting data: {e}")
    finally:
        # Close the connection
        if conn:
            conn.close()

# Main block to manage timing and function calls
if __name__ == "__main__":
    # Connect to the database and empties the table before starting the test
    conn = sqlite3.connect(db_path)
    cursor = conn.cursor()
    cursor.execute("DELETE FROM LiveMonitoring")
    conn.commit()
    conn.close()

    # Record start time, set up end time and make sure that the loop starts exactly 1 second after
    start_time = time.time()
    end_time = start_time + run_time  # Calculate the end time from run_time
    next_loop_time = start_time + 1  # Set the first loop time to the next whole second

    while time.time() < end_time:
        current_time = time.time()
        if current_time >= next_loop_time:
            # Call the insertion and reading functions multiple times
            for _ in range(loop_amount):
                insert_data(db_path)
                read_data(db_path)
            # Update the next loop time to the next whole second
            next_loop_time += 1

    # Export the database to a CSV file after the test
    export_database_to_csv(db_path, csv_export_path, 'LiveMonitoring')
    sys.exit(0)