//
// Created by Chris on 9/5/2023.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include <unordered_map>
#include "Board.h"
#include "Piece.h"
#include "King.h"
#include "NullPiece.h"


class Game {
public:

    Piece* gameState[8][8];
    sf::Texture pieceTexture;

    bool isWhiteTurn = true;

    // Pieces
    void createPiece(char symbol);

    Game();
    // Methods for game management
    bool isCheckmate();
    bool isCheck();

    void movePiece(Piece* piece, int rank, int file);
    bool isLegalMove(Piece* piece, int rank, int file);
    bool isValidPiece(Piece* piece) const;
    void endTurn();
    void loadTexture();

    sf::Texture getPieceTexture();

    Piece getPiece();
    Board getBoard();

private:
    Board chessboard;

};


#endif //CHESS_GAME_H
