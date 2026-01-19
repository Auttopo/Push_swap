#!/bin/bash

seq 0 500 | shuf -n "$1" > tmp.txt ; ./push_swap --bench $(cat tmp.txt)
./push_swap $(cat tmp.txt) | ./checker_linux $(cat tmp.txt)
./push_swap $(cat tmp.txt) | ./a.out $(cat tmp.txt)
