@echo off

REM Install MinGW-w64
echo Installing MinGW-w64...
mingw-get.exe install mingw32-base
mingw-get.exe install msys-base

REM Install pthreads-win32
echo Installing pthreads-win32...
curl -O https://www.sourceware.org/pub/pthreads-win32/pthreads-w32-2-9-1-release.zip
tar -xf pthreads-w32-2-9-1-release.zip
cd pthreads-w32-2-9-1-release
mingw32-make.exe GC-static
mingw32-make.exe install GC-static
cd ..

REM Install gnuplot
echo Installing gnuplot...
curl -O https://sourceforge.net/projects/gnuplot/files/gnuplot/5.2.8/gp528-win64-mingw.zip
unzip gp528-win64-mingw.zip

REM Compile C code
echo Compiling C code...
gcc -o stock_game.exe stock_game.c -lpthread

echo Done.