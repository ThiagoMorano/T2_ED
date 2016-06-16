#pragma once

#include "state_manager.h"
#include "player.h"

class main_game : public aux_state {
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	player* guy;
};