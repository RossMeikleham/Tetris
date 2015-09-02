#include "board_tests.h"

#include "../src/board.h"

void BoardTests::row_insertion_valid() {
  
    int rows = 20;
    int cols = 8;
    std::vector<int> filled_rows = {0, 3, 7};

    Board board(cols, rows);

    // Check initial state
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            QCOMPARE(board.isFilled(x, y), false);
        }
    }
  
    // Fill some rows
    for (auto const &row_no : filled_rows) {
        board.fill_row(row_no);
    }


    // Check state after
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            if (std::find(filled_rows.begin(), filled_rows.end(), y) != filled_rows.end()) {
                QCOMPARE(board.isFilled(x, y), true); 
            } else {
                QCOMPARE(board.isFilled(x, y), false);
            }
        }
    }    

}

/*  
void BoardTests::row_insertion_negative();
void BoardTests::row_insertion_too_large();

void BoardTests::row_clear();

void BoardTests::insert_valid();
void BoardTests::insert_x_negative();
void BoardTests::insert_x_too_large();
void BoardTests::insert_y_negative();
void BoardTests::insert_y_too_large();
*/
