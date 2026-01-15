#!/bin/bash

seq 0 500 | shuf -n "$1" > tmp.txt ; ./a.out --bench $(cat tmp.txt)
./a.out $(cat tmp.txt) | ./checker_linux $(cat tmp.txt)
