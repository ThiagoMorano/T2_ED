#include <SFML/Graphics.hpp>
#include "snake.h"
#include "list.h"

int width = 200;
int height = 200;

int main()
{
    sf::RenderWindow App(sf::VideoMode(width, height),"Snake Picky Eater");

    snake snake;
    cFruit fruit(0);

    while(App.isOpen())
    {
        sf::Event event;
        while(App.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                App.close();

            /*if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                App.close();

            if(App.GetInput().IsKeyDown(sf::Key::Up))
                snake.setDirection(1);

            if(App.GetInput().IsKeyDown(sf::Key::Down))
                snake.setDirection(2);

            if(App.GetInput().IsKeyDown(sf::Key::Right))
                snake.setDirection(3);

            if(App.GetInput().IsKeyDown(sf::Key::Left))
                snake.setDirection(4);*/
        }
        
        
        snake.move();

        if(snake.eatFruit(fruit)) {
            fruit.generate();

            while(snake.fruitCollision(fruit))
            fruit.generate();

            snake.addBodyPiece();
        }
        
        if(snake.wallHit() || snake.bodyHit()) {
        	//Die
		}

		App.clear();
        snake.draw(App);
        fruit.draw(App);
        App.display();

    }

    return 0;
}

/*MAIN OLD VERSION
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
*/
