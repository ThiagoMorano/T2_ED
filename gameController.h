#include "snake.h"
#include "list.h"

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

class gameController {


	//Defining as singleton
	private static gameController instance = null;
	public static gameController getInstance() {
		if(instance == null) {
			instance = new ReactionTabel();
		}
		return instance;
	}

private:
	list* fruitList;

	gameController() {
		fruitList = new list();

		fruits[0].setColour(0);
		fruits[1].setColour(1);
		fruits[2].setColour(2);
		fruits[3].setColour(3);
		fruits[4].setColour(4);

		//Call method to add random colors to the list
		this->generateAllNew();
	}


public:

	cFruit ingameFruits[5];
	
	//Generate new values for the list, and new positions for the fruits
	void generateAllNew() {
		fruitList->clearList(fruitList);
		
	}

	//Check if the fruit eaten was in the list.s
	// returns true if it was
	bool checkColourEaten(int colour) {
		if(this->fruitList->isInList(colour)) {
			return true;
		}
		else
			return false;
	}

	//Checks if the list was complete
	// returns true if it was
	bool checkListComplete() {

	}

};



#endif