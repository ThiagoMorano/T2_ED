#include "snake.h"

snake::snake() {
	speed = 10.0f;
	
	texture.loadFromFile("snakes_head.png");
	head.setTexture(texture);
}

snake::~snake() {

}

void snake::Update() {

}

void snake::Draw(sf::RenderWindow* window) {
	window->draw(head);
}
