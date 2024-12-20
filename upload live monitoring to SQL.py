### Upload live monitoring values into database
# 1. Database Connection and Insertion: 
# You need to connect to the SQLite database and insert the monitoring data after a successful poll.
# 2. Data Insertion Function:
# Create a function to handle data insertion into the database.

import sqlite3
import os
import requests
import time
from datetime import datetime

# Create database names
database_directory = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase"
port = 1234  # Replace with your actual port number

# Function to connect to the SQLite database
def connect_to_database(db_path):
    conn = sqlite3.connect(db_path)
    return conn

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
    ### Start a separate thread to listen for the interrupt key
    threading.Thread(target=listen_for_interrupt, args=(interrupt_key,), daemon=True).start()
    #.
    #.
    #.
    else:
        # Successful retrieval of device info
        print(f"Device: {device_name} - {device_serial}")

    # Create live monitoring database path only if device info was retrieved successfully
    if device_info_success:
        live_monitoring_db = os.path.join(database_directory, f"{device_name}_{device_serial}_live-monitoring.db")
        # Connect to the database
        conn = connect_to_database(live_monitoring_db)
    else:
        # Handle the case where device info retrieval failed
        print("Device information not available, exiting...")
        running = False  # Adjust exit logic as needed

#-------------------------------------------------------------------
### Being loop to poll data from status page every second
    start_time = time.time()
    next_poll_time = start_time + 1  # Set the time for the next poll

    try:
        while running: 
            # trigger the poll if current time matches the next poll time
            current_time = time.time()  # Record the time now
            if current_time >= next_poll_time:
                success, pc_date, pc_time, meter_date, meter_time, LAeq, response_time_str = get_device_status(current_port)
                if success:
                    log_data(pc_date, pc_time, meter_date, meter_time, LAeq, output_file_path)  # Call the new log_data function
                    insert_monitoring_data(conn, pc_date, pc_time, meter_date, meter_time, LAeq)

                next_poll_time += 1 # next polling time is 1 second later

        # Handles if monitoring duration is pre-set by user, and stops the program accordingly
            if run_time is not None and (current_time - start_time) >= run_time:
                print("User-defined duration has elapsed. Exiting...")
                running = False  # running to False to prevent infinite loop when run_time = None

    except KeyboardInterrupt:
        logging.info("Interrupted by user. Stopping the program.")
        running = False  # running to False to prevent infinite loop when run_time = None

    finally:
        conn.close()
        cleanup()  # Ensure cleanup is called on exit
        sys.exit() # Shutdown Python.exe upon exit