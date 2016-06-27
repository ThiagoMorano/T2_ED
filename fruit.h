#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>
#include <ctime>

extern int height;
extern int width;
extern int gridScale;

class cFruit {
private:
	int x, vetorx[10000];
	int y, vetory[10000];
	int i = 0;
	int colour;
	sf::Color colourToDraw;
	
	sf::CircleShape* circle;

public:
	cFruit() {
		int flag = 0, flag2 = 0;
		while (flag != 1) {
			x = rand() % 30;
			x = x - (x % 10);
			y = (rand() % 30);
			y = y - (y % 10);
			for (int j = 0; j <= i; j++) {
				if (x == vetorx[j] && y == vetory[j])
					flag2 = 1;
			}
			if (flag2 == 0) {
				flag = 1;
				vetorx[i] = x;
				vetory[i] = y;
				i++;
			}
			else {
				flag2 = 0;
			}
		}
		/*x = (rand() % 30);
		x = x - (x % 10);
		
		y = (rand() % 30);
		y = y - (y % 10);*/
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

	void generate() {
		int flag = 0, flag2 = 0;
		while (flag != 1) {
			x = rand() % 30;
			x = x - (x % 10);
			y = (rand() % 30);
			y = y - (y % 10);
			for (int j = 0; j <= i; j++) {
				if (x == vetorx[j] && y == vetory[j])
					flag2 = 1;
			}
			if (flag2 == 0) {
				flag = 1;
				vetorx[i] = x;
				vetory[i] = y;
				i++;
			} else {
				flag2 = 0;
			}
		}
	}

	void escondeFruta() {
		x = -30;
		y = -30;
	}

	~cFruit() {
		//delete(circle);
	}
};
#endif
