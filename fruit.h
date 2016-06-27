#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>
#include <ctime>

extern int height;
extern int width;
extern int gridScale;

class cFruit {
private:
	int x;
	int y;
	int i = 0;
	int colour;
	sf::Color colourToDraw;
	
	sf::CircleShape* circle;

public:
	cFruit() {
		x = (rand() % 30);
		y = (rand() % 30);
	}

	void setColour(int _colour) {
		circle = new sf::CircleShape(10.0f);
		colour = _colour;

		switch (colour) {
		//case Blue:
		case 0:
			colourToDraw = sf::Color::Blue;
			break;
		//case Red:
		case 1:
			colourToDraw = sf::Color::Red;
			break;
		//case Magenta:
		case 2:
			colourToDraw = sf::Color::Magenta;
			break;
		//case Yellow:
		case 3:
			colourToDraw = sf::Color::Yellow;
			break;
		//case Green:
		case 4:
			colourToDraw = sf::Color::Green;
			break;
		}
		circle->setFillColor(colourToDraw);
	}

	int xVal() {
		return x;
	}

	int yVal() {
		return y;
	}

	void draw(sf::RenderWindow & window) {
		circle->setPosition(x*gridScale, y*gridScale);
		window.draw(*circle);
	}

	//Gera valores de posicao para a fruta
	void generate(cFruit* lista) {
		do {	//Nao permite que duas frutas ocupem a mesma posicao
			x = (rand() % 30);
			y = (rand() % 30);
		} while (!((this->x == lista[0].xVal()) && (this->y == lista[0].yVal()) ||
				((this->x == lista[1].xVal()) && (this->y == lista[1].yVal()))  ||
				((this->x == lista[2].xVal()) && (this->y == lista[2].yVal()))  ||
				((this->x == lista[3].xVal()) && (this->y == lista[3].yVal()))  ||
				((this->x == lista[4].xVal()) && (this->y == lista[4].yVal()))));
	}

	void escondeFruta() {
		x = -30;
		y = -30;
	}

	~cFruit() {
	}
};
#endif
