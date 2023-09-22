//
// Created by Chris on 9/15/2023.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Piece.h"


class King : public Piece {
public:
    explicit King(Color pieceColor);

    ~King() override = default;

    void movePiece(int rank, int file) override;
//    char getSymbol() const override;
//    void setSymbol() override;
//    void setOrigin() override;
};


#endif //CHESS_KING_H
