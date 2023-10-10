#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <test_file_name>"
    exit 1
fi

test_file="$1"
source_file="../Libft/${test_file}.c"

if [ ! -f "${source_file}" ]; then
    # Define ANSI escape codes for color
    RED='\e[31m'
    RESET='\e[0m'

    # Message to display
    message="Source file '${source_file}' not found :("
    message1="check the name of the file again."

    # Print the message in red
    echo -e "${RED}${message}${RESET}"
    echo -e "${RED}${message1}${RESET}"
    exit 1
fi

compile_command="cc -Wall -Wextra -Werror ${test_file}_test.c myheader.c ${source_file}"

# color green
GREEN='\e[32m'
RESET='\e[0m'

# Message to display
message="Compiling and running ${test_file}_test.c..."

# Print the message in green
echo -e "${GREEN}${message}${RESET}"
echo ""

$compile_command

sleep 0.4

run_command="./a.out"
remove_output_file="rm ./a.out"

if [ -f "./a.out" ]; then
    $run_command
    $remove_output_file
fi