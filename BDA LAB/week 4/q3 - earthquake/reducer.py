#!/usr/bin/env python
import sys

# Initialize variables for total earthquakes and total magnitude
total_earthquakes = 0
total_magnitude = 0.0

# Iterate over each key-value pair from mapper output
for line in sys.stdin:
    line = line.strip()
    magnitude, count = line.split('\t')

    # Increment total earthquakes and total magnitude
    total_earthquakes += int(count)
    total_magnitude += float(magnitude) * int(count)

# Compute average magnitude of earthquakes
if total_earthquakes > 0:
    avg_magnitude = total_magnitude / total_earthquakes
else:
    avg_magnitude = 0.0

# Output information about the earthquakes
print(f'Total number of earthquakes: {total_earthquakes}')
print(f'Average magnitude of earthquakes: {avg_magnitude}')
