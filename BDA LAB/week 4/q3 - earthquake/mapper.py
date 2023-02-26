#!/usr/bin/env python
import sys

# Read each line from input and extract earthquake information
for line in sys.stdin:
    line = line.strip()
    date, time, latitude, longitude, depth, magnitude = line.split(',')

    # Emit key-value pairs for magnitude and count
    print(f'{magnitude}\t1')
