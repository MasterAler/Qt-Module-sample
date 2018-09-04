TEMPLATE = subdirs

BIN_DIR = bin
CONFIG(debug, debug|release):BIN_DIR = $$join(BIN_DIR,,,_debug)

SUBDIRS += \
    MainWindow \
    SampleModule1 \
    SampleModule2

SUBVIEW_DIR = $${BIN_DIR}/subview
SUBVIEW_DIR ~= s,/,\\,g
