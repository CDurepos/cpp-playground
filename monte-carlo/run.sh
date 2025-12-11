#!/bin/bash

eval "$(conda shell.bash hook)"

# Setup conda
if ! conda env list | grep -q "monte-carlo"; then
    conda create -n monte-carlo python -y
fi
conda activate monte-carlo

# Install python dependencies
pip install matplotlib pandas numpy

# Compile C++
g++ ./main.cpp -o main.exe

# Run
./main.exe

# Plot
python plot.py