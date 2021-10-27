#!/bin/bash

# Compiling with GCC (Replace with CLANG/TCC/Your favorite compile if you want to).
gcc ./src/main.c -o ./build/main
# Assembling with NASM (You can manually write the bytes if you want to).
nasm ./floppy.asm -f bin -o ./build/floppy.bin

# Running Program
./build/main ./build/floppy.bin