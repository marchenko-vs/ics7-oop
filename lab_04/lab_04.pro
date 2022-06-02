QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += "inc/"

SOURCES += \
    src\main.cc \
    src\mainwindow.cc \
    src\button.cc \
    src\cabin.cc \
    src\controller.cc \
    src\doors.cc \
    src\elevator.cc

HEADERS += \
    inc\button.h \
    inc\cabin.h \
    inc\controller.h \
    inc\doors.h \
    inc\elevator.h \
    inc\mainwindow.h

FORMS += \
    mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
