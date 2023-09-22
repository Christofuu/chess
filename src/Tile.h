//
// Created by Chris on 9/5/2023.
//

#ifndef CHESS_TILE_H
#define CHESS_TILE_H


#include <vector>
#include <SFML/Graphics.hpp>

class Tile {

public:
    // Enums to represent tile colors
    enum class Color {LIGHT, DARK};

    // Constructors
    Tile();
    Tile(char file, int rank, Color tileColor, sf::Vector2i position, sf::Vector2f size);

    // Getters
    char getFile() const;
    int getRank() const;
    Tile::Color getColor() const;
    sf::Vector2i getTilePosition() const;
    sf::Vector2f getTileSize() const;

    // Setters
    void setFile(char file);
    void setRank(int rank);
    void setColor(Color tileColor);
    void setPosition(sf::Vector2i tilePosition);
    void setSize(sf::Vector2f tileSize);

private:
    char file;
    int rank;
    Color tileColor;
    sf::Vector2i tilePosition;
    sf::Vector2f tileSize = sf::Vector2f(128,128);
};



#endif //CHESS_TILE_H
