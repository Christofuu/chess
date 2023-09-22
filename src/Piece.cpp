//
// Created by Chris on 9/5/2023.
//

#include <iostream>
#include "Piece.h"

Piece::Piece() : isValidPiece(false), pieceColor(Color::EMPTY)  {
    // Constructor body (if needed)
}

Piece::Piece(Piece::Color pieceColor) {
}


void Piece::setColor(Color pieceColor) {
    this->pieceColor = pieceColor;
}

void Piece::setPiecePosition(sf::Vector2f newPosition) {
    position = newPosition;
}

sf::Vector2f Piece::getPosition() const {
    return position;
}

Piece::Color Piece::getColor() const {
    return pieceColor;
}

void Piece::setTexture() {
    if (!pieceTexture.loadFromFile("C:/Users/Chris/CLionProjects/chess/assets/pieces-sprite-map.png")) {
        std::cout << "   ERROR: Pieces Textures Not Found!" << std::endl;
    }
    else {
        std::cout << "piece texture loaded successfully at " << &pieceTexture << std::endl;
    }
}





