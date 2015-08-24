#-------------------------------------------------
#
# Project created by QtCreator 2015-07-21T21:04:45
#
#-------------------------------------------------

include(../common.pri)

QT += widgets

TARGET = wplot
TEMPLATE = lib

DEFINES += WPLOT_LIBRARY

SOURCES += \
	Plot.cpp \
	Plot2D.cpp \
	Layer.cpp \
	Layer2D.cpp \
    Background.cpp \
    Graph.cpp \
    Padding.cpp \
    Grid2D.cpp \
    Item2D.cpp \
    Circle.cpp \
    Rectangle.cpp \
    ScatterGraph2D.cpp \
    Graph2D.cpp \
    ScalarGraph2D.cpp \
    LineGraph2D.cpp \
    BarGraph2D.cpp

HEADERS += \
	wplot_global.h \
	Plot.h \
	Plot2D.h \
	Layer.h \
	Layer2D.h \
    Background.h \
    Graph.h \
    Padding.h \
    Grid2D.h \
    Item2D.h \
    Circle.h \
    Rectangle.h \
    ScatterGraph2D.h \
    Graph2D.h \
    ScalarGraph2D.h \
    LineGraph2D.h \
    BarGraph2D.h

INCLUDEPATH += ../

release:DESTDIR = ../build/release
debug:DESTDIR = ../build/debug

unix {
	target.path = /usr/lib
	INSTALLS += target
}
