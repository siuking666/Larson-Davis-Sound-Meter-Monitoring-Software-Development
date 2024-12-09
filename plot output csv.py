import pandas as pd
import matplotlib.pyplot as plt
import mplcursors

# Load the CSV file, using the second row as header
data = pd.read_csv(r'C:\Users\WAL01\Desktop\test_output\test_weekend_6 dec.csv', header=1)

# Combine 'Meter Date' and 'Meter Time' into a single datetime column
data['datetime'] = pd.to_datetime(data['Meter Date'] + ' ' + data['Meter Time'])

# Set the datetime as the index
data.set_index('datetime', inplace=True)

# Plotting
plt.figure(figsize=(12, 6))
line, = plt.plot(data.index, data['LAeq'], label='LAeq', color='blue')

# Formatting the date ticks
plt.xticks(rotation=45)

# Marking the date at each new day
unique_dates = set(data['Meter Date'])

for date in unique_dates:
    plt.axvline(pd.to_datetime(date), color='red', linestyle='--', label=date)

# Adding interactivity
mplcursors.cursor(line, hover=True)

# Updating legend to avoid duplicates
handles, labels = plt.gca().get_legend_handles_labels()
by_label = dict(zip(labels, handles))
plt.legend(by_label.values(), by_label.keys(), title='Dates', bbox_to_anchor=(1.05, 1), loc='upper left')

plt.title('LAeq vs Meter Time')
plt.xlabel('Meter Time')
plt.ylabel('LAeq')
plt.tight_layout()
plt.show()