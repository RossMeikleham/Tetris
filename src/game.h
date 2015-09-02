#ifndef GAME_H
#define GAME_H

#include <QObject>

#include "board.h"
#include "tetromino.h"

class Game : public QObject {

protected:
    TetrominoFactory tFactory;
    Board board;
    int score;

    bool isCollision(Tetromino const &t);

public:
    Game();
    
    void gameLoop();


};

#endif //GAME_H
