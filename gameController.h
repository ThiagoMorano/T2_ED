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
	}
	

private:
	list* fruitList;

	gameController() {
		fruitList = new list();
	}


public:
	

};



#endif