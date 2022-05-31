TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "inc"

SOURCES += \
        src\main.cc \
        src\example.cc \
        src\base_iterator.cc \
        src\base_vector.cc \

HEADERS += \
        inc\example.hpp \
        inc\base_iterator.hpp \
        inc\base_vector.hpp \
        inc\const_iterator.hpp \
        inc\iterator.hpp \
        inc\vector.h \
        inc\vector.hpp \
        inc\errors.hpp
