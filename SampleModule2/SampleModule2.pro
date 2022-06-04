QT       += core gui widgets

SOURCES += main.cpp\
        SecondModule.cpp

HEADERS  += SecondModule.h

FORMS    += SecondModule.ui

include($$PWD/../plugin2.pri)
