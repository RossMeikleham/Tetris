CC=g++
CPPFLAGS=-c -std=c++11 -W -Wall
QT_UI_DIR=qt/tetris
#QT_UI_OBJECTS= $(wildcard $(QT_UI_DIR)/*.o)
LIBS=$(SUBLIBS) -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread 

all: board tetromino graphics game
	cd $(QT_UI_DIR); \
		qmake; \
		make
	
	$(CC) -o tetris board.o tetromino.o game.o graphics.o $(QT_UI_DIR)/libtetris.a $(LIBS) 

graphics: graphics.o
	$(CC) $(CPPFLAGS) graphics.cpp 

game: game.o
	$(CC) $(CPPFLAGS) game.cpp

board: board.o
	$(CC) $(CPPFLAGS) board.cpp 

tetromino: tetromino.o
	$(CC) $(CPPFLAGS) tetromino.cpp
