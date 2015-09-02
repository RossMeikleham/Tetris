TEMPLATE = app

QT += quick qml widgets testlib
TARGET = tetris_tests

CONFIG += c++11 testcase 

SOURCES += src/tetromino.cpp src/board.cpp tests/*.cpp
HEADERS += src/tetromino.h src/board.h tests/*.h
RESOURCES += tetris.qrc
