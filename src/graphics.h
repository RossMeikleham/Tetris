#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "board.h"

class Graphics {
    
public:
    Graphics();


    // Render current board state
    void draw_board(Board &board);
};

#endif //GRAPHICS_H
