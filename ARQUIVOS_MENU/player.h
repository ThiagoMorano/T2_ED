#pragma once

#include "entity.h"

class player : public Entity {
public:
	player() {
		this->Load("ninja.png");
	}
	void Update() {
		this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
		this->velocity.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	
		Entity::Update();
	}
private:
};