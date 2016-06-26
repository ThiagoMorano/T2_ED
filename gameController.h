#include "snake.h"
#include "list.h"

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

class gameController {

private:
	list* fruitList;

public:
	cFruit fruits[5];


	gameController() {
		fruitList = new list();

		fruits[0].setColour(0);
		fruits[1].setColour(1);
		fruits[2].setColour(2);
		fruits[3].setColour(3);
		fruits[4].setColour(4);

		this->geraNovasFrutas();
	}

	//Adiciona novas cores a lista
	void geraNovasFrutas(snake _snake) {//TODO
		fruitList->clearList(fruitList);
		int corPraInserir;
		int i = 0;

		std::srand((int) time(0));
		fruitList->insertAtFront(fruitList, rand() % 4);

		while(i < 2) { //Populando lista com novas cores
			corPraInserir = rand() % 4;
			if(!fruitList->isInList(corPraInserir)) {
				fruitList->insertAtRear(fruitList, corPraInserir);
				i++;
			}
		}

		for(int i = 0; i < 5; i++) { //
			fruits[i]->generate();
            while(_snake.fruitCollision(fruits[i]))
				fruits[i]->generate();
		}


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