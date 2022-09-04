#!/bin/sh
clear
cd sasm
make
./sasm test.sasm
cp out.bin ../stack-vm
cd ../stack-vm
make
./stack-vm out.bin 
cd ..
