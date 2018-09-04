QT       += core gui widgets

TARGET = MainWindow
TEMPLATE = app

CONFIG += c++11

isEmpty(BIN_DIR) {
    BIN_DIR = $$PWD/../bin
    CONFIG(debug, debug|release):BIN_DIR = $$join(BIN_DIR,,,_debug)
}
DESTDIR=$$BIN_DIR


SUBVIEW_DIR = $${BIN_DIR}/subview
SUBVIEW_DIR ~= s,/,\\,g

SOURCE_DIR = $$PWD
SOURCE_DIR ~= s,/,\\,g

INCLUDEPATH *= \
    $$PWD/../subview \
    $$PWD/../interfaces

DEPENDPATH *= \
    $$INCLUDEPATH

HEADERS  += MainWidget.h \
    $$PWD/../interfaces/ModuleInterface.h \
    $$PWD/../interfaces/PluginInterface.h \
    $$PWD/../subview/Subview.h \
    $$PWD/../subview/SubviewWidget.h \
    Loader.h

SOURCES += main.cpp\
    MainWidget.cpp \
    Loader.cpp \
    $$PWD/../subview/Subview.cpp \
    $$PWD/../subview/SubviewWidget.cpp \


FORMS    += MainWidget.ui

LIBS *= \
    -L"$$DESTDIR"
