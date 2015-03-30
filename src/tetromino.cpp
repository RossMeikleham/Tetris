#include "tetromino.h"

#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <random>
#include <memory>

using namespace std;

// Move the tetromino 1 Y coordinate down
void Tetromino::descend() {
    boost::fusion::for_each(this->blocks, [](Pos &pos) {
        get<Y_INDEX>(pos) +=1;
    });
}

/* Return the lowest y position of the tetromino 
 * i.e. the position with the largest y value */ 
int Tetromino::lowestPos() {    
    int max = 0;
    
    boost::fusion::for_each(this->blocks, [&](Pos &pos) {
        int y_pos = get<Y_INDEX>(pos);
        if (y_pos > max) {
            max = y_pos;
        } 
    });

    return max;
}

// Returns coordinates of all 4 pieces in the tetromino
Blocks Tetromino::getBlocks() {
    return blocks; 
}
   

/**** I Tetronimo ****/ 

I_Tetromino::I_Tetromino(int top_left_x) {
    blocks = make_tuple(make_tuple(top_left_x, 0),
                        make_tuple(top_left_x, 1),
                        make_tuple(top_left_x, 2),
                        make_tuple(top_left_x, 3)
                       );
}

void I_Tetromino::rotateLeft() {
}

void I_Tetromino::rotateRight() {}   


/**** O Tetronimo ****/ 

O_Tetromino::O_Tetromino(int top_left_x) {
    blocks = make_tuple(make_tuple(top_left_x - 1, 0),
                        make_tuple(top_left_x, 0),
                        make_tuple(top_left_x + 1, 0),
                        make_tuple(top_left_x + 2, 0)
                       );
}

// O Tetronimo does not rotate
void O_Tetromino::rotateLeft() {}
void O_Tetromino::rotateRight() {}   



/**** T Tetronimo ****/ 

T_Tetromino::T_Tetromino(int top_left_x) {
    blocks = make_tuple(make_tuple(top_left_x, 0),
                        make_tuple(top_left_x - 1, 1),
                        make_tuple(top_left_x, 1),
                        make_tuple(top_left_x + 1, 1)
                       );
}

void T_Tetromino::rotateLeft() {}
void T_Tetromino::rotateRight() {}   


/**** S Tetronimo ****/ 

S_Tetromino::S_Tetromino(int top_left_x) {
    blocks = make_tuple(make_tuple(top_left_x, 0),
                        make_tuple(top_left_x + 1, 0),
                        make_tuple(top_left_x - 1, 1),
                        make_tuple(top_left_x, 1)
                       );
}

void S_Tetromino::rotateLeft() {}
void S_Tetromino::rotateRight() {}   



/**** Z Tetronimo ****/ 

Z_Tetromino::Z_Tetromino(int top_left_x) {
    blocks = make_tuple(make_tuple(top_left_x - 1, 0),
                        make_tuple(top_left_x, 0),
                        make_tuple(top_left_x, 1),
                        make_tuple(top_left_x + 1, 1)
                       );
}

// Rotations for the O tetromino doesn't change its position
void Z_Tetromino::rotateLeft() {}
void Z_Tetromino::rotateRight() {}   



/**** J Tetronimo ****/ 

J_Tetromino::J_Tetromino(int top_left_x) {
    blocks = make_tuple(make_tuple(top_left_x - 1, 0),
                        make_tuple(top_left_x, 0),
                        make_tuple(top_left_x + 1, 0),
                        make_tuple(top_left_x + 1, 1)
                       );
}

void J_Tetromino::rotateLeft() {}
void J_Tetromino::rotateRight() {}   


/**** L Tetronimo ****/ 

L_Tetromino::L_Tetromino(int top_left_x) {
    blocks = make_tuple(make_tuple(top_left_x - 1, 0),
                        make_tuple(top_left_x, 0),
                        make_tuple(top_left_x + 1, 1),
                        make_tuple(top_left_x -1, 1)
                       );
}

void L_Tetromino::rotateLeft() {}
void L_Tetromino::rotateRight() {}   


/**** Tetromino Factory ****/

TetrominoFactory::TetrominoFactory(int top_left_x) {
    dis = uniform_int_distribution<>(0, 6);
    x = top_left_x;
}


/* Create a random tetromino, returns a unique pointer
   to a random new tetromino */
std::unique_ptr<Tetromino> TetrominoFactory::createRandomTetromino() {
    
    std::unique_ptr<Tetromino> t;
    int n = this->dis(this->generator); 
    
    /* Create Tetromino relating to the randomly
       generated number */
    switch (n) {
        case 0: t.reset(new I_Tetromino(this->x)); break; 
        case 1: t.reset(new O_Tetromino(this->x)); break; 
        case 2: t.reset(new T_Tetromino(this->x)); break;
        case 3: t.reset(new S_Tetromino(this->x)); break;
        case 4: t.reset(new Z_Tetromino(this->x)); break;
        case 5: t.reset(new J_Tetromino(this->x)); break;
        case 6: t.reset(new L_Tetromino(this->x)); break;
    }
    
    return t;
}


