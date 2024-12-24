### Export SQLite database files to CSV files
# Currently set to both live monitoring and exported data databases

import sqlite3
import pandas as pd
import os
from datetime import datetime

# Define the model number and serial number
model_number = "821SE"
serial_number = "40126"

# Define the directory for the SQLite databases
database_directory = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase"
output_directory = r"C:\Users\WAL01\Desktop\test_output"

# Construct the database file names
live_monitoring_db = os.path.join(database_directory, f"{model_number}_{serial_number}_live-monitoring.db")
exported_data_db = os.path.join(database_directory, f"{model_number}_{serial_number}_exported_csv_data.db")

# Generate a unique filename for the exported CSV files using the current date and time
timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
live_monitoring_csv_path = os.path.join(output_directory, f"live_monitoring_data_export_{timestamp}.csv")
exported_data_csv_path = os.path.join(output_directory, f"exported_data_export_{timestamp}.csv")

# Function to export the SQLite database to a CSV file
def export_database_to_csv(db_path, csv_path, table_name):
    try:
        # Connect to the SQLite database
        conn = sqlite3.connect(db_path)

        # Read the data from the specified table into a DataFrame
        df = pd.read_sql_query(f"SELECT * FROM {table_name}", conn)

        # Export the DataFrame to a CSV file
        df.to_csv(csv_path, index=False)
        print(f"Data exported from table '{table_name}' in '{db_path}' to {csv_path} successfully.")

    except sqlite3.Error as e:
        print(f"An error occurred while accessing the database '{db_path}': {e}")
    except Exception as e:
        print(f"An error occurred while exporting data: {e}")
    finally:
        # Close the connection
        if conn:
            conn.close()

# Export commences
export_database_to_csv(live_monitoring_db, live_monitoring_csv_path, "LiveMeasurements")
export_database_to_csv(exported_data_db, exported_data_csv_path, "ExportedData")