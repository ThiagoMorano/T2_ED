#include <SFML/Graphics.hpp>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake BCC Edition");
    sf::Texture texture;
    texture.loadFromFile("snakes_head.png");
    sf::Sprite square(texture);

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Green);

        // draw everything here...
        window.draw(square);

        // end the current frame
        window.display();
    }

    return 0;
}
