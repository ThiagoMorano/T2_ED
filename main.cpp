#include <SFML/Graphics.hpp>
#include "game_state.h"
#include "main_game.h"

game_state coreState;
bool quitGame = false;

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake BCC Edition");

    //Preparing the core state
    coreState.SetWindow(&window);
    coreState.SetState(new main_game());

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

        //Update the state
        coreState.Update();
        //Render the state
        coreState.Render();


        // end the current frame
        window.display();

        //Close the window in case the game ended
        if(quitGame) {
            window.close();
        }

    }

    return 0;
}
