#include "snake.h"
#include "game_state.h"


#ifndef MAIN_GAME_H
#define MAIN_GAME_H

class main_game : public sub_state {

public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:

	snake* _snake;

	sf::Font* font;
	bool enterKey;
};
#endif
