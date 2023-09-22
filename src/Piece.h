//
// Created by Chris on 9/5/2023.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <SFML/Graphics.hpp>


class Piece {

public:
    // Enums to represent piece type
    enum class Color {WHITE, BLACK, EMPTY};
    sf::Texture pieceTexture;
    sf::Sprite pieceSprite;
    char symbol = '_';
    sf::Vector2f origin;
    bool isValidPiece;

    Piece();
    Piece(Color pieceColor);

    // Deconstructor
    virtual ~Piece() = default;

    virtual void movePiece(int rank, int file) = 0;

    void setColor(Color pieceColor);
    void setPiecePosition(sf::Vector2f newPosition);
    void setTexture();

    sf::Vector2f getPosition() const;

    Piece::Color getColor() const;

private:
    Color pieceColor;
    sf::Vector2f position;


};


#endif //CHESS_PIECE_H
