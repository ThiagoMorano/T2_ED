#include "game.h"

void main_game::Initialize(sf::RenderWindow* window) {

	

}

void main_game::Update(sf::RenderWindow* window) {
	snake->Update();
}

void main_game::Render(sf::RenderWindow* window) {
	snake->Draw(window);
}

void main_game::Destroy(sf::RenderWindow* window) {
	snake->~snake();
}
