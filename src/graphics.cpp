
#include "graphics.h"
#include "qt/tetris/qt_graphics.h"

std::unique_ptr<Tetris_UI> createQT_UI() {
    std::unique_ptr<Tetris_UI> t(new QT_Tetris_UI);
    return t;
};

