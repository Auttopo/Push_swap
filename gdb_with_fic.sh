#!/bin/bash

seq -9999 9999 | shuf -n "$1" > tmp.txt
gdb -tui --args ./h_swap --complex  $(cat tmp.txt)

