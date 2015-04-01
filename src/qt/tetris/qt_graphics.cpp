#include "mainwindow.h"
#include "../../graphics.h"
#include <QApplication>
#include "qt_graphics.h"


char *argv[] = {};
int argc = 0;


class QT_Vars {
public:
    QApplication a;
    MainWindow w;
    QT_Vars();
    ~QT_Vars();
};

QT_Vars::QT_Vars() : a(argc, argv) {}

QT_Vars::~QT_Vars() {}


QT_Tetris_UI::QT_Tetris_UI() : qt_vars(new QT_Vars()) {
    //qt_vars->w.show();
    //qt_vars->a.exec();
}


void QT_Tetris_UI::draw_board(Board &board) {

}
