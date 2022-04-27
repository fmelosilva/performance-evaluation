#!/bin/bash

printf "execution;time elapsed"
for i in {1..30}; do
    time_elasped=$(./bin/q3/q3.out < in/q3/1.txt | awk '/^time elapsed:/ {print $3}')
    printf "\n%d;%f" "$i" "$time_elasped"
done