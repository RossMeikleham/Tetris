#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "tetromino.h"

using namespace std;

class Board {

protected:
    int width;
    int height;
    vector<bool> *state; //Each vector represents the state of a row

public:
    Board(int w, int h);

    // Clear rows which are full and returns number of rows filled
    int clearRows();
   
    // Insert a single block in the specified position 
    void insert(int w, int h);

    // Check if a position on the board has been filled by a block
    bool isFilled(int w, int h);

    void print_board();

    void fill_row(int row);
};

#endif //BOARD_H
