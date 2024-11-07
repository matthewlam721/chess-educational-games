/**
 * @file piece.cpp
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
#include "piece.h"

Piece::Piece(PieceType pt, bool newPawn, QObject *parent)
    : QObject{parent},
    pieceType(pt),
    freshPawn(newPawn)
{
    if (pt == BLACK_KNIGHT) {
        pieceImage = QPixmap(":/pieces/Images/blackKnight.png");
    }

    else if (pt == BLACK_BISHOP) {
        pieceImage = QPixmap(":/pieces/Images/blackBishop.png");
    }

    else if (pt == BLACK_ROOK) {
        pieceImage = QPixmap(":/pieces/Images/blackRook.png");
    }

    else if (pt == BLACK_PAWN) {
        pieceImage = QPixmap(":/pieces/Images/blackPawn.png");
    }

    else if (pt == BLACK_KING) {
        pieceImage = QPixmap(":/pieces/Images/blackKing.png");
    }

    else if (pt == BLACK_QUEEN) {
        pieceImage = QPixmap(":/pieces/Images/blackQueen.png");
    }

    else if (pt == WHITE_KNIGHT) {
        pieceImage = QPixmap(":/pieces/Images/whiteKnight.png");
    }

    else if (pt == WHITE_BISHOP) {
        pieceImage = QPixmap(":/pieces/Images/whiteBishop.png");
    }

    else if (pt == WHITE_ROOK) {
        pieceImage = QPixmap(":/pieces/Images/whiteRook.png");
    }

    else if (pt == WHITE_PAWN) {
        pieceImage = QPixmap(":/pieces/Images/whitePawn.png");
    }

    else if (pt == WHITE_KING) {
        pieceImage = QPixmap(":/pieces/Images/whiteKing.png");
    }

    else if (pt == WHITE_QUEEN) {
        pieceImage = QPixmap(":/pieces/Images/whiteQueen.png");
    }

}

void Piece::setPiece(QPushButton *space){
    pieceLabel = new QLabel(space);
    pieceLabel->setPixmap(pieceImage);
    pieceLabel->setScaledContents(true);
    pieceLabel->setGeometry(0, 0, space->width(), space->height());
    pieceLabel->show();
}

void Piece::hide(){
    pieceLabel->hide();
}

QList<QPair<int, int>> Piece::getPossibleLocations(QPair<int,int> currLocation, QHash<QPair<int, int>, Piece*> gameBoard){
    QList<QPair<int, int>> validLocations;
    if (pieceType == BLACK_KNIGHT) {
        knightMoves(true, currLocation, gameBoard, validLocations);
    }

    else if (pieceType == WHITE_KNIGHT) {
        knightMoves(false, currLocation, gameBoard, validLocations);
    }

    else if (pieceType == BLACK_BISHOP) {
        bishopMoves(true, currLocation, gameBoard, validLocations);
    }

    else if (pieceType == WHITE_BISHOP) {
        bishopMoves(false, currLocation, gameBoard, validLocations);
    }

    else if (pieceType == BLACK_ROOK) {
        rookMoves(true, currLocation, gameBoard, validLocations);
    }

    else if (pieceType == WHITE_ROOK) {
        rookMoves(false, currLocation, gameBoard, validLocations);
    }

    else if (pieceType == BLACK_PAWN) {
        pawnMoves(true, currLocation, gameBoard, validLocations);
    }

    else if (pieceType == WHITE_PAWN) {
        pawnMoves(false, currLocation, gameBoard, validLocations);
    }

    else if (pieceType == BLACK_KING) {
        kingMoves(true, currLocation, gameBoard, validLocations);
    }

    else if (pieceType == WHITE_KING) {
        kingMoves(false, currLocation, gameBoard, validLocations);
    }

    else if (pieceType == BLACK_QUEEN) {
        rookMoves(true, currLocation, gameBoard, validLocations);
        bishopMoves(true, currLocation, gameBoard, validLocations);
    }

    else if (pieceType == WHITE_QUEEN) {
        rookMoves(false, currLocation, gameBoard, validLocations);
        bishopMoves(false, currLocation, gameBoard, validLocations);
    }
    return validLocations;
}

bool Piece::checkInbounds(int nextY, int nextX){
    if((nextY < 0) ||
       (nextY > 7) ||
       (nextX < 0) ||
       (nextX > 7)){
        return false;
    }
    return true;
}

bool Piece::whitePiece(Piece* piece){
    if(piece->pieceType == WHITE_KING||
        piece->pieceType == WHITE_QUEEN||
        piece->pieceType == WHITE_ROOK||
        piece->pieceType == WHITE_BISHOP||
        piece->pieceType == WHITE_KNIGHT||
        piece->pieceType == WHITE_PAWN){
        return true;
    }
    return false;
}

bool Piece::blackPiece(Piece* piece){
    if(piece->pieceType == BLACK_KING||
        piece->pieceType == BLACK_QUEEN||
        piece->pieceType == BLACK_ROOK||
        piece->pieceType == BLACK_BISHOP||
        piece->pieceType == BLACK_KNIGHT||
        piece->pieceType == BLACK_PAWN){
        return true;
    }
    return false;
}

bool Piece::checkPiece(int nextX, int nextY, bool black, QHash<QPair<int, int>, Piece*> gameBoard, QList<QPair<int, int>> &validLocations){
    if(checkInbounds(nextX, nextY)){
        QPair<int, int> nextLocation(nextX, nextY);
        if(gameBoard.contains(nextLocation)){
            if(black){
                if(whitePiece(gameBoard[nextLocation])){
                    validLocations.append(nextLocation);
                }
            }else{
                if(blackPiece(gameBoard[nextLocation])){
                    validLocations.append(nextLocation);
                }
            }
        }else{
            validLocations.append(nextLocation);
            return true;
        }
    }
    return false;
}

void Piece::rookMoves(bool black, QPair<int,int> currLocation, QHash<QPair<int, int>, Piece*> gameBoard, QList<QPair<int, int>> &validLocations){
    // Search Right
    int offsetX = 1;
    int offsetY = 0;
    bool clear = true;
    while(clear){
        clear = checkPiece(currLocation.first + offsetY, currLocation.second + offsetX, black, gameBoard, validLocations);
        offsetX++;
    }

    // Search Down
    offsetX = 0;
    offsetY = -1;
    clear = true;
    while(clear){
        clear = checkPiece(currLocation.first + offsetY, currLocation.second + offsetX, black, gameBoard, validLocations);
        offsetY--;
    }

    // Left
    offsetX = -1;
    offsetY = 0;
    clear = true;
    while(clear){
        clear = checkPiece(currLocation.first + offsetY, currLocation.second + offsetX, black, gameBoard, validLocations);
        offsetX--;
    }

    // Search Up
    offsetX = 0;
    offsetY = 1;
    clear = true;
    while(clear){
        clear = checkPiece(currLocation.first + offsetY, currLocation.second + offsetX, black, gameBoard, validLocations);
        offsetY++;
    }
}

void Piece::bishopMoves(bool black, QPair<int,int> currLocation, QHash<QPair<int, int>, Piece*> gameBoard, QList<QPair<int, int>> &validLocations){
    // Search Up and Right
    int offsetX = 1;
    int offsetY = 1;
    bool clear = true;
    while(clear){
        clear = checkPiece(currLocation.first + offsetY, currLocation.second + offsetX, black, gameBoard, validLocations);
        offsetX++;
        offsetY++;
    }

    // Search Down and Right
    offsetX = 1;
    offsetY = -1;
    clear = true;
    while(clear){
        clear = checkPiece(currLocation.first + offsetY, currLocation.second + offsetX, black, gameBoard, validLocations);
        offsetX++;
        offsetY--;
    }

    // Search Up and Left
    offsetX = -1;
    offsetY = 1;
    clear = true;
    while(clear){
        clear = checkPiece(currLocation.first + offsetY, currLocation.second + offsetX, black, gameBoard, validLocations);
        offsetX--;
        offsetY++;
    }

    // Search Down and Left
    offsetX = -1;
    offsetY = -1;
    clear = true;
    while(clear){
        clear = checkPiece(currLocation.first + offsetY, currLocation.second + offsetX, black, gameBoard, validLocations);
        offsetX--;
        offsetY--;
    }
}

void Piece::knightMoves(bool black, QPair<int,int> currLocation, QHash<QPair<int, int>, Piece*> gameBoard, QList<QPair<int, int>> &validLocations){
    checkPiece(currLocation.first + 2, currLocation.second + 1, black, gameBoard, validLocations);
    checkPiece(currLocation.first + 2, currLocation.second - 1, black, gameBoard, validLocations);
    checkPiece(currLocation.first - 2, currLocation.second + 1, black, gameBoard, validLocations);
    checkPiece(currLocation.first - 2, currLocation.second - 1, black, gameBoard, validLocations);
    checkPiece(currLocation.first + 1, currLocation.second + 2, black, gameBoard, validLocations);
    checkPiece(currLocation.first + 1, currLocation.second - 2, black, gameBoard, validLocations);
    checkPiece(currLocation.first - 1, currLocation.second + 2, black, gameBoard, validLocations);
    checkPiece(currLocation.first - 1, currLocation.second - 2, black, gameBoard, validLocations);
}

void Piece::kingMoves(bool black, QPair<int,int> currLocation, QHash<QPair<int, int>, Piece*> gameBoard, QList<QPair<int, int>> &validLocations){
    checkPiece(currLocation.first + 1, currLocation.second, black, gameBoard, validLocations);
    checkPiece(currLocation.first + 1, currLocation.second + 1, black, gameBoard, validLocations);
    checkPiece(currLocation.first + 1, currLocation.second - 1, black, gameBoard, validLocations);
    checkPiece(currLocation.first - 1, currLocation.second, black, gameBoard, validLocations);
    checkPiece(currLocation.first - 1, currLocation.second + 1, black, gameBoard, validLocations);
    checkPiece(currLocation.first - 1, currLocation.second - 1, black, gameBoard, validLocations);
    checkPiece(currLocation.first, currLocation.second + 1, black, gameBoard, validLocations);
    checkPiece(currLocation.first, currLocation.second - 1, black, gameBoard, validLocations);
}

void Piece::pawnMoves(bool black, QPair<int,int> currLocation, QHash<QPair<int, int>, Piece*> gameBoard, QList<QPair<int, int>> &validLocations){
    int direction = -1;
    if(black){
        direction = 1;
    }
    // Pawn gets custom logic (yay)
    if(freshPawn){
        // Check two moves
        if(checkInbounds(currLocation.first + direction * 2, currLocation.second)){
            QPair<int, int> nextLocation(currLocation.first + direction * 2, currLocation.second);
            if(!gameBoard.contains(nextLocation)){
                validLocations.append(nextLocation);
            }
        }
    }

    // Check One Move
    if(checkInbounds(currLocation.first + direction, currLocation.second)){
        QPair<int, int> nextLocation(currLocation.first + direction, currLocation.second);
        if(!gameBoard.contains(nextLocation)){
            validLocations.append(nextLocation);
        }
    }

    // Check diagonal capture
    if(checkInbounds(currLocation.first + direction, currLocation.second - 1)){
        QPair<int, int> nextLocation(currLocation.first + direction, currLocation.second - 1);
        if(gameBoard.contains(nextLocation)){
            if(black){
                if(whitePiece(gameBoard[nextLocation])){
                    validLocations.append(nextLocation);
                }
            }else{
                if(blackPiece(gameBoard[nextLocation])){
                    validLocations.append(nextLocation);
                }
            }
        }
    }
    if(checkInbounds(currLocation.first + direction, currLocation.second + 1)){
        QPair<int, int> nextLocation(currLocation.first + direction, currLocation.second + 1);
        if(gameBoard.contains(nextLocation)){
            if(black){
                if(whitePiece(gameBoard[nextLocation])){
                    validLocations.append(nextLocation);
                }
            }else{
                if(blackPiece(gameBoard[nextLocation])){
                    validLocations.append(nextLocation);
                }
            }
        }
    }
}
