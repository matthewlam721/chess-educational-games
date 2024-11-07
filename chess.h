/**
 * @file chess.h
 * @author teamname: The QT's
 *
 * @brief
 * CS 3505
 * Assignment Name: A9-An-Educational-App
 *
 * The chess class is reponsible for overall view of the application.
 *
 * @date 2023-12-08
 */
#ifndef CHESS_H
#define CHESS_H

#include "QtWidgets/qmessagebox.h"
#include <QMainWindow>
#include <QHBoxLayout>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui { class Chess; }
QT_END_NAMESPACE

class Chess : public QMainWindow
{
    Q_OBJECT

public:
    Chess(QWidget *parent = nullptr);
    ~Chess();

public slots:
    /**
     * @brief Handles the loading of puzzles completed previously.
     * @param puzzleIndex The index states which puzzle is completed
     */
    void loadCompletedPuzzle(int);

private:
    Ui::Chess *ui;
    /**
     * @brief Shows the starting screen.
     */
    void startGame();

    // Loads the specfic lesson / puzle
    void lesson1();
    void puzzle1();

    void lesson2();
    void puzzle2();

    void lesson3();
    void puzzle3();

    void lesson4();
    void puzzle4();

    void lesson5();
    void puzzle5();

    void lesson6();
    void puzzle6();

    /**
     * @brief Enables a specific puzzle after related lesson is completed.
     * @param puzzleIndex The index of the puzzle to enable.
     */
    void enablePuzzle(int);

    /**
     * @brief Marks a puzzle as completed.
     * @param puzzleIndex The index of the completed puzzle.
     */
    void completePuzzle(int);

    // Reponsible for the message box on the celebration screen
    QMessageBox celebrationPopUpBox;
    QPushButton *celebrationPopUpOk;
    QPushButton *celebrationGoBackMenu;

    /**
     * @brief Displays the celebration screen.
     */
    void showCelebrationScreen();

signals:
    /**
     * @brief Signal emitted when a puzzle is completed.
     */
    void completePuzzleSignal();

};
#endif // CHESS_H
