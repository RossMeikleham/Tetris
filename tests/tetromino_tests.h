#ifndef TETROMINO_TESTS
#define TETROMINO_TESTS

// Unit Tests for the Tetromino class and subclasses

#include <QObject>
#include <QtTest/QtTest>

class TetrominoTests : public QObject {
  Q_OBJECT

private slots:
    //Check descending a tetromino correctly modifies the position
    void descend();
    // Check moving a tetromino left correctly modifies the position
    void moveLeft();
    // Check moving the tetromino right correctly modifies the position
    void moveRight();
    // Check that the calculation of the lowest position of the tetromino is correct
    void lowestPos();
};

#endif
