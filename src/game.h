#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "tetromino.h"

class Game {

protected:
    TetrominoFactory tFactory;
    Board board;
    int score;

    bool isCollision(Tetromino *t);

public:
    Game();
    
    void gameLoop();


};

#endif //GAME_H
