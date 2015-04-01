CC=g++
CPPFLAGS=-c -std=c++11 -W -Wall

all: board tetromino graphics game 
	$(CC) -o tetris board.o tetromino.o game.o graphics.o

graphics: graphics.o
	$(CC) $(CPPFLAGS) graphics.cpp

game: game.o
	$(CC) $(CPPFLAGS) game.cpp

board: board.o
	$(CC) $(CPPFLAGS) board.cpp 

tetromino: tetromino.o
	$(CC) $(CPPFLAGS) tetromino.cpp
