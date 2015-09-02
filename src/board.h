#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include <QObject>

#include "tetromino.h"

class Board : public QObject {
    Q_OBJECT
    Q_PROPERTY(int width READ width)
    Q_PROPERTY(int height READ height)

protected:
    int m_width;
    int m_height;
    std::vector<std::vector<bool>> state; //Each vector represents the state of a row

public:
    Board(int w, int h, QObject *parent = 0);

    // Clear rows which are full and returns number of rows filled
    Q_INVOKABLE int clearRows();
   
    // Insert a single block in the specified position 
    void insert(int w, int h);

    // Check if a position on the board has been filled by a block
    Q_INVOKABLE bool isFilled(int w, int h);

    void print_board();

    void fill_row(int row);

    // Get board dimensions
    int width();
    int height();
};

#endif //BOARD_H
