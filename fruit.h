#pragma once

class cFruit
{
private:
	int x;
	int y;

public:
	cFruit()
	{
		x = sf::Randomizer::Random(0, 19);
		y = sf::Randomizer::Random(0, 19);
	}

	int xVal()
	{
		return x;
	}

	int yVal()
	{
		return y;
	}

	void draw(sf::RenderWindow & App)
	{
		App.Draw(sf::Shape::Circle(x * 10 + 5, y * 10 + 5, 5.0, sf::Color(255, 0, 0)));
	}

	void generate()
	{
		x = sf::Randomizer::Random(0, 19);
		y = sf::Randomizer::Random(0, 19);
	}

	~cFruit() {}
};
