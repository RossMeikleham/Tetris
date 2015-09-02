#ifndef TETROMINO_H
#define TETROMINO_H

#include <boost/fusion/adapted/std_tuple.hpp>
#include <random>
#include <memory>

#include <QObject>

#define X_INDEX 0
#define Y_INDEX 1
#define TETROMINO_BLOCKS 4

typedef struct {
    int y;
    int x;
} Pos;


// Details of Tetronimo pieces 
class Tetromino : public QObject {
    Q_OBJECT

protected: 
    std::vector<Pos> blocks; //Coordinates of all blocks in the tetromino

public:   
   
   // Move the tetromino 1 Y coordinate down
   Q_INVOKABLE void descend();

   // Return the lowest Y position of the tetromino 
   int lowestPos() const;

   // Returns coordinates of all 4 pieces in the tetromino
   std::vector<Pos> getBlocks() const;

   // Move the tetromino 1 block to the left
   Q_INVOKABLE void moveLeft();

   // Move the tetromino 1 block to the right
   Q_INVOKABLE void moveRight();
   
   // Rotate the tetronimo 90 degrees anticlockwise 
   Q_INVOKABLE virtual void rotateLeft () = 0;
   
   // Rotate the tetronimo 90 degrees clockwise 
   Q_INVOKABLE virtual void rotateRight() = 0; 

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


class TetrominoFactory : public QObject{
    Q_OBJECT


protected:
    int x;
    std::uniform_int_distribution<int> dis;
    std::default_random_engine generator;

public:
    TetrominoFactory(int top_left_x, QObject *parent = 0);
    TetrominoFactory(QObject *parent = 0);
    Q_INVOKABLE Tetromino *createRandomTetromino();
};

#endif /* TETROMINO_H */




