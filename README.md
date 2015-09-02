# Tetris
Simple Tetris Clone in C++14 using the Qt framework.

[![Build Status](https://travis-ci.org/RossMeikleham/Tetris.svg?branch=master)](https://travis-ci.org/RossMeikleham/Tetris)

#Instructions


###Required:
- Qt 5.4 or above
- Compiler with C++14 features (gcc 5.1+, clang 3.4+, VC2015+)

###Building:

- Open the `tetris.pro` file in Qt Creator, run qmake and then build/run
- Alternatively from OSX/*Nix run `qmake tetris.pro` from the command line and then `make`
  to produce the binary

###Running Unit Tests

- Open the `tetris_tests.pro` file in Qt Creator, run `qmake tetris_tests.pro` and then build/run
- Alternatively from OSX/*Nix run `qmake tetris_tests.pro` from the command line and then `make`
  to produce the binary


# TODO
- Game Event Loop
- Tetromino Rotations
- Complete UI
- Compile to Android
