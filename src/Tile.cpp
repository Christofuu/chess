//
// Created by Chris on 9/5/2023.
//
#include <iostream>
using namespace std;

#include "Tile.h"
#include <SFML/Graphics.hpp>

Tile::Tile() : file('a'), rank(1), tileColor(Color::LIGHT) {}

Tile::Tile(char file, int rank, Color tileColor, sf::Vector2f position, sf::Vector2f size ): file(file), rank(rank), tileColor(tileColor), tilePosition(position), tileSize(size) {
    setColor(tileColor);
}

char Tile::getFile() const {
    return file;
}

int Tile::getRank() const {
    return rank;
}

sf::Vector2f Tile::getTilePosition() const {
    return tilePosition;
}


Tile::Color Tile::getColor() const {
    return tileColor;
}

sf::Vector2f Tile::getTileSize() const {
    return tileSize;
}

void Tile::setFile(char file) {
    this->file = file;
}

void Tile::setRank(int rank) {
    this->rank = rank;
}

void Tile::setColor(Color tileColor) {
    this->tileColor = tileColor;
}

void Tile::setPosition(sf::Vector2f tilePosition) {
    this->tilePosition = tilePosition;
}

void Tile::setSize(sf::Vector2f tileSize) {
    this->tileSize = tileSize;
}

