#!/usr/bin/env python

import sys

# Initialize variables to hold earthquake counts and total magnitudes by country
current_country = None
earthquake_count = 0
total_magnitude = 0

# Loop through each line of input from the mapper
for line in sys.stdin:

    # Split the line into country and magnitude
    country, magnitude = line.strip().split('\t')

    # Convert magnitude to a float
    magnitude = float(magnitude)

    # If the country changes, output the total number of earthquakes and average magnitude for the previous country
    if country != current_country and current_country is not None:
        avg_magnitude = total_magnitude / earthquake_count
        print(current_country + '\t' + str(earthquake_count) + '\t' + str(avg_magnitude))
        earthquake_count = 0
        total_magnitude = 0

    # Update earthquake count and total magnitude for the current country
    current_country = country
    earthquake_count += 1
    total_magnitude += magnitude

# Output the earthquake count and average magnitude for the last country in the loop
if current_country is not None:
    avg_magnitude = total_magnitude / earthquake_count
    print(current_country + '\t' + str(earthquake_count) + '\t' + str(avg_magnitude))

