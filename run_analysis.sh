#!/bin/bash
echo "Running program on container..."
mkdir -p /result
{ time ./cpu_load; } 2> /result/container_time.txt
if [[ -f /result/container_time.txt ]]; then
    echo "Program executed successfully."
else
    echo "Error: Results file not created."
fi