#include "tetromino.h"

#include <random>
#include <memory>
#include <algorithm>

using namespace std;

// Move the tetromino 1 Y coordinate down
void Tetromino::descend() {
    for (auto &block : blocks) {
        block.y++;
    }

}

void Tetromino::moveLeft() {
    for (auto &block : blocks) {
        block.x--;
    }
}

void Tetromino::moveRight() {
    for (auto &block : blocks) {
        block.x++;
    }
}


/* Return the lowest y position of the tetromino 
 * i.e. the position with the largest y value */ 
int Tetromino::lowestPos() const {    

    auto pos = *std::max_element(blocks.begin(), blocks.end(), [](const Pos &b1, const Pos &b2) {
            return b1.y < b2.y;
        });
    
    return pos.y;
}

// Returns coordinates of all 4 pieces in the tetromino
std::vector<Pos> Tetromino::getBlocks() const {
    return blocks; 
}
   

/**** I Tetronimo ****/ 

I_Tetromino::I_Tetromino(int top_left_x) {
    blocks = {{top_left_x, 0},
              {top_left_x, 1},
              {top_left_x, 2},
              {top_left_x, 3}
            };
}

void I_Tetromino::rotateLeft() {
}

void I_Tetromino::rotateRight() {}   


/**** O Tetronimo ****/ 

O_Tetromino::O_Tetromino(int top_left_x) {
    blocks = {{top_left_x - 1, 0},
              {top_left_x + 0, 0},
              {top_left_x + 1, 0},
              {top_left_x + 2, 0}
            };
}

// O Tetronimo does not rotate
void O_Tetromino::rotateLeft() {}
void O_Tetromino::rotateRight() {}   



/**** T Tetronimo ****/ 

T_Tetromino::T_Tetromino(int top_left_x) {
    blocks = {{top_left_x + 0, 0},
              {top_left_x - 1, 1},
              {top_left_x + 0, 1},
              {top_left_x + 1, 1}
            };
}

void T_Tetromino::rotateLeft() {}
void T_Tetromino::rotateRight() {}   


/**** S Tetronimo ****/ 

S_Tetromino::S_Tetromino(int top_left_x) {
    blocks = {{top_left_x + 0, 0},
              {top_left_x + 1, 0},
              {top_left_x - 1, 1},
              {top_left_x + 0, 1}
            };
}

void S_Tetromino::rotateLeft() {}
void S_Tetromino::rotateRight() {}   



/**** Z Tetronimo ****/ 

Z_Tetromino::Z_Tetromino(int top_left_x) {
    blocks = {{top_left_x - 1, 0},
              {top_left_x + 0, 0},
              {top_left_x + 0, 1},
              {top_left_x + 1, 1}
            };
}

// Rotations for the O tetromino doesn't change its position
void Z_Tetromino::rotateLeft() {}
void Z_Tetromino::rotateRight() {}   



/**** J Tetronimo ****/ 

J_Tetromino::J_Tetromino(int top_left_x) {
    blocks = {{top_left_x - 1, 0},
              {top_left_x + 0, 0},
              {top_left_x + 1, 0},
              {top_left_x + 1, 1}
            };
}

void J_Tetromino::rotateLeft() {}
void J_Tetromino::rotateRight() {}   


/**** L Tetronimo ****/ 

L_Tetromino::L_Tetromino(int top_left_x) {
    blocks = {{top_left_x - 1, 1},
              {top_left_x + 0, 1},
              {top_left_x + 1, 1},
              {top_left_x + 1, 0}
            };
}

void L_Tetromino::rotateLeft() {}
void L_Tetromino::rotateRight() {}   


/**** Tetromino Factory ****/

TetrominoFactory::TetrominoFactory(int top_left_x, QObject *parent) :
    QObject(parent),
    x(top_left_x),
    dis(std::uniform_int_distribution<>(0, 6)) {}

TetrominoFactory::TetrominoFactory(QObject *parent) : TetrominoFactory(0, parent) {}


/* Create a random tetromino, returns a unique pointer
   to a random new tetromino */
Tetromino *TetrominoFactory::createRandomTetromino() {
    
    int n = this->dis(this->generator); 
    
    /* Create Tetromino relating to the randomly
       generated number */
    switch (n) {
        case 0: return new I_Tetromino(this->x); 
        case 1: return new O_Tetromino(this->x); 
        case 2: return new T_Tetromino(this->x); 
        case 3: return new S_Tetromino(this->x); 
        case 4: return new Z_Tetromino(this->x); 
        case 5: return new J_Tetromino(this->x); 
        case 6: return new L_Tetromino(this->x); 
    }

    return NULL;
}


