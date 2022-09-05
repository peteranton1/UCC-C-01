Read and display a CSV file
--------

This program demonstrates how to read a file in csv format, and convert internally to an array of structs and then print to the screen.

Input file "file.txt"

    U,Virat Kohli,23,95.6
    U,Serena Williams,21,83.2
    G,Wayne Gretzky,19,84.2

Screen output

    3 records read.
    U Virat Kohli 23 95.60
    U Serena Williams 21 83.20
    G Wayne Gretzky 19 84.20

## How to run

    gcc -o d CSVFile.c
    ./d
    