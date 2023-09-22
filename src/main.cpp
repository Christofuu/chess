#include <SFML/Graphics.hpp>
#include "./Board.h"
#include "./King.h"
#include "./Game.h"
#include "NullPiece.h"
#include <cmath>
#include <array>

sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight) {

    // Compares the aspect ratio of the window to the aspect ratio of the view,
    // and sets the view's viewport accordingly in order to achieve a letterbox effect.
    // A new view (with a new viewport set) is returned.

    float windowRatio = windowWidth / (float) windowHeight;
    float viewRatio = view.getSize().x / (float) view.getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    bool horizontalSpacing = true;
    if (windowRatio < viewRatio)
        horizontalSpacing = false;

    // If horizontalSpacing is true, the black bars will appear on the left and right side.
    // Otherwise, the black bars will appear on the top and bottom.

    if (horizontalSpacing) {
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2.f;
    }

    else {
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2.f;
    }

    view.setViewport( sf::FloatRect(posX, posY, sizeX, sizeY) );

    return view;
}

std::array<int,2> detectMouseClick(sf::Event event, const Board& chessboard, sf::RenderWindow& window) {
    std::array<int, 2> coords = {-1, -1};

    if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonReleased) {
        if (chessboard.boardSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            coords[0] = floor(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x / 128);
            coords[1] = floor(window.mapPixelToCoords(sf::Mouse::getPosition(window)).y / 128);
        }
        else {
            std::cout<< "click out of board bounds" << std::endl;
        }
    }

    return coords;
}


int main()
{
    Game game;
    game.loadTexture();

    bool isPieceSelected = false;
    Piece* selectedPiece;
    NullPiece nullPiece;

    game.createPiece('K');
    game.createPiece('k');

    int currentTileSize = 128;

    unsigned int resX = 1024u;
    unsigned int resY = 1024u;

    auto window = sf::RenderWindow{ { resX, resY }, "Chess", (sf::Style::Resize + sf::Style::Close) };
    window.setFramerateLimit(144);

    sf::View view;
    view.setSize( 1024u, 1024u );
    view.setCenter( view.getSize().x / 2, view.getSize().y / 2 );
    view = getLetterboxView( view, resX, resY );


    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::Resized) {
                view = getLetterboxView(view, event.size.width, event.size.height);
            }

            if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonReleased) {
                std::array<int, 2> coords = detectMouseClick(event, game.getBoard(), window);
                int rank = coords[0];
                int file = coords[1];

                std::cout << rank << " " << file << std::endl;

                if (!isPieceSelected) {
                    if (game.isValidPiece(game.gameState[rank][file])) {
                        selectedPiece = game.gameState[rank][file];
                        isPieceSelected = true;
                    }
                    else {
                        std::cout << "invalid piece" << std::endl;
                    }
                    std::cout << "piece selected: " << isPieceSelected << std::endl;
                }
                else {
                    if (game.isLegalMove(selectedPiece, rank, file)) {

                        game.movePiece(selectedPiece, rank, file);
                    }
                    isPieceSelected = false;
                    selectedPiece = &nullPiece;
                }
            }


            detectMouseClick(event, game.getBoard(), window);
        }

        window.clear();

        window.setView(view);
        window.draw(game.getBoard().boardSprite);
        window.draw(game.gameState[4][7]->pieceSprite);
        window.draw(game.gameState[4][0]->pieceSprite);

        window.display();
    }
}
