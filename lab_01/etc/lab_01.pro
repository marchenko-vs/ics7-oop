QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

INCLUDEPATH += "..\inc"

SOURCES += \
    ..\src\canvas.cpp \
    ..\src\edges.cpp \
    ..\src\errors.cpp \
    ..\src\main.cpp \
    ..\src\mainwindow.cpp \
    ..\src\object.cpp \
    ..\src\points.cpp \
    ..\src\requests.cpp

HEADERS += \
    ..\inc\canvas.h \
    ..\inc\edges.h \
    ..\inc\errors.h \
    ..\inc\mainwindow.h \
    ..\inc\object.h \
    ..\inc\points.h \
    ..\inc\requests.h

FORMS += \
    ..\etc\mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
