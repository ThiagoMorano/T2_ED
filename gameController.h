#include "snake.h"
#include "list.h"
#include "interface.h"

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

class gameController {

private:
	list* fruitList;

public:
	cFruit fruits[5];


	gameController() {
		fruitList = new list();
		fruitList = fruitList->newlist();

		fruits[0].setColour(0);
		fruits[1].setColour(1);
		fruits[2].setColour(2);
		fruits[3].setColour(3);
		fruits[4].setColour(4);
	}

	//Adiciona novas cores a lista
	void geraNovasFrutas(snake _snake) {
		fruitList->clearList(fruitList);
		int corPraInserir;
		int i = 0;

		corPraInserir =  rand() % 4;
		fruitList->insertAtFront(fruitList, corPraInserir);
		gameMask->setCor(i, corPraInserir);

		while(i < 2) { //Populando lista com novas cores
			corPraInserir = rand() % 4;
			if(!fruitList->isInList(corPraInserir)) {
				fruitList->insertAtRear(fruitList, corPraInserir);
				i++;
				gameMask->setCor(i, corPraInserir);
			}
		}

		for(int i = 0; i < 5; i++) { //Checa se nenhuma fruta está sobre a cobra
			fruits[i].generate();
				while(_snake.fruitCollision(fruits[i]))
					fruits[i].generate();
		}
	}

	//Check if the fruit eaten was in the list.s
	bool checkColourEaten(int colour) {
		if(this->fruitList->isInList(colour)) {
			return true;
		}
		else
			return false;
	}

	void draw(sf::RenderWindow &window) {
		for(int i = 0; i < 5; i++) {
			fruits[i].draw(window);
		}
	}

};

extern gameController* gM;
extern mask* gameMask;

#endif
