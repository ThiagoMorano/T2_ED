#include "main_game.h"

void main_game::Initialize(sf::RenderWindow* window) {

	_snake = new snake();

	enterKey = false;
}

void main_game::Update(sf::RenderWindow* window) {
	_snake->Update();
}

void main_game::Render(sf::RenderWindow* window) {
	_snake->Draw(window);
}

void main_game::Destroy(sf::RenderWindow* window) {
	_snake->~snake();
}
