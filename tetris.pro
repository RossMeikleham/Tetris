TEMPLATE = app

CXX = $$(CXX)
isEmpty(CXX) {
  CXX = "g++"   
}

QMAKE_CXX = $${CXX}


QT += quick qml widgets
TARGET = tetris
QMAKE_CXXFLAGS += -std=c++14
CONFIG += 

SOURCES += src/*.cpp
HEADERS += src/*.h
RESOURCES += tetris.qrc
