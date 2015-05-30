

#include "game.h"
#include "board.h"
#include "tetromino.h"
#include "graphics.h"
#include <boost/fusion/algorithm/iteration/fold.hpp>
#include <boost/fusion/include/fold.hpp>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 22

Game::Game() : tFactory(BOARD_WIDTH/2), board(BOARD_WIDTH, BOARD_HEIGHT)  {
    score = 0;
}


bool Game::isCollision(std::unique_ptr<Tetromino> const &t) {
   
 // Trying to get boost/fusion fold to fold over tuple but doesn't
 // seem to be working, so use macro hack
 Blocks blocks = t->getBlocks();
 #define isFilled(I) (this->board.isFilled(get<X_INDEX>(get<I>(blocks)), get<Y_INDEX>(get<I>(blocks)))) 
 return isFilled(0) || isFilled(1) || isFilled(2) || isFilled(3);
 #undef isFilled
}


void Game::gameLoop() {

    bool game_over = false;
    while (!game_over) {
        auto t = tFactory.createRandomTetromino();
        // If immediate collision for initial position then gameover
        if (this->isCollision(t)) {
            game_over = true;
        } else {
            bool block_placed = false;
            while (!block_placed) {
                Blocks current_pos = t->getBlocks();
            
            }
        } 
    }

}


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
}


