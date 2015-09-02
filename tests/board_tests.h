#ifndef BOARD_TESTS_H
#define BOARD_TESTS_H

// Unit Tests for the Board class

#include <QObject>
#include <QtTest/QtTest>

class BoardTests : public QObject {
  Q_OBJECT

private slots:
    //Check row insertion working correctly
    void row_insertion_valid();
/*
    void row_insertion_negative();
    void row_insertion_too_large();

    // Check row clearing working correctly
    void row_clear();

    // Check inserting individual blocks works correctly
    void insert_valid();
    void insert_x_negative();
    void insert_x_too_large();
    void insert_y_negative();
    void insert_y_too_large();
*/
};

#endif
