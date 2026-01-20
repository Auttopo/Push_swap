#!/bin/bash

seq -99999 99999 | shuf -n "$1" > tmp.txt
./push_swap --complex --bench $(cat tmp.txt) #| ./checker_linux $(cat tmp.txt)
