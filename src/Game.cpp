//
// Created by Chris on 9/5/2023.
//

#include "Game.h"
#include <cmath>

Game::Game() {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            gameState[i][j] = new NullPiece;
        }
    }
}

Board Game::getBoard() {
    return chessboard;
}

void Game::endTurn() {
    isWhiteTurn = !isWhiteTurn;
}

void Game::createPiece(char symbol) {

    //todo: create classes for all pieces, implement in method
    switch(symbol) {
        case 'K': {
            gameState[4][7] = new King(Piece::Color::WHITE);
            sf::Vector2f origin = sf::Vector2f(512 + 10, 896 + 10);
            gameState[4][7]->setPiecePosition(origin);
            gameState[4][7]->pieceSprite = sf::Sprite(pieceTexture, sf::IntRect(0, 0, 108, 108));
            gameState[4][7]->pieceSprite.setPosition(origin);
            break;
        }
        case 'k': {
            gameState[4][0] = new King(Piece::Color::BLACK);
            sf::Vector2f origin = sf::Vector2f(512 + 10,10);
            gameState[4][0]->setPiecePosition(origin);
            gameState[4][0]->pieceSprite = sf::Sprite(pieceTexture, sf::IntRect(0, 105, 108, 108));
            gameState[4][0]->pieceSprite.setPosition(origin);
            break;
        }
        case 'Q': {
            break;
        }
        case 'q': {
            break;
        }
        case 'R': {
            break;
        }
        case 'r': {
            break;
        }
        case 'B': {
            break;
        }
        case 'b': {
            break;
        }
        case 'N': {
            break;
        }
        case 'n': {
            break;
        }
        case 'P': {
            break;
        }
        case 'p': {
            break;
        }
        default:
            std::cout << "   ERROR: Piece symbol: " << symbol <<  " not recognized." << std::endl;
    }
}

void Game::loadTexture() {
    if (!pieceTexture.loadFromFile("C:/Users/Chris/CLionProjects/chess/assets/pieces-sprite-map.png")) {
        std::cout << "   ERROR: Pieces Textures Not Found!" << std::endl;
    }
    else {
        std::cout << "texture loaded successfully" << std::endl;
    }
}

void Game::movePiece(Piece* piece, int rank, int file) {
    char symbol = piece->symbol;
    int currRank = floor(piece->getPosition().x / 128);
    int currFile = floor(piece->getPosition().y / 128);

    int dx = rank - currRank;
    int dy = file - currFile;

    switch(symbol) {
        case 'K': {
            piece->setPiecePosition(sf::Vector2f (piece->getPosition().x + (dx * 128),piece->getPosition().y + (dy * 128)));
            piece->pieceSprite.setPosition(piece->getPosition());
            gameState[rank][file] = piece;
            endTurn();
            break;
        }
        case 'k': {
            piece->setPiecePosition(sf::Vector2f (piece->getPosition().x + (dx * 128),piece->getPosition().y + (dy * 128)));
            piece->pieceSprite.setPosition(piece->getPosition());
            gameState[rank][file] = piece;
            endTurn();
            break;
        }
        case 'Q': {
            break;
        }
        case 'q': {
            break;
        }
        case 'R': {
            break;
        }
        case 'r': {
            break;
        }
        case 'B': {
            break;
        }
        case 'b': {
            break;
        }
        case 'N': {
            break;
        }
        case 'n': {
            break;
        }
        case 'P': {
            break;
        }
        case 'p': {
            break;
        }
        default:
            std::cout << "   ERROR: Piece symbol: " << symbol <<  " not recognized." << std::endl;
    }
}

// logic for various piece moves
bool Game::isLegalMove(Piece* piece, int rank, int file) {
    int currRank = floor(piece->getPosition().x / 128);
    int currFile = floor(piece->getPosition().y / 128);

    int dx = rank - currRank;
    int dy = file - currFile;

    char symbol = piece->symbol;

    switch(symbol) {
        case 'K': {
            if (abs(dx) > 1 or abs(dy) > 1) {
                std::cout << "   ERROR: invalid move" << std::endl;
                return false;
            }
            std::cout << "valid move" << std::endl;
            return true;
        }
        case 'k': {
            if (abs(dx) > 1 or abs(dy) > 1) {
                std::cout << "   ERROR: invalid move" << std::endl;
                return false;
            }
            std::cout << "valid move" << std::endl;
            return true;
            break;
        }
        case 'Q': {
            break;
        }
        case 'q': {
            break;
        }
        case 'R': {
            break;
        }
        case 'r': {
            break;
        }
        case 'B': {
            break;
        }
        case 'b': {
            break;
        }
        case 'N': {
            break;
        }
        case 'n': {
            break;
        }
        case 'P': {
            break;
        }
        case 'p': {
            break;
        }
        case '_': {
            std::cout << "   ERROR: blank square selected" << std::endl;
        }
        default:
            std::cout << "   ERROR: Piece symbol: " << symbol <<  " not recognized." << std::endl;
    }
    return false;
}

bool Game::isValidPiece(Piece* piece) const {
    if ((isWhiteTurn and piece->getColor() == Piece::Color::WHITE) or (!isWhiteTurn and piece->getColor() == Piece::Color::BLACK)) {
        return true;
    }
    return false;
}
