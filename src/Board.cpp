//
// Created by Chris on 9/5/2023.
//

#include "Board.h"
Board::Board() {

    if (!boardTexture.loadFromFile("C:/Users/Chris/CLionProjects/chess/assets/green-plastic.png")) {
        std::cout << "   ERROR: Board texture not found." << std::endl;
    }
    boardSprite.setTexture(boardTexture);
    generateTiles();

}

void Board::generateTiles() {
    sf::Vector2f tileSize(boardSprite.getGlobalBounds().width / numRows, boardSprite.getGlobalBounds().height / numCols);

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            // rule to determine tile color
            Tile::Color tileColor = (row + col) % 2 == 0 ? Tile::Color::DARK : Tile::Color::LIGHT;
            // rule to determine tile position
            sf::Vector2f tilePosition(col * tileSize.x, row * tileSize.y);
            sf::Vector2i tileIndex(row, col);

            // populate chessboard with tiles
            chessboard[row][col] = Tile(static_cast<char>('a' + col), row + 1, tileColor, tilePosition, tileSize);

            std::cout << "Tile: " << chessboard[row][col].getFile() << chessboard[row][col].getRank() << " " << static_cast<bool>(tileColor)
                      << " generated." << " Position: " << chessboard[row][col].getTilePosition().x << ", " << chessboard[row][col].getTilePosition().y << std::endl;
        }
    }
}

sf::Vector2f Board::getTilePosition(int row, int col) {
    return chessboard[row][col].getTilePosition();
}

