#ifndef TETROMINO_H
#define TETROMINO_H

#include <boost/fusion/adapted/std_tuple.hpp>

#define X_INDEX 0
#define Y_INDEX 1

typedef std::tuple<int, int> Pos; //X and Y coordinates
typedef std::tuple<Pos, Pos, Pos, Pos> Blocks;

// Details of Tetronimo pieces 
class Tetromino {

protected: 
    Blocks blocks; //Coordinates of all blocks in the tetromino

public:   
   
   // Move the tetromino 1 Y coordinate down
   void descend();

   // Return the lowest Y position of the tetromino 
   int lowestPos();

   // Returns coordinates of all 4 pieces in the tetromino
   Blocks getBlocks();
   
   // Rotate the tetronimo 90 degrees anticlockwise 
   virtual void rotateLeft () = 0;
   
   // Rotate the tetronimo 90 degrees clockwise 
   virtual void rotateRight() = 0; 

};


class I_Tetromino: public Tetromino {
public:
    I_Tetromino(int top_left_x);
    void rotateLeft();
    void rotateRight();    
};


class O_Tetromino : public Tetromino {
public:
    O_Tetromino(int top_left_x);    
    void rotateLeft();
    void rotateRight();    
};


class T_Tetromino: public Tetromino {
public:
    T_Tetromino(int top_left_x);
    void rotateLeft();
    void rotateRight();    
};


class S_Tetromino: public Tetromino {
public:
    S_Tetromino(int top_left_x);
    void rotateLeft();
    void rotateRight();    
};


class Z_Tetromino: public Tetromino {
public:
    Z_Tetromino(int top_left_x);
    void rotateLeft();
    void rotateRight();    
};


class J_Tetromino: public Tetromino {
public:
    J_Tetromino(int top_left_x);
    void rotateLeft();
    void rotateRight();    
};


class L_Tetromino: public Tetromino {
public:
    L_Tetromino(int top_left_x);
    void rotateLeft();
    void rotateRight();    
};

#endif /* TETROMINO_H */
