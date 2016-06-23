#include <SFML/Graphics.hpp>

#ifndef FOOD_H
#define FOOD_H

enum type FoodColour {
	Blue, Yellow, Red, Green, 
};

class Food {
	private:
		sf::Texture texture;
		FoodColour colour;
	
	public:
		Food(FoodColour _colour) {
			colour = _colour;
			
			switch(colour) {
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
		~Food() {
			//DELETE Texture
		}

	}
};

#endif
