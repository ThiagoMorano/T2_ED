#include "game.h"

void Initialize(sf::RenderWindow* window) {

	snake = new snake();

	enterKey = false;
}

void Update(sf::RenderWindow* window) {
	snake->Update();
}

void Render(sf::RenderWindow* window) {
	snake->Draw();
}

void Destroy(sf::RenderWindow* window) {
	snake->~snake();
}
