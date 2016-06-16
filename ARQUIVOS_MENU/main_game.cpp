#include "stdafx.h"
#include "main_game.h"
#include "main_menu.h"

void main_game::Initialize(sf::RenderWindow* window) {
	this->guy = new player();
}
void main_game::Update(sf::RenderWindow* window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		coreState.SetState(new main_menu());
	}
	this->guy->Update();
}
void main_game::Render(sf::RenderWindow* window) {
	window->draw(*this->guy);
}
void main_game::Destroy(sf::RenderWindow* window) {
	delete guy;
}