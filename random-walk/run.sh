#!/bin/bash

# Setup conda
conda create -n random-walk python -n
eval "$(conda shell.bash hook)"
conda activate random-walk

# Install python dependencies
pip install matplotlib pandas

# Compile C++
g++ ./main.cpp -o main.exe

# Run
./main.exe

# Plot
python plot.py