

#include <vector>
#include "tetromino.h"

using namespace std;

class Board {

protected:
    int width;
    int height;
    vector<bool> *state;

public:
    Board(int w, int h);

    // Destory rows which are full and returns number of rows filled
    int eliminateRows();
    
    void insert(int w, int h);

    void print_board();

    void fill_row(int row);
};
