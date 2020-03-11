QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

win32: LIBS += -LC:\Qt\Qt5.14.0\5.14.0\opencv4.2.0\build\x64\vc15\lib -lopencv_world420
win32: LIBS += -LC:\Qt\Qt5.14.0\5.14.0\mscv2017_sys\lib\um\x64 -lkernel32
win32: LIBS += -LC:\Qt\Qt5.14.0\5.14.0\mscv2017_sys\lib\ucrt\x64 -lucrtd

INCLUDEPATH += C:\Qt\Qt5.14.0\5.14.0\opencv4.2.0\build\include
INCLUDEPATH += C:\Qt\Qt5.14.0\5.14.0\mscv2017_sys\include\ucrt
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    widget.cpp

HEADERS += \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
