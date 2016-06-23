#include <SFML/Graphics.hpp>
#include "queue.h"
#include "entity.h"

#ifndef SNAKE_H
#define SNAKE_H

class snake : public entity {
	public:
		snake();
		~snake();
	
		void Update();
		void Draw(sf::RenderWindow* window);
	
	private:
		queue body;
		float speed;
		bool enterKey;

		sf::Texture texture;
    	sf::Sprite head;
};

#endif
