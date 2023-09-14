//
// Created by Chris on 9/5/2023.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "Tile.h"
#include "Piece.h"
#include "iostream"
#include <SFML/Graphics.hpp>

class Board {
    public:
        Board();

        sf::Texture boardTexture;
        sf::Sprite boardSprite;
        sf::Vector2f tileSize;

        const int numRows = 8, numCols = 8;

        Piece getPiece();

        void movePiece(Piece piece);

        bool isLegalMove();


        void generateTiles();
        sf::Vector2f getTilePosition(int row, int col);


    private:
        Tile chessboard[8][8];

};



#endif //CHESS_BOARD_H
