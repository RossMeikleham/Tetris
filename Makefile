CC=g++
CPPFLAGS=-std=c++11 -W -Wall
QT_UI_DIR=src/qt/tetris
LIBS=$(SUBLIBS) -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread 
SRCDIR=src
TARGET=tetris

SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS=$(SOURCES:$(SRCDIR)/%.cpp=%.o)



all: $(OBJECTS)
	cd $(QT_UI_DIR); \
		qmake; \
		make
	
	$(CC) -o $(TARGET) $(OBJECTS) $(QT_UI_DIR)/libtetris.a $(LIBS) 

$(OBJECTS): %.o : $(SRCDIR)/%.cpp
	$(CC) -c $(CPPFLAGS) $< -o $@ 


clean:
	rm *.o
	cd $(QT_UI_DIR); \
		make clean
