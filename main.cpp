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
                gM->fruits[cor].escondeFruta();
                if(_snake.getNumComidas() % 3 == 0 ) {
                    gM->geraNovasFrutas(_snake);
                }
            }
        }

        if(_snake.wallHit() || _snake.bodyHit()) {
			_snake = snake();
            gM->geraNovasFrutas(_snake);
		}

		App.clear();
        _snake.draw(App); 	 //Draw the snake
        gM->draw(App); 		 //Draw the fruits
        gameMask->draw(App); //Draw the interface
        App.display();
        
		Sleep(100);
    }

    return 0;
}
