#include <SFML/Graphics.hpp>
#include "snake.h"
#include "list.h"
#include "gameController.h"
#include <Windows.h>

int width = 800;
int height = 600;
int gridScale = 20;
gameController * gM = new gameController();
mask* gameMask = new mask();

int main() {
    sf::RenderWindow App(sf::VideoMode(width, height),"Snake Picky Eater");
	
	srand(time(NULL));
	snake _snake;
    int cor;
    
    gM->geraNovasFrutas(_snake);
    //cFruit fruits[5];

    while(App.isOpen()) {
        sf::Event event;
        while(App.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                App.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				App.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				_snake.setDirection(1);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				_snake.setDirection(2);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				_snake.setDirection(3);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				_snake.setDirection(4);
        }

        _snake.move();

        if(_snake.tryEatFruit(gM->fruits, cor)) { //Verifica se comeu uma fruta

            if(!gM->checkColourEaten(cor)) { //Caso comeu uma fruta incorreta, morre
                _snake = snake();
                gM->geraNovasFrutas(_snake);
            }
            else {  //Caso comeu uma fruta certa
                _snake.addBodyPiece();
                if(_snake.getNumComidas() % 3 == 0 ) {
                    gM->geraNovasFrutas(_snake);
                }
                gM->fruits[cor].escondeFruta();
            }
        }

        if(_snake.wallHit() || _snake.bodyHit()) {
			_snake = snake();
            gM->geraNovasFrutas(_snake);
		}

		App.clear();
        _snake.draw(App); //Draw the snake
        gM->draw(App); //Draw the fruits
        //gameMask->draw(App);
        App.display();
        
		Sleep(100);
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
