### Upload Data to a SQL Database with Python

import sqlite3

# Step 1: Connect to the database (or create it if it doesn't exist)
connection = sqlite3.connect('example.db')

# Step 2: Create a cursor object to execute SQL commands
cursor = connection.cursor()

# Step 3: Create a table (if it doesn't exist)
cursor.execute('''
CREATE TABLE IF NOT EXISTS sound_data (
    id INTEGER PRIMARY KEY,
    timestamp TEXT,
    value REAL
)
''')

# Step 4: Prepare your data to upload
data_to_insert = [
    ('2024-12-18 12:00:00', 75.5),
    ('2024-12-18 12:01:00', 78.0),
    ('2024-12-18 12:02:00', 72.3),
]

# Step 5: Insert data into the table
cursor.executemany('''
INSERT INTO sound_data (timestamp, value) VALUES (?, ?)
''', data_to_insert)

# Step 6: Commit the transaction
connection.commit()

# Step 7: Close the connection
connection.close()