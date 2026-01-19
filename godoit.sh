#!/bin/bash

seq -99999 99999 | shuf -n "$1" > tmp.txt ; ./push_swap "$2" --bench $(cat tmp.txt)
./push_swap "$2" $(cat tmp.txt) | ./checker_linux $(cat tmp.txt)
