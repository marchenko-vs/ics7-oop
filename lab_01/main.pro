QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += "inc/"

SOURCES += \
    src\main.cc \
    src\mainwindow.cc \
    src\canvas.cc \
    src\edges.cc \
    src\errors.cc \
    src\object.cc \
    src\points.cc \
    src\requests.cc

HEADERS += \
    inc\canvas.h \
    inc\edges.h \
    inc\errors.h \
    inc\mainwindow.h \
    inc\object.h \
    inc\points.h \
    inc\requests.h

FORMS += mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
