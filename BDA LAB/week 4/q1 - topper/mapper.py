#!/usr/bin/env python
import sys

# Read each line from input and extract student name and marks
for line in sys.stdin:
    line = line.strip()
    name, marks = line.split(',')
    # Emit key-value pair with marks as key and student name as value
    print(f'{marks}\t{name}')
