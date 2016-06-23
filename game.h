#include "snake.h"
#include "state_base.h"


#ifndef GAME_H
#define GAME_H

class main_game : public tiny_state {

public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:

	sf::Font* font;
	bool enterKey;
}
#endif
