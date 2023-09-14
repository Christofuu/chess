//
// Created by Chris on 9/5/2023.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H


class Piece {

public:
    // Enums to represent piece type
    enum class Color {WHITE, BLACK};

    // Deconstructor
    virtual ~Piece() {}

    // Virtual methods for implementation in subclasses
    virtual bool isValidMove() const = 0;
    virtual char getSymbol() const = 0;

    void setColor(Color pieceColor);

    Piece::Color getColor() const;

private:
    Color pieceColor;

};


#endif //CHESS_PIECE_H
