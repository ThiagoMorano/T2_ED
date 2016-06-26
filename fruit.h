#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>
#include <ctime>

extern int height;
extern int width;
extern int gridScale;

//enum FoodColour { Blue, Yellow, Red, Green, Orange };

/*class Food {
private:
	sf::Texture texture;
	FoodColour colour;

public:
	Food (FoodColour _colour) {
		colour = _colour;

		switch (colour) {
		case Blue:
			//	texture = sf::LoadSprite("blue_square");
			break;
		case Yellow:
			//	texture = sf::LoadSprite("yellow_square");
			break;
		case Red:
			//	texture = sf::LoadSprite("red_square");
			break;
		case Green:
			//	texture = sf::LoadSprite("green_square");
			break;
		}
	}
	~Food () {
		//DELETE Texture
	}
};*/

class cFruit {
private:
	int x;
	int y;
	//FoodColour colour;
	int colour;
	sf::Color colourToDraw;
	
	sf::CircleShape* circle;

public:
	//cFruit(FoodColour _colour) {
	cFruit() {
		
		//x = (rand() % width);
		x = (rand() % 30);
		x = x - (x % 10);
		
		//y = (rand() % height);
		y = (rand() % 30);
		y = y - (y & 10);
		
		//x = sf::Randomizer::Random(0, 19);
		//y = sf::Randomizer::Random(0, 19);
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
		//case Orange:
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
			//App.Draw(sf::ShapeCircle(x * 10 + 5, y * 10 + 5, 5.0, sf::Color::Green));
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
		x = (rand() % 30);
		x = x - (x % 10);
		y = (rand() % 30);
		y = y - (y & 10);
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
