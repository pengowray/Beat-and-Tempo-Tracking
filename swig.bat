@echo off
setlocal
set PATH=%PATH%;C:\apps\swigwin-4.1.1
set PATH=%PATH%;C:\msys64\mingw64\bin
set PATH=%PATH%;C:\msys64

mkdir btt-cs
swig.exe -csharp -outdir btt-cs BTT.i 

rem gcc -lm -lpthread -lrt

mkdir build
cd build
gcc -c -fpic -lm ../src/*.c ../BTT_wrap.c 
gcc -shared *.o -o BTT.dll
rem mono-csc -out:runme.exe *.cs
rem cat runme.cs

endlocal