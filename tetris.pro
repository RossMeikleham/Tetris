TEMPLATE = app

CXX = $$(CXX)
isEmpty(CXX) {
  CXX = "g++"   
}

QMAKE_CXX = $${CXX}
QMAKE_CXX_FLAGS += std=c++14

QT += quick qml widgets
TARGET = tetris
CONFIG +=

SOURCES += src/*.cpp
HEADERS += src/*.h
RESOURCES += tetris.qrc
