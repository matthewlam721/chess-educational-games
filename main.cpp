/**
 * @file main.cpp
 * @author teamname: The QT's
 *
 * @brief
 * CS 3505
 * Assignment Name: A9-An-Educational-App
 *
 * The application teaches tricks about chess and have puzzles for users to pratice related tricks.
 *
 * @date 2023-12-08
 */
#include "chess.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chess w;
    w.show();
    return a.exec();
}
