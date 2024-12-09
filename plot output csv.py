### Prototype code to read and plot real-time data logged CSV

import pandas as pd
import matplotlib
matplotlib.use('TkAgg')  # Use a suitable backend
import matplotlib.pyplot as plt
from matplotlib.dates import DateFormatter  # Import DateFormatter from matplotlib.dates
import mplcursors

# Load the CSV file, using the second row as header
data = pd.read_csv(r'C:\Users\WAL01\Desktop\test_output\test_weekend_6 dec.csv', header=1)

# Verify the loaded data
print("Data Loaded:")
print(data.head())  # Check the first few rows
print(data.info())  # Check the DataFrame structure and data types

# Combine 'Meter Date' and 'Meter Time' into a single datetime column
data['datetime'] = pd.to_datetime(
    data['Meter Date'] + ' ' + data['Meter Time'],
    format='%d/%m/%Y %H:%M:%S'  # Specify the correct date and time format
)

# Set the datetime as the index
data.set_index('datetime', inplace=True)

# Check if 'LAeq' column exists and its values
if 'LAeq' in data.columns:
    print("LAeq Column Found:")
    print(data['LAeq'].head())  # Check the first few values of the LAeq column
else:
    print("LAeq column not found in the data.")
    exit()  # Exit if the column is not found

# Plotting as a scatter plot to avoid connecting lines
plt.figure(figsize=(12, 6))
plt.scatter(data.index, data['LAeq'], label='LAeq', color='blue', s=2)  # Smaller scatter point size
plt.title('LAeq vs Meter Time')
plt.xlabel('Meter Time')
plt.ylabel('LAeq')

# Formatting the x-axis to show date and time clearly
plt.xticks(rotation=45)
plt.gca().xaxis.set_major_formatter(DateFormatter('%Y-%m-%d %H:%M:%S'))  # Correctly format datetime
plt.gca().xaxis.set_major_locator(plt.MaxNLocator(nbins='auto'))  # Automatically adjust tick locations

plt.legend()
plt.tight_layout()

# Adding interactivity with precise datetime
cursor = mplcursors.cursor(hover=True)
@cursor.connect("add")
def on_add(sel):
    sel.annotation.set_text(f'Time: {data.index[sel.index]}\nLAeq: {data["LAeq"].iloc[sel.index]}')
    sel.annotation.get_bbox_patch().set_alpha(0.5)  # Optional: make annotation background semi-transparent

# Show the plot
plt.show()