#include <SFML/Graphics.hpp>
#include "fruit.h"

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

		void move();
		void setDirection(int);

		void draw(sf::RenderWindow &window);
		void addBodyPiece();

		bool eatFruit(cFruit&);
		bool wallHit();
		bool bodyHit();
		bool fruitCollision(cFruit&);
		
	
	private:
		pos body[100];
		int x;
		int y;
		int direction;
		int length;
		
		sf::RectangleShape* bodyPiece;
};

#endif
