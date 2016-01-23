#!/bin/bash

g++ tools/romdump.cpp -std=c++11 -O3 -static -o tools/romdump

or1k-elf-g++ tools/lib.cpp -ffreestanding -std=c++11 -O0 -c -o tools/lib.o

or1k-elf-g++ "$1" -std=c++11 -ffreestanding -Itools -O0 -c -o "$1"".o"
or1k-elf-g++ "$1"".o" tools/lib.o -O0 -ffreestanding -nostdlib -o "$(basename "$1" .cpp)"
or1k-elf-objdump -d "$(basename "$1" .cpp)"
./tools/romdump "$(basename "$1" .cpp)"
rm "$1"".o"
rm "$(basename "$1" .cpp)"
