TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp


HEADERS += \
    reader.h

OTHER_FILES += \
    test.txt

QMAKE_CXXFLAGS += -std=c++11
