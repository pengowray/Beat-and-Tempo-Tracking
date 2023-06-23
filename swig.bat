@echo off
setlocal
set PATH=%PATH%;C:\apps\swigwin-4.1.1

mkdir bttswig
swig.exe -csharp -outdir bttswig BTT.i 

endlocal