### Extract desired data from csv data files from Larson Davis Utility App
### Originally written in Python 3.9

import pandas as pd
import os
import re
import shutil
import sys

### CHECK THESE VARIABLES!!! THE CODE DEPENDS ON THEM TO RUN!!!
input_directory_path = r"\\WAL-NAS\wal\TEMP\TEMP2023\Research\KC3\Larson Davis Sound Meter Monitoring Software Development\Test Data Sets - Exported Data Processing\Custom Test Data Set 1" # set input folder
output_directory_path = r"C:\Users\WAL01\Desktop\test_output" # set output folder
base_output_file = "time_history" # name of output file will have date as prefix and version number as suffix
output_file_extension = ".csv" # Currently ONLY support .csv
model_number = '821SE' # Give the model number of the sound meter that exported the data
serial_number = '40126' # Give the serial number of the sound meter that exported the data

# Specify a file name, e.g. 'example.csv' or leave it as 'None' to process all CSV files
specific_file_name = None

# Specify the columns you want to omit, no need to include the spaces
columns_to_skip = ['Record Type', 'LApk', 'LCeq', 'LCpk', 'LZeq', 'LZpk', 'External (V)', 'Battery (%)', 'Power Source', 'Overload', 'Invalid', 'Markers'] 

#------------------------------------------
### Preliminary checks & define functions

# Check if the input directory exists, if not, the program stops
if not os.path.exists(input_directory_path):
    print(f"Input directory does not exist: {input_directory_path}")
    exit(1)

# if the output directory does not exist, create one    
if not os.path.exists(output_directory_path):
    os.makedirs(output_directory_path)

# Validate that the filename contains the correct model and serial number, otherwise skip processing
# Assume the filename is structed as "{model_number} {serial_number}-{date}{index}-{time}"
def validate_filename(file_name):
    # Split the filename at hyphens into 3 parts
    parts = file_name.split('-')[0].split()  # Get the first part and split it again by space
    if len(parts) >= 2:
        extracted_model = parts[0] # {model_number}
        extracted_serial = parts[1] # {serial_number}
        # compare-checks
        return extracted_model == model_number and extracted_serial == serial_number 
        # returns True or False
    return False

# Read the date of a file from its filename, based on default naming pattern
# Assume the filename is structed as "{model_number} {serial_number}-{date}{index}-{time}"
def extract_date(file_name):
    # Split the filename at hyphens into 3 parts
    parts = file_name.split('-') 
    if len(parts) > 1:
    # Get the second part {date}{index} after first hyphen
    # Return the first 6 characters as the date
        date_part = parts[1]  
        return date_part[:6]  
    return None

# Process an inputted CSV file and return the DataFrame.
def process_file(input_file):
    try:
        df = pd.read_csv(input_file)
        # Empty csv file error handling
        if df.empty:
            print(f"{input_file} is empty, skipping...")
            return # skip this file and continue
        
        df = df[:-1]  # Discard the last row; normally no data
        # Strip leading/trailing spaces from the column NAMES, does not strip the content elements
        df.columns = df.columns.str.strip()  
        
        # discard columns specified above
        # Use errors='ignore' to avoid errors if specified columns don't exist
        df_2 = df.drop(columns=columns_to_skip, errors='ignore')
        return df_2

    # Exception handling for input file does not exist
    except FileNotFoundError:
        print(f"Error: The file {input_file} was not found.")
        return None
    # Exception handling for value error
    except ValueError as e:
        print(f"Value error in {input_file}: {e}")
        return None  # Skip this file and continue
    # Exception handling for other errors, i.e. file with password, or corruptions
    except Exception as e:
        print(f"An error occurred while reading the file: {e}")
        return None

# Define lists and dictionaries as temporary memory during processing
dataframes_by_date = []
processed_files_by_date = {}

#------------------------------------------
### File processing procedure
if __name__ == "__main__":

    ### If a specific file is provided, process that file ONLY

    if specific_file_name: # if "None", whole thing is skipped
        input_file = os.path.join(input_directory_path, specific_file_name) # full directory

        # Exception handling for input file does not exist
        if not os.path.isfile(input_file):
            print(f"{input_file} does not exist, skipping...")
        # avoids processing an existing output file with defined output file name
        elif specific_file_name.startswith(base_output_file):
            print(f"{input_file} is an output file, skipping...")

        # process
        else:
            print(f"Processing {input_file}...")
            # Check if the file matches the given model and serial number
            if validate_filename(specific_file_name):  
                date_str = extract_date(specific_file_name) # date extracted from filename
                result_df = process_file(input_file) # data reduction
                # check that the data is not empty and date is valid
                if result_df is not None and not result_df.empty and date_str:
                    # processed data saved in dataframes_by_date for saving
                    dataframes_by_date.append((date_str, result_df))         
            else:
                print('---------------------')
                print(f"{specific_file_name} does not match the model and serial number, skipping...")

    #------------------------------------------ 
    ### Otherwise Process all CSV files matching the model & serial numbers in the directory
    else:
        # loop through the entire input directory
        for file_name in os.listdir(input_directory_path):
        # only qualifies CSV files as inputs
            if file_name.endswith('.csv'):
                # full input file directory
                input_file = os.path.join(input_directory_path, file_name)

                # avoids processing output file
                if file_name.startswith(base_output_file):
                    print(f"{input_file} is an output file, skipping...")
                    continue
                
                else:
                # only processes csv files in input directory
                    print(f"Processing {input_file}...")
                # Check if the file matches the given model and serial number
                    if validate_filename(file_name):
                        date_str = extract_date(file_name) # date extracted from filename

                        # Currently, files with unknown dates are skipped
                        if date_str is None:
                            print(f"No date found in {file_name}, skipping...")
                            continue
                        
                        # data reduction on CSV files matching the given model and serial number & known dates
                        result_df = process_file(input_file)
                        # check that the data is not empty and date is valid
                        if result_df is not None and not result_df.empty and date_str:
                            # processed data saved in dataframes_by_date for saving
                            dataframes_by_date.append((date_str, result_df))
                            # keeping track of all dates present in processed files and all processed files' names
                            if date_str not in processed_files_by_date:
                                # processed_files_by_date is a dictionary, date acts as index and a list is created under each index
                                processed_files_by_date[date_str] = []
                            processed_files_by_date[date_str].append(file_name)  # Track successfully processed file by date
                        # General error message if processing fails
                        else:
                            print(f"Failed to process {input_file}")
                    else:
                        print('---------------------')
                        print(f"{file_name} does not match the model and serial number, skipping...")           
                    
    #--------------------------------------------------
    # dataframes_by_date = processed CSV content, each element saves each processed result with its date
    # processed_files_by_date tracks all the processed file names and all dates appeared
    # grouped_dataframes combines all processed results with one same date into one element

    # Combine and save files for each date
    if dataframes_by_date:
        # combine entries by date
        grouped_dataframes = {}
        for date_str, df in dataframes_by_date:
            if date_str not in grouped_dataframes:
                grouped_dataframes[date_str] = []
            grouped_dataframes[date_str].append(df)
    # Example of dataframes_by_date = [("202311", df1), ("202311", df2)]
    # Example of grouped_dataframes = {"202311": [df1, df2]}

        for date_str, dataframes in grouped_dataframes.items():
            combined_df = pd.concat(dataframes, ignore_index=True)
            # The concat function in pandas is used to concatenate (or stack) multiple DataFrames along a particular axis—either row-wise or column-wise.
            # now each date_str has only one combined_df

            # Construct base output file name
            base_output_name = f"{date_str}_{base_output_file}"
            output_file_path = os.path.join(output_directory_path, f"{base_output_name}{output_file_extension}")

            version = 1
            while os.path.exists(output_file_path):
            # only runs if an output file of the same name already exists
                output_file_path = os.path.join(output_directory_path, f"{base_output_name}_v{version}{output_file_extension}")
                version += 1

            # Save the combined DataFrame to a new CSV file
            try:
                combined_df.to_csv(output_file_path, index=False)  # Avoid writing row indices
                print('---------------------')
                print(f"Saved {output_file_path} with specified columns skipped.")
                print('---------------------')

            except Exception as e:
                print(f"An error occurred while saving the file: {e}")

            # Create a folder for the date if it doesn't exist and move the original files
            date_folder = os.path.join(output_directory_path, date_str)
            os.makedirs(date_folder, exist_ok=True)

            # Copy only processed files to the corresponding date folder
            if date_str in processed_files_by_date:
                for file_name in processed_files_by_date[date_str]:
                    shutil.copy(os.path.join(input_directory_path, file_name), os.path.join(date_folder, file_name))
                    print(f"Copied {file_name} to {date_folder}")
    else:
        print("No CSV files were processed.")

    sys.exit() # Shutdown Python.exe upon exit