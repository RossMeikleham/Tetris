#include <QtTest/QtTest>
#include <iostream>

#include "tetromino_tests.h"
#include "board_tests.h"

int main(int argc, char **argv)
{

    QCoreApplication app(argc, argv); 

    int failed_suites_count = 0;
    std::vector<QObject *> tests;

    TetrominoTests tet_tests;
    tests.push_back(&tet_tests);

    BoardTests board_tests;
    tests.push_back(&board_tests);

    for (auto &test : tests) {
        int result = QTest::qExec(test);
        if (result != 0) {
            failed_suites_count++;
        }
    }
    

    return failed_suites_count;   
}

