#ifndef QT_GRAPHICS_H
#define QT_GRAPHICS_H

#include "../../graphics.h"
#include "../../board.h"

class QT_Vars;

class QT_Tetris_UI : public Tetris_UI {

public:
    QT_Tetris_UI();
    ~QT_Tetris_UI();
    void draw_board(Board &board);

private:
    std::unique_ptr<QT_Vars> qt_vars;

};

#endif // QT_GRAPHICS_H

