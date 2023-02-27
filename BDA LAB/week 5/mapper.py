#!/usr/bin/env python

import sys

# input comes from standard input (stdin)
for line in sys.stdin:
    # split the line into columns
    columns = line.strip().split(',')

    # extract the country and magnitude columns
    country = columns[5]
    magnitude = None

    # try to parse the magnitude from each of the columns that could contain it
    try:
        magnitude = float(columns[11])
    except ValueError:
        pass

    try:
        if magnitude is None:
            magnitude = float(columns[12])
    except ValueError:
        pass

    try:
        if magnitude is None:
            magnitude = float(columns[13])
    except ValueError:
        pass

    # output the country and magnitude as separate values if magnitude is not None
    if magnitude is not None:
        print(f"{country}\t{magnitude}")

