import sqlite3
import pandas as pd
import os
from datetime import datetime

# Define the model number and serial number
model_number = "821SE"
serial_number = "40126"

# Define the directory for the SQLite databases
database_directory = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\SQLiteDatabase"

# Construct the database file name
database_name = f"{model_number}_{serial_number}_exported_csv_data.db"

# Define the path to your SQLite database
database_path = os.path.join(database_directory, database_name)

# Generate a unique filename for the exported CSV file using the current date and time
timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
export_csv_path = os.path.join(r"C:\Users\WAL01\Desktop", f"exported_data_{timestamp}.csv")

# Function to export the SQLite database to a CSV file
def export_database_to_csv(db_path, csv_path):
    # Connect to the SQLite database
    conn = sqlite3.connect(db_path)

    # Read the data from the ExportedData table into a DataFrame
    df = pd.read_sql_query("SELECT * FROM ExportedData", conn)

    # Export the DataFrame to a CSV file
    df.to_csv(csv_path, index=False)
    print(f"Data exported to {csv_path} successfully.")

    # Close the connection
    conn.close()

# Call the function to export the database to CSV
export_database_to_csv(database_path, export_csv_path)