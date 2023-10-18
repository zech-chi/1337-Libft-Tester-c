#!/bin/bash

# Check if the user provided a value for k as an argument
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <k>"
    exit 1
fi

# Extract the value of k from the command line argument
k="$1"

# Define the file paths based on the value of k
expected_file="expected/test${k}.txt"
got_file="got/test${k}_got.txt"

# Check if the expected file exists
if [ ! -f "$expected_file" ]; then
    echo "Error: $expected_file does not exist."
    exit 1
fi

# Check if the got file exists
if [ ! -f "$got_file" ]; then
    echo "Error: $got_file does not exist."
    exit 1
fi

# Run the cat command
# Read the entire contents of the files into variables
got_output=$(cat "$got_file")
expected_output=$(cat "$expected_file")

# Display the contents of the variables
echo "got     : '$got_output'"
echo "expected: '$expected_output'"