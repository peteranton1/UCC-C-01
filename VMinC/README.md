Virtual Machine in C++
-------------

Implement a virtual stack machine in C++.

This implementation takes machine code instructions and data and runs those instructions and presents output on screen. 

This simulates the low level behaviour of a simple stack machine. This is useful for understanding stack machines. 

## How to Run

## Build and Run all

    ./run.sh
    

## Build and Run SASM

    cd sasm/
    make
    ./sasm test.sasm
    cp out.bin ../stack-vm

This builds the sasm program and then runs it. 

The sasm program assembles the file test.sasm which is the source code to assemble. 
Output file is called out.bin. 

This file is copied to the ../stack-vm/ folder

## Build and Run Stack-VM

    cd ../stack-vm
    make
    ./stack-vm out.bin

This loads out.bin which is the binary version of test.sasm and runs the program in the Stack VM. The output appears on screen. 
