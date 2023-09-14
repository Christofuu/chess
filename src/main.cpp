#include <SFML/Graphics.hpp>
#include "./Board.h"

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

int main()
{
    Board chessboard;
    unsigned int resX = 1024u;
    unsigned int resY = 1024u;

    sf::Texture chessPiecesTexture;

    if (!chessPiecesTexture.loadFromFile("C:/Users/Chris/CLionProjects/chess/assets/pieces-sprite-map.png")) {
        std::cout << "   ERROR: Pieces Textures Not Found!" << std::endl;
        return EXIT_FAILURE;
    }

    sf::Sprite whiteKing(chessPiecesTexture, sf::IntRect(0,0,108,108));
    sf::Vector2f whiteKingPosition(512 + 10, 896 + 10);

    whiteKing.setPosition(whiteKingPosition);

    sf::FloatRect kingBounds = whiteKing.getGlobalBounds();
    sf::RectangleShape redOutline(sf::Vector2f(kingBounds.width, kingBounds.height));
    redOutline.setPosition(kingBounds.left, kingBounds.top);
    redOutline.setOutlineColor(sf::Color::Red);
    redOutline.setOutlineThickness(2.0f);
    redOutline.setFillColor(sf::Color::Transparent);

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
        }


        window.clear();
        window.setView(view);
        window.draw(chessboard.boardSprite);
        window.draw(whiteKing);
        window.draw(redOutline);
        window.display();
    }
}
