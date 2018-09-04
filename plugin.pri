TEMPLATE = lib


isEmpty(BIN_DIR) {
    BIN_DIR = $$PWD/bin
    CONFIG(debug, debug|release):BIN_DIR = $$join(BIN_DIR,,,_debug)
}
DESTDIR = $$join(BIN_DIR,,,/subviews_one)

QT += widgets network
CONFIG += plugin c++11

CONFIG(debug, debug|release):TARGET = $$join(TARGET,,,d)


INCLUDEPATH *= \
    $$PWD/interfaces \
    $$PWD/subview

LIBS *= \
    -L"$$BIN_DIR" \

DEPENDPATH += \
    $$INCLUDEPATH


HEADERS += \
    $$PWD/interfaces/PluginInterface.h \
    $$PWD/subview/SubviewWidget.h


SOURCES += \
    $$PWD/subview/SubviewWidget.cpp
