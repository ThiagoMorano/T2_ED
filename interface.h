#include <SFML/Graphics.hpp>

#ifndef MASK_H
#define MASK_H

class mask {

private:
	int score;

	sf::Font* font;
	sf::Text* regras;

/*	int maskX = 600;
	int maskHeight = 600;

	int bordaFrutasX = maskX + 40;
*/
	int xFruta1;
	int xFruta2;
	int xFruta3;
	int yFrutas;

	sf::RectangleShape* bordaFrutas;

	sf::CircleShape* fruits[3];
	sf::Color auxCor;

public:

	mask() {

/*		this->font = new sf::Font();
		this->font->loadFromFile("/T2_ED/font.ttf");

		this->regras = new sf::Text("Pegue apenas as frutas cuja cor a cobrinha quer comer!", *this->font, 32U);
		this->regras->setOrigin(this->regras->getGlobalBounds().width / 2, this->regras->getGlobalBounds().height / 2);
		this->regras->setPosition(window->getSize().x / 2, window->getSize().y / 8);

		bordaFrutas = new st::CircleShape(sf::Vector2f(120,)
*/

		xFruta1 = 680;
		xFruta2 = 720;
		xFruta3 = 660;
		yFrutas = 300;
	
		fruits[0] = new sf::CircleShape(10.0f);
		fruits[0]->setPosition(xFruta1, yFrutas);

		fruits[1] = new sf::CircleShape(10.0f);
		fruits[1]->setPosition(xFruta2, yFrutas);

		fruits[2] = new sf::CircleShape(10.0f);
		fruits[2]->setPosition(xFruta3, yFrutas);


	}

	void setScore(int _score) {
		score = _score;
	}

	void setCor(int num, int cor) {

		switch (cor) {
		case 0:
			auxCor = sf::Color::Blue;
			break;
		case 1:  //case Red:
			auxCor = sf::Color::Red;
			break;
		//case Magenta:
		case 2:
			auxCor = sf::Color::Magenta;
			break;
		//case Yellow:
		case 3:
			auxCor = sf::Color::Yellow;
			break;
		//case Green:
		case 4:
			auxCor = sf::Color::Green;
			break;
		}
		fruits[num]->setFillColor(auxCor);
	}

	void draw(sf::RenderWindow &window) {
		//DRAW CONTORNO
		//DRAW REGRAS
		//DRAW FRUTAS
		//DRAW SCORE

		window.draw(*fruits[0]);
		window.draw(*fruits[1]);
		window.draw(*fruits[2]);
	}
};

extern mask* gameMask;

#endif
