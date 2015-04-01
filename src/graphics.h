#ifndef TETRIS_UI_H
#define TETRIS_UI_H

#include "board.h"
#include <memory>

class Tetris_UI {
    
public:
    // Render current board state
    virtual void draw_board(Board &board) = 0;
};


std::unique_ptr<Tetris_UI> createQT_UI();


#endif //TETTRIS_UI_H
