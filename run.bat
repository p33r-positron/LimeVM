@echo off
REM Compiling with GCC (Replace with CLANG/TCC/Your favorite compiler if you want to).
gcc .\src\main.c -o .\build\main.exe
REM Assembling with NASM (You can manually write the bytes if you want to).
nasm .\floppy.asm -f bin -o .\build\floppy.bin

REM Running program
.\build\main.exe .\build\floppy.bin
@echo on