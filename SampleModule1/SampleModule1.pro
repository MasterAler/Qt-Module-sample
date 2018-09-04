QT       += core gui widgets


SOURCES += main.cpp\
        FirstModule.cpp \
    FirstPlugin.cpp

HEADERS  += FirstModule.h \
    FirstPlugin.h

FORMS    += FirstModule.ui

include($$PWD/../plugin.pri)
