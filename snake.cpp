#include "snake.h"

snake::snake() {
	x =	0;
	y = 0;
	body[0].x = x;
	body[0].y = y;
	srand(time(NULL));
	//direction = rand() % 3 + 2;
	direction = 0;
	length = 1;
	dies = false;
	contadorComida = 0;

	squareRadius = 20;
	
	bodyPiece = new sf::RectangleShape(sf::Vector2f(squareRadius, squareRadius));
	bodyPiece->setFillColor(sf::Color::Green);
}

void snake::move() {

	for(int i=length-1;i != 0;i--)	{
		body[i].x = body[i-1].x;
       	body[i].y = body[i-1].y;
	}

	switch(direction) {
	case 1:
		y--;
		break;

	case 2:
		y++;
		break;

	case 3:
		x++;
		break;

	case 4:
		x--;
		break;
	}

	body[0].x = x;
	body[0].y = y;

}

void snake::setDirection(int dir) { direction = dir; }

void snake::draw(sf::RenderWindow &window) {
	for(int i=0;i<length;i++) {
		bodyPiece->setPosition(body[i].x*gridScale, body[i].y*gridScale);
		//window.draw(sf::Shape::Rectangle(body[i].x*10+1, body[i].y*10+1, body[i].x*10+9, body[i].y*10+9, sf::Color(0,255,0)));
		window.draw(*bodyPiece);
	}
		
}

void snake::addBodyPiece() {
	length++;
	for(int i=length-1;i != 0;i--) {
		body[i].x = body[i-1].x;
		body[i].y = body[i-1].y;
	}

	body[0].x = x;
	body[0].y = y;
}

bool snake::tryEatFruit(cFruit* frutas, int& cor) {
	bool comeu = false;
	int i = -1;
	do {
		i++;
		if(x == frutas[i].xVal() && y == frutas[i].yVal()) {
			comeu = true;
			cor = i;
		}
	} while (comeu == false && i < 4)

	return comeu;
}

bool snake::wallHit() {
	if(y == -1 || y == (height/gridScale) || x == -1 || x == (width - 200)/gridScale)
		return true;
	else
		return false;
}

bool snake::bodyHit(){
	for(int i=2;i<length;i++) {
		if(body[i].x == x && body[i].y == y)
			return true;
	}

	return false;
}

bool snake::fruitCollision(cFruit &Food) {
	for(int i=0;i<length;i++)
		if(body[i].x == Food.xVal() && body[i].y == Food.yVal())
			return true;

	return false;
}


int snake::getNumComidas() {
	return (length - 1);
}

snake::~snake() {
	//delete(bodyPiece);
}