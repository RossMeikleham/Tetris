

#include "game.h"
#include "board.h"
#include "tetromino.h"
#include "graphics.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 22

Game::Game() : tFactory(BOARD_WIDTH/2), board(BOARD_WIDTH, BOARD_HEIGHT)  {
    score = 0;
}


bool Game::isCollision(Tetromino *t) {
   return false; 
}

void Game::gameLoop() {

    bool game_over = false;
    while (!game_over) {
        bool block_placed = false;
        auto t = tFactory.createRandomTetromino();
//        if collision then gameover

        while (!block_placed) {
            
        }
    
    }

}


int main() {
    Board board {8, 20};
    board.print_board();
    board.fill_row(3);
    board.print_board();
    board.eliminateRows();
    board.print_board();
    return 0;
}


