#include "snake.h"

snake::snake() {
	x = 30;
	y = 30;
	body[0].x = x;
	body[0].y = y;
	direction = 0;
	length = 1;
	
	bodyPiece = new sf::RectangleShape(5, 5);
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
	for(int i=0;i<length;i++)
		window.draw(sf::Shape::Rectangle(body[i].x*10+1,body[i].y*10+1,body[i].x*10+9,body[i].y*10+9,sf::Color(0,255,0)));
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

bool snake::eatFruit(cFruit &Food) {
	if(x == Food.xVal() && y == Food.yVal())
	return true;
	else
	return false;
}

bool snake::wallHit() {
	if(y == -1 || y == 20 || x == -1 || x == 20)
		return true;
	else
		return false;
}

bool snake::bodyHit(){
	for(int i=2;i<length;i++)
	if(body[i].x == x && body[i].y == y)
		return true;

	return false;
}

bool snake::fruitCollision(cFruit &Food) {

	/*
		VERIFICAR A COR DA COMIDA, E SE NÃO ESTIVER NA LISTA, MORRE
	*/
	for(int i=0;i<length;i++)
		if(body[i].x == Food.xVal() && body[i].y == Food.yVal())
			return true;

	return false;
}

snake::~snake() {}
