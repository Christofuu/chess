//
// Created by Chris on 9/22/2023.
//

#ifndef CHESS_NULLPIECE_H
#define CHESS_NULLPIECE_H


#include "Piece.h"

class NullPiece : public Piece {

    void movePiece(int rank, int file) override;
};


#endif //CHESS_NULLPIECE_H
