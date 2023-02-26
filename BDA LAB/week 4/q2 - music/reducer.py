#!/usr/bin/env python
import sys

# Initialize max_marks and max_name to None
max_marks = None
max_name = None

# Iterate over each key-value pair from mapper output
for line in sys.stdin:
    line = line.strip()
    marks, name = line.split('\t')
    marks = int(marks)

    # Check if marks are greater than current max_marks
    if max_marks is None or marks > max_marks:
        max_marks = marks
        max_name = name

# Output the name of the student with the highest marks
print(f'The topper is {max_name} with marks {max_marks}')
