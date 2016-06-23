#include <SFML/Graphics.hpp>
#include "queue.h"
#include "entity.h"

#ifndef SNAKE_H
#define SNAKE_H

struct pos {
	int x;
	int y;
};

class snake : public entity {
	public:
		snake();
		~snake();

		void move();
		void setDirection();

		void draw(sf::RenderWindow &window);
		void addBodyPiece();

		bool eatFood();
		bool wallHit();
		bool bodyHit();
		bool foodColision();
		
	
	private:
		pos body[100];
		int x;
		int y;
		int direction;
		int length;
};

#endif
