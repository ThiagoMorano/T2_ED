#include "stdafx.h"
#include <iostream>
#include <SFML\Graphics.hpp>

class aux_state {
public:
	virtual void initialize(sf::RenderWindow* _window)
	{
	}
	virtual void update(sf::RenderWindow* _window)
	{
	}
	virtual void destroy(sf::RenderWindow* _window)
	{
	}
	virtual void render(sf::RenderWindow* _window)
	{
	}
};


class game_state {
public:
	game_state() 
	{
		
	}
	void initialize(sf::RenderWindow* _window)
	{
		if (this->state != NULL)
	}
	void update(sf::RenderWindow* _window);
	void destroy(sf::RenderWindow* _window);
	void render(sf::RenderWindow* _window);
private:
	sf::RenderWindow* window;
	aux_state *state;
};