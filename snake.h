#include <SFML/Graphics.hpp>
#include "fruit.h"
#include "interface.h"

#ifndef SNAKE_H
#define SNAKE_H

struct pos {
	int x;
	int y;
};

class snake {
	public:
		snake();
		~snake();
		int contadorComida;

		void move();
		void setDirection(int);

		void draw(sf::RenderWindow &window);
		void addBodyPiece();

		bool tryEatFruit(cFruit*, int&);
		bool wallHit();
		bool bodyHit();
		bool fruitCollision(cFruit&);
		int getNumComidas();
	
	private:
		pos body[900];
		int x;
		int y;
		int direction;
		int length;
		bool dies;
		
		int squareRadius;
		
		sf::RectangleShape* bodyPiece;
};

#endif
