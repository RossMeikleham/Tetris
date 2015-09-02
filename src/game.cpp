#include "game.h"

#include <numeric>

#include "board.h"
#include "tetromino.h"


#define BOARD_WIDTH 10
#define BOARD_HEIGHT 22

using namespace std;

Game::Game() : tFactory(BOARD_WIDTH/2), board(BOARD_WIDTH, BOARD_HEIGHT)  {
    score = 0;
}


bool Game::isCollision(Tetromino const &t) {
   
 auto blocks = t.getBlocks();
 return accumulate(blocks.begin(), blocks.end(), false, [&](bool const &b, auto const &block) {
        return b || this->board.isFilled(block.x, block.y);
     });
}


void Game::gameLoop() {

    bool game_over = false;
    while (!game_over) {
        Tetromino *t = tFactory.createRandomTetromino();
        // If immediate collision for initial position then gameover
        if (this->isCollision(*t)) {
            game_over = true;
        } else {
            bool block_placed = false;
            while (!block_placed) {
                auto current_pos = t->getBlocks();
            
            }
        } 
        free(t);
    }

}


/*  
int main() {
    Board board {8, 20};
    board.print_board();
    board.fill_row(3);
    board.print_board();
    board.clearRows();
    board.print_board();
    
    TetrominoFactory tFactory = TetrominoFactory(0);
    auto t = tFactory.createRandomTetromino();
    Blocks current_pos = t->getBlocks();
    t->descend();
    Blocks new_pos = t->getBlocks();

    //Check descending works
    printf("old y0 %d. new y0 %d\n", get<X_INDEX>(get<0>(current_pos)), get<Y_INDEX>(get<0>(new_pos)));
    return 0;
}*/


