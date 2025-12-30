#!/bin/bash

seq -10 9999 | shuf -n "$1" > tmp.txt ; ./a.out $(cat tmp.txt) | wc -l
