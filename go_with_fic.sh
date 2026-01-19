#!/bin/bash

seq -999999 999999 | shuf -n "$1" > tmp.txt
./push_swap --bench $(cat tmp.txt)
