/**
 * @file piece.h
 * @author teamname: The QT's
 *
 * @brief
 * CS 3505
 * Assignment Name: A9-An-Educational-App
 *
 * The piece class defines various types of chess pieces, their properties, and movement rules.
 * It is used to create and manage individual chess pieces on the game board.
 *
 * @date 2023-12-08
 */
#ifndef PIECE_H
#define PIECE_H

#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <cstdlib>

class Piece : public QObject
{
    Q_OBJECT
public:
    enum PieceType
    {
        WHITE_KING,
        WHITE_QUEEN,
        WHITE_ROOK,
        WHITE_BISHOP,
        WHITE_KNIGHT,
        WHITE_PAWN,
        BLACK_KING,
        BLACK_QUEEN,
        BLACK_ROOK,
        BLACK_BISHOP,
        BLACK_KNIGHT,
        BLACK_PAWN
    };

    explicit Piece(PieceType, bool newPawn = false, QObject *parent = nullptr);
    PieceType pieceType;
    QPixmap pieceImage;
    QLabel *pieceLabel;
    bool freshPawn;

    /**
     * @brief Sets the chess piece on a QPushButton.
     * @param button The QPushButton on which to set the piece.
     */
    void setPiece(QPushButton*);

    /**
     * @brief Hides the chess piece.
     */
    void hide();

    /**
     * @brief Shows the chess piece.
     */
    void show();

    /**
     * @brief Checks if a chess piece is white.
     * @param piece The chess piece to be checked.
     * @return True if the piece is white, false otherwise.
     */
    bool whitePiece(Piece*);

    /**
     * @brief Retrieves possible locations for the chess piece's movement.
     * @param currentPosition The current position of the chess piece.
     * @param occupiedLocations A hash containing occupied locations on the board.
     * @return A list of possible locations for movement.
     */
    QList<QPair<int, int>> getPossibleLocations(QPair<int, int>, QHash<QPair<int, int>, Piece*>);

private:
    /**
     * @brief checkInbounds tells if a given location is in bounds
     * @return True if a location is in bounds and false otherwise
     */
    bool checkInbounds(int, int);

    /**
     * @brief blackPiece tells if a given piece is a black piece
     * @return True if piece is black and false otherwise
     */
    bool blackPiece(Piece*);

    /**
     * @brief checkPiece check if new location is valid and add to valid locations if it is
     * @return true if a location was added
     */
    bool checkPiece(int, int, bool, QHash<QPair<int, int>, Piece*>, QList<QPair<int, int>>&);

    /**
     * @brief rookMoves loop through all locations a rook can access, horizontal and vertical
     */
    void rookMoves(bool, QPair<int,int>, QHash<QPair<int, int>, Piece*>, QList<QPair<int, int>>&);

    /**
     * @brief bishopMoves loop through all locations a bishop can access, diagonals
     */
    void bishopMoves(bool, QPair<int,int>, QHash<QPair<int, int>, Piece*>, QList<QPair<int, int>>&);

    /**
     * @brief knightMoves loop through all locations a knight can access, L's
     */
    void knightMoves(bool, QPair<int,int>, QHash<QPair<int, int>, Piece*>, QList<QPair<int, int>>&);

    /**
     * @brief kingMoves loop through all locations a king can access, 1 square away
     */
    void kingMoves(bool, QPair<int,int>, QHash<QPair<int, int>, Piece*>, QList<QPair<int, int>>&);

    /**
     * @brief pawnMoves check through all locations a pawn can access, 1 or 2 forward/diagonal captures
     */
    void pawnMoves(bool, QPair<int,int>, QHash<QPair<int, int>, Piece*>, QList<QPair<int, int>>&);

};

#endif // PIECE_H
