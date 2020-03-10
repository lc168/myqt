QT += widgets


SOURCES += main.cpp \
    form2.cpp
CONFIG += console
DESTDIR += ../bin
TARGET = testq

win32: LIBS += -LC:\Qt\Qt5.14.0\5.14.0\opencv4.2.0\build\x64\vc15\lib -lopencv_world420
win32: LIBS += -LC:\Qt\Qt5.14.0\5.14.0\mscv2017_sys\lib\um\x64 -lkernel32
win32: LIBS += -LC:\Qt\Qt5.14.0\5.14.0\mscv2017_sys\lib\ucrt\x64 -lucrtd

INCLUDEPATH += C:\Qt\Qt5.14.0\5.14.0\opencv4.2.0\build\include
INCLUDEPATH += C:\Qt\Qt5.14.0\5.14.0\mscv2017_sys\include\ucrt
#DEPENDPATH +=  C:\Qt\Qt5.14.0\5.14.0\opencv4.2.0\build\x64\vc15\bin

FORMS += \
    form1.ui \
    form2.ui

HEADERS += \
    form2.h
