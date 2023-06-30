#!/usr/bin/bash

# compile the source
g++ -o $1.exe $1.cpp -fopenmp

# make it executable
chmod 700 $1.exe

