@echo off
setlocal
set PATH=%PATH%;C:\msys64\mingw64\bin
set PATH=%PATH%;C:\msys64

gcc -c -DBUILD_DLL src/BTT.c -o src/BTT.o
gcc -c -DBUILD_DLL src/DFT.c -o src/DFT.o
gcc -c -DBUILD_DLL src/Filter.c -o src/Filter.o
gcc -c -DBUILD_DLL src/STFT.c -o src/STFT.o
gcc -c -DBUILD_DLL src/Statistics.c -o src/Statistics.o
gcc -c -DBUILD_DLL src/fastsin.c -o src/fastsin.o

gcc -shared -o BTT.dll src/BTT.o src/DFT.o src/Filter.o src/STFT.o src/Statistics.o src/fastsin.o -Wl,--out-implib,libBTT.a

endlocal