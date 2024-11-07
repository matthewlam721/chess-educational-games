/**
 * @file puzzle.h
 * @author teamname: The QT's
 *
 * @brief
 * CS 3505
 * Assignment Name: A9-An-Educational-App
 *
 * The puzzle class sets up puzzles in the application and allows users to interact with puzzles.
 *
 * @date 2023-12-08
 */
#ifndef PUZZLE_H
#define PUZZLE_H

#include "piece.h"
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

class Puzzle : public QWidget
{
    Q_OBJECT
public:
    enum PuzzleType
    {
        Puzzle1,
        Puzzle2,
        Puzzle3,
        Puzzle4,
        Puzzle5,
        Puzzle6
    };

    explicit Puzzle(QWidget *parent = nullptr);

    explicit Puzzle(PuzzleType, QWidget *parent = nullptr);
    PuzzleType puzzleType;


private:
    Piece* selectedPiece;

    QHash<QPair<int, int>, Piece::PieceType> boardSetUp;

    /**
     * @brief Map to keep track which pieces on the board the player is playing with.
     */
    QHash<QPair<int, int>, Piece::PieceType> playerPieces;

    /**
     * @brief Map to keep track of the actual pieces held in occupied spaces.
     */
    QHash<QPair<int, int>, Piece*> piecePositions;

    /**
     * @brief Contains the correct sequence of user clicks to complete a puzzle. Used to
     * track puzzle progress.
     */
    QList<QPair<int, int>> correctClickSequence;

    /**
     * @brief Holds the current index the user is at in the correct click sequence.
     */
    int currSequenceIndex;

    /**
     * @brief Holds the list of moves the computer must make.
     */
    QList<QPair<int, int>> computerMoves;

    int computerMovesIndex;

    /**
     * @brief Holds the potential valid move locations for the currently selected piece.
     */
    QList<QPair<int, int>> potentialLocations;

    /**
     * @brief Holds the coordinates of the pieces. Saves this information on a selecting click so the
     * proceeding moving click can caluclate valid moves based on that position.
     */
    QPair<int, int> selectedPiecePos;

    QList<QPushButton*> allButtons;

    /**
     * @brief Displays feedback on whether a correct or incorrect move was made.
     */
    QLabel* feedbackLabel;

    QPushButton* helpButton;
    QLabel* revealedMove;
    QLabel* WhosTurnLabel;

    bool correctMove;
    bool selecting;
    bool moving;

    QGridLayout *layout;

    QList<PuzzleType> completedPuzzles;

    /**
     * @brief Creates the puzzle page.
     */
    void createBoard();

    /**
     * @brief Sets a chess piece on a QPushButton with specific coordinate.
     * @param space The QPushButton with specific coordinate
     * @param piece The chess piece to set.
     */
    void setPiece(QPushButton *space, Piece*);

    /**
     * @brief Sets the background color of a button.
     * @param row The row of the button.
     * @param col The column of the button.
     * @param color The color to be set.
     */
    void setButtonBackgroundColor(int row, int col, QString color);

    // Set up the puzzles
    /**
     * @brief Puzzle::setUpPuzzle1
     * This method sets up the chess board and moves for a fork puzzle.
     */
    void setUpPuzzle1();

    /**
     * @brief Puzzle::setUpPuzzle2
     * This method sets up the chess board and moves for a pinned queen puzzle.
     * the puzzle came from
     * "https://www.google.com/search?q=pinned+queen+puzzles+chess&rlz=1C1CHBF_enUS1043US1043&oq=pinned+&gs_lcrp=EgZjaHJvbWUqCAgAEEUYJxg7MggIABBFGCcYOzIGCAEQRRhAMgYIAhBFGDkyBwgDEAAYgAQyBwgEEAAYgAQyBwgFEAAYgAQyBwgGEAAYgAQyBwgHEAAYgATSAQgxNDU0ajFqOagCALACAA&sourceid=chrome&ie=UTF-8#fpstate=ive&vld=cid:d30812a0,vid:XIlYJjRLc_A,st:0"
     */
    void setUpPuzzle2();

    /**
     * @brief Puzzle::setUpPuzzle3
     * this method sets up the chess board for a smother mate puzzle
     * got the puzzle from "https://lichess.org/study/oJ4jLe50/iGOCuCaa" - Sveshnikov - Ivanov, 1976
     */
    void setUpPuzzle3();

    /**
     * @brief Puzzle::setUpPuzzle4
     * this method sets up the chess board for a overloading puzzle
     */
    void setUpPuzzle4();

    /**
     * @brief Puzzle::setUpPuzzle5
     * Control opponent king to take out important pieces.
     */
    void setUpPuzzle5();

    /**
     * @brief Puzzle::setUpPuzzle6
     * use forking and pinning to take out important pieces.
     */
    void setUpPuzzle6();

    /**
     * @brief Get the title of the puzzle.
     * @return The puzzle title.
     */
    QString getPuzzleTitle();

    /**
     * @brief Sets up player's chess (white) pieces for the puzzle.
     */
    void setPlayerPieces();

    /**
     * @brief Resets the puzzle board.
     */
    void resetBoard();

    /**
     * @brief Handles the next move in the puzzle.
     */
    void nextMove();

    /**
     * @brief Saves the current game progress.
     */
    void savePuzzle();

signals:
    /**
     * @brief Emit signal when the "Go Back" button is clicked.
     */
    void goBackButtonClicked();

    /**
     * @brief Emit signal when a puzzle is completed.
     * @param puzzleIndex The index of the completed puzzle.
     */
    void puzzleComplete(int);

    /**
     * @brief Emit signal when the puzzle is loaded.
     * @param puzzleIndex The index of the loaded puzzle.
     */
    void fileLoaded(int);

public slots:
    /**
     * @brief Handles the selection of a chess space.
     */
    void selectSpace();

    /**
     * @brief Handles the "Go Back" button click.
     */
    void onGoBackButtonClicked();

    /**
     * @brief Handles the "Help" button click.
     */
    void onHelpButtonClicked();

    /**
     * @brief Loads a puzzle.
     */
    void loadPuzzle();

};

#endif // PUZZLE_H
