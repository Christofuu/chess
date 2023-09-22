//
// Created by Chris on 9/15/2023.
//

#include "King.h"
#include <iostream>
#include <cmath>

King::King(Color pieceColor) {
    isValidPiece = true;
    setColor(pieceColor);

    if (getColor() == Piece::Color::WHITE) {
        origin = sf::Vector2f(512 + 10, 896 + 10);
        setPiecePosition(origin);
        pieceSprite = sf::Sprite(pieceTexture, sf::IntRect(0,0,108,108));
        pieceSprite.setPosition(origin);
        symbol = 'K';
    }
    else if (getColor() == Piece::Color::BLACK) {
        origin = sf::Vector2f (512 + 10, 10);
        setPiecePosition(origin);
        pieceSprite = sf::Sprite(pieceTexture, sf::IntRect(0,105,108,108));
        pieceSprite.setPosition(origin);
        symbol = 'k';
    }
    else {
        throw std::invalid_argument( "   ERROR: King color not defined");
    }
}

void King::movePiece(int rank, int file) {
    int currRank = floor(getPosition().x / 128);
    int currFile = floor(getPosition().y / 128);

    int dx = rank - currRank;
    int dy = file - currFile;

    if ((abs(dx) > 1 or abs(dy) > 1) and (abs(dx) == 0 or abs(dy) == 0)) {
        std::cout << "   ERROR: invalid move" << std::endl;
    }
    else {
        std::cout << "valid move" << std::endl;
        setPiecePosition(sf::Vector2f (getPosition().x + (dx * 128),getPosition().y + (dy * 128)));
        pieceSprite.setPosition(getPosition());
    }
}


