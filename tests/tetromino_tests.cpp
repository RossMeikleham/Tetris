#include "tetromino_tests.h"

#include "../src/tetromino.h"


void TetrominoTests::descend() {
    int x = 4;
    int n = 6;
    size_t correct_block_count = 4;

    TetrominoFactory tf(x);
    auto t = tf.createRandomTetromino();

    auto before_blocks = t->getBlocks();
    QCOMPARE(before_blocks.size(), correct_block_count); // Check we have 4 blocks
    
   
    for (int i = 0; i < n; i++) {
        t->descend();
    }

    auto after_blocks = t->getBlocks();
    QCOMPARE(after_blocks.size(), correct_block_count);

    for (size_t i = 0; i < after_blocks.size(); i++) {
        QCOMPARE(before_blocks[i].x, after_blocks[i].x); // Check x position is the same
        QCOMPARE(before_blocks[i].y + n, after_blocks[i].y);
    }
}

     
void TetrominoTests::moveLeft() {
    int x = 9;
    int n = 3;
    size_t correct_block_count = 4;

    TetrominoFactory tf(x);
    auto t = tf.createRandomTetromino();

    auto before_blocks = t->getBlocks();
    QCOMPARE(before_blocks.size(), correct_block_count); // Check we have 4 blocks
    
   
    for (int i = 0; i < n; i++) {
        t->moveLeft();
    }

    auto after_blocks = t->getBlocks();
    QCOMPARE(after_blocks.size(), correct_block_count);

    for (size_t i = 0; i < after_blocks.size(); i++) {
        QCOMPARE(before_blocks[i].y, after_blocks[i].y); // Check y position is the same
        QCOMPARE(before_blocks[i].x - n, after_blocks[i].x);
    }

}
    
void TetrominoTests::moveRight() {
    int x = 1;
    int n = 1;
    size_t correct_block_count = 4;

    TetrominoFactory tf(x);
    auto t = tf.createRandomTetromino();

    auto before_blocks = t->getBlocks();
    QCOMPARE(before_blocks.size(), correct_block_count); // Check we have 4 blocks
    
   
    for (int i = 0; i < n; i++) {
        t->moveRight();
    }

    auto after_blocks = t->getBlocks();
    QCOMPARE(after_blocks.size(), correct_block_count);

    for (size_t i = 0; i < after_blocks.size(); i++) {
        QCOMPARE(before_blocks[i].y, after_blocks[i].y); // Check y position is the same
        QCOMPARE(before_blocks[i].x + n, after_blocks[i].x);
    }

}
    
void TetrominoTests::lowestPos() {
    int x = 9;
    int n = 3;

    I_Tetromino t(x);

    for (int i = 0; i < n; i++) {
        t.descend();
    }

    auto blocks = t.getBlocks();

    int min = blocks[0].y;
    for (size_t i = 0; i < blocks.size(); i++) {
        if (min > blocks[i].y) {
            min = blocks[i].y;
        }
    }
    
    QCOMPARE(min, t.lowestPos());
}


