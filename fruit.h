#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>
#include <ctime>

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
	cFruit(int _colour) {
		circle = new sf::CircleShape(5.0f);
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

		std::srand((int) time(0));
		x = (rand() % 19);
		y = (rand() % 19);
	
		circle->setPosition(x, y);
		
		//x = sf::Randomizer::Random(0, 19);
		//y = sf::Randomizer::Random(0, 19);
	}

	int xVal() {
		return x;
	}

	int yVal() {
		return y;
	}

	void draw(sf::RenderWindow & window) {
		window.draw(*circle);
	}

	void generate() {
		std::srand((int) time(0));
		x = (rand() % 20);
		y = (rand() % 20);
	}

	~cFruit() {}
};
#endif
