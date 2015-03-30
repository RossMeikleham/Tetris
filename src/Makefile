CC=g++
CPPFLAGS=-c -std=c++11 -W -Wall

all: board tetromino
	$(CC) -o tetris board.o tetromino.o

board: board.o
	$(CC) $(CPPFLAGS) board.cpp 

tetromino: tetromino.o
	$(CC) $(CPPFLAGS) tetromino.cpp
