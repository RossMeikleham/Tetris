TEMPLATE = app

CXX = $$(CXX)
isEmpty(CXX) {
  CXX = "g++"   
}

QMAKE_CXX = $${CXX}
QMAKE_CXXFLAGS += -std=c++14

QT += quick qml widgets testlib
TARGET = tetris_tests

CONFIG += testcase 

SOURCES += src/tetromino.cpp src/board.cpp tests/*.cpp
HEADERS += src/tetromino.h src/board.h tests/*.h
RESOURCES += tetris.qrc
