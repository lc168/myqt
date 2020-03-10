call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat"
qmake -o makefile testqmake.pro
jom /f makefile
pause