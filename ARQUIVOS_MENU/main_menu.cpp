#include <iostream>
#include "main_menu.h"
#include "snake.h"

void main_menu::Initialize(sf::RenderWindow* window) {
	this->selected = 0;

	this->font = new sf::Font();
	this->font->loadFromFile("/T2_ED/font.ttf");

	this->title = new sf::Text("Snake", *this->font, 128U);
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->title->setPosition(window->getSize().x / 2, window->getSize().y / 8);

	this->play = new sf::Text("Jogar", *this->font, 64U);
	this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
	this->play->setPosition(window->getSize().x / 2, window->getSize().y / 1.8);

	this->quit = new sf::Text("Quit", *this->font, 64U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 1.4);
}

void main_menu::Update(sf::RenderWindow* window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey) {
		this->selected += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey) {
		this->selected = 1;
	}
	if (this->selected > 1) {
		this->selected = 0;
	}
	if (this->selected < 0) {
		this->selected = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
		switch (this->selected) {
		case 0:
			coreState.SetState(new main_game());
			break;
		case 1:
			quitGame = true;
			break;
		}
	}
	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}

void main_menu::Render(sf::RenderWindow* window) {
	
	this->play->setColor(sf::Color::White);
	this->quit->setColor(sf::Color::White);
	
	switch (this->selected) {
	case 0:
		this->play->setColor(sf::Color::Green);
		break;
	case 1:
		this->quit->setColor(sf::Color::Green);
		break;
	}

	window->draw(*this->title);
	window->draw(*this->play);
	window->draw(*this->quit);
}

void main_menu::Destroy(sf::RenderWindow* window) {
	delete this->font;
	delete this->title;
	delete this->play;
	delete this->quit;
}
