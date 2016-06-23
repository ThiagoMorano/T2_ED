#ifndef FRUIT_H
#define FRUIT_H
#include <SFML/Graphics.hpp>

enum FoodColour { Blue, Yellow, Red, Green, Orange };

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

public:
	cFruit() {
		x = sf::Randomizer::Random(0, 19);
		y = sf::Randomizer::Random(0, 19);
	}

	int xVal() {
		return x;
	}

	int yVal() {
		return y;
	}

	void draw(sf::RenderWindow & App) {
		FoodColour colour;
		switch (colour) {
		case Blue:
			break;
		case Red:
			break;
		case Orange:
			break;
		case Yellow:
			break;
		case Green:
			App.Draw(sf::Shape::Circle(x * 10 + 5, y * 10 + 5, 5.0, sf::Color::Green));
			break;
		}
	}

	void generate() {
		x = sf::Randomizer::Random(0, 19);
		y = sf::Randomizer::Random(0, 19);
	}

	~cFruit() {}
};
#endif
