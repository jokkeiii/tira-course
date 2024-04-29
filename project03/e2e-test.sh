#!/bin/bash

# Set the number of times to loop
n=5
d=10000
k=14
for ((i = 1; i <= n; i++))
do
  # Echo '3' and pipe it into the CLI application
  echo "4 $d $k" | ./testped
done