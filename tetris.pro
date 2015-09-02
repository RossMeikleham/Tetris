TEMPLATE = app

CXX = $$(CXX)
isEmpty(CXX) {
  CXX = "g++"   
}

QMAKE_CXX = $${CXX}


QT += quick qml widgets
TARGET = tetris
CONFIG += c++14

SOURCES += src/*.cpp
HEADERS += src/*.h
RESOURCES += tetris.qrc
