#-------------------------------------------------
#
# Project created by QtCreator 2015-04-01T16:47:28
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tetris
TEMPLATE = lib

CONFIG += staticlib
CONFIG += c++11

QMAKE_LFLAGS += -Xlinker -Bstatic

SOURCES +=\
        mainwindow.cpp \
    qt_graphics.cpp

HEADERS  += mainwindow.h \
    qt_graphics.h

FORMS    += mainwindow.ui
