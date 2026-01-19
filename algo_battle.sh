#!/bin/bash

seq 0 500 | shuf -n "$1" > tmp.txt ; ./push_swap --bench "$2" $(cat tmp.txt)
./push_swap "$3" --bench $(cat tmp.txt)
