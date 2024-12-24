### Upload live monitoring VALUES into database
### INTEGRATE THIS INTO THE MAIN MONITORING CODE FOR LIVE MONITORING
# 1. Database Connection and Insertion: 
# You need to connect to the SQLite database and insert the monitoring data after a successful poll.
# 2. Data Insertion Function:
# Create a function to handle data insertion into the database.

import sqlite3
import os
import requests
import time
import threading
import sys
from datetime import datetime


# Create database names
database_directory = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase"
port = 1234  # Replace with your actual port number

# Function to connect to the SQLite database
def connect_to_database(db_path):
    return sqlite3.connect(db_path)

# for the future, if we switch to online/server MySQL or PostgreSQL
# Only need to modify the connection function/logics

# # for MySQL
# import mysql.connector

# def connect_to_mysql(db_name, user, password, host, port):
#     conn = mysql.connector.connect(
#         database=db_name,
#         user=user,
#         password=password,
#         host=host,
#         port=port
#     )
#     return conn

# # fo Postgre SQL
# import psycopg2

# def connect_to_postgresql(db_name, user, password, host, port):
#     conn = psycopg2.connect(
#         dbname=db_name,
#         user=user,
#         password=password,
#         host=host,
#         port=port
#     )
#     return conn

# Function to insert monitoring data into the database
def insert_measurement_data(conn, pc_date, pc_time, meter_date, meter_time, LAeq, response_time):
    cursor = conn.cursor()
    try:
        cursor.execute('''
            INSERT INTO Measurements (pc_date, pc_time, meter_date, meter_time, LAeq, response_time)
            VALUES (?, ?, ?, ?, ?, ?)
        ''', (pc_date, pc_time, meter_date, meter_time, LAeq, response_time))
        conn.commit()  # Commit the changes
    except sqlite3.IntegrityError:
        print(f"Duplicate entry for meter_date: {meter_date} and meter_time: {meter_time}. Entry not added.")
    finally:
        cursor.close()


if __name__ == "__main__":
    if device_info_success:
        live_monitoring_db = os.path.join(database_directory, f"{device_name}_{device_serial}_live-monitoring.db")
        conn = connect_to_database(live_monitoring_db)
    else:
        print("Device information not available, exiting...")
        sys.exit()

    running = True  # Flag for the main loop

#-------------------------------------------------------------------
### Being loop to poll data from status page every second
    start_time = time.time()
    next_poll_time = start_time + 1  # Set the time for the next poll

    try:
        while running:
            current_time = time.time()  # Record the time now
            if current_time >= next_poll_time:
                success, pc_date, pc_time, meter_date, meter_time, LAeq, response_time_str = get_device_status(port)  # Assuming this function is defined
                if success:
                    # Check for duplicates
                    cursor = conn.cursor()
                    cursor.execute("SELECT COUNT(*) FROM Measurements WHERE meter_date = ? AND meter_time = ?", (meter_date, meter_time))
                    exists = cursor.fetchone()[0]

                    if exists:
                        print(f"Entry with meter_date={meter_date} and meter_time={meter_time} already exists. Skipping entry.")
                    else:
                        insert_measurement_data(conn, pc_date, pc_time, meter_date, meter_time, LAeq, response_time_str)
                        print(f"Inserted data: pc_date={pc_date}, pc_time={pc_time}, meter_date={meter_date}, meter_time={meter_time}, LAeq={LAeq}")

                next_poll_time += 1  # Next polling time is 1 second later

            # Handle user-defined duration if applicable
            if run_time is not None and (current_time - start_time) >= run_time:
                print("User-defined duration has elapsed. Exiting...")
                running = False

    except KeyboardInterrupt:
        print("Interrupted by user. Stopping the program.")
        running = False

    finally:
        # Ensure cleanup and close the connection
        if 'conn' in locals() and conn:
            conn.close()
        sys.exit()  # Shutdown Python.exe upon exit