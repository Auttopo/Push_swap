#!/bin/bash

seq -9999 9999 | shuf -n "$1" > tmp.txt
./a.out --bench $(cat tmp.txt)
