#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

#ifndef MASK_H
#define MASK_H

class mask {

private:
	int score;

	sf::Font* font;
	sf::Text* regras;
	sf::Text* setas;
	sf::Text* scoreText;
	
	sf::String sfString;
	std::stringstream ss;
	
	
	int posRegrasX;
	int posRegrasY;

	int posScoreX;
	int posScoreY;


	int maskX;
	int maskHeight;
	int maskThickness;


	int bordaFrutasX;
	int bordaFrutasY;
	int bordaFrutasWidth;
	int bordaFrutasHeight;
	int bordaFrutasThickness;

	int xFruta1;
	int xFruta2;
	int xFruta3;
	int yFrutas;

	sf::RectangleShape* bordaFrutas;
	sf::RectangleShape* bordaMask;

	sf::CircleShape* fruits[3];
	sf::Color auxCor;

public:

	mask() {

		font = new sf::Font();
		font->loadFromFile("font.ttf");
		

		maskX = 600;
		maskHeight = 600;
		maskThickness = 6;

		bordaFrutasX = maskX + 30;
		bordaFrutasY = 260;
		bordaFrutasWidth = 130;
		bordaFrutasHeight = 80;
		bordaFrutasThickness = 2;
		
		xFruta1 = bordaFrutasX + 20;
		xFruta2 = bordaFrutasX + 60;
		xFruta3 = bordaFrutasX + 100;
		yFrutas = bordaFrutasY + 40;
	
		//Definindo shape da borda principal
		bordaMask = new sf::RectangleShape(sf::Vector2f(200 - maskThickness, maskHeight + maskThickness));
		bordaMask->setFillColor(sf::Color::Black);
		bordaMask->setPosition(maskX, 0);
		bordaMask->setOutlineThickness(maskThickness);
		bordaMask->setOutlineColor(sf::Color::White);
	
	

		//Definindo shape da borda das frutas	
		bordaFrutas = new sf::RectangleShape(sf::Vector2f(bordaFrutasWidth, bordaFrutasHeight));
		bordaFrutas->setFillColor(sf::Color::Black);
		bordaFrutas->setPosition(bordaFrutasX, bordaFrutasY);
		bordaFrutas->setOutlineThickness(bordaFrutasThickness);
		bordaFrutas->setOutlineColor(sf::Color::White);
	
		fruits[0] = new sf::CircleShape(10.0f);
		fruits[0]->setPosition(xFruta1, yFrutas);

		fruits[1] = new sf::CircleShape(10.0f);
		fruits[1]->setPosition(xFruta2, yFrutas);

		fruits[2] = new sf::CircleShape(10.0f);
		fruits[2]->setPosition(xFruta3, yFrutas);

		
		posRegrasX = maskX + 20;
		posRegrasY = 40;
		
		regras = new sf::Text("Pegue apenas as\nfrutas cuja cor\na cobrinha\nquer comer!", *this->font, 16U);
		regras->setColor(sf::Color::White);
		regras->setPosition(posRegrasX, posRegrasY);
		
		setas = new sf::Text("Use as setas para jogar", *this->font, 16U);
		setas->setColor(sf::Color::White);
		setas->setPosition(posRegrasX - 15, posRegrasY + 140);
		
		
		posScoreX = maskX + 90;
		posScoreY = 500;
		score = 0;
		ss << score;
		
		scoreText = new sf::Text(ss.str(), *this->font, 32U);
		scoreText->setColor(sf::Color::White);
		scoreText->setPosition(posScoreX, posScoreY);
		
	}

	void setScore(int _score) {
		ss.str(std::string());
		score = _score;
		ss << score;
		
		scoreText = new sf::Text(ss.str(), *this->font, 32U);
		scoreText->setPosition(posScoreX, posScoreY);
	}

	void setCor(int num, int cor) {

		switch (cor) {
		case 0:
			auxCor = sf::Color::Blue;
			break;
		case 1:  //case Red:
			auxCor = sf::Color::Red;
			break;
		//case Magenta:
		case 2:
			auxCor = sf::Color::Magenta;
			break;
		//case Yellow:
		case 3:
			auxCor = sf::Color::Yellow;
			break;
		//case Green:
		case 4:
			auxCor = sf::Color::Green;
			break;
		}
		fruits[num]->setFillColor(auxCor);
	}

	void draw(sf::RenderWindow &window) {
		//DRAW CONTORNO
		//DRAW REGRAS
		//DRAW FRUTAS
		//DRAW SCORE
		window.draw(*bordaMask);
		
		window.draw(*bordaFrutas);
		
		window.draw(*regras);
		
		window.draw(*scoreText);
		window.draw(*setas);
		
		window.draw(*fruits[0]);
		window.draw(*fruits[1]);
		window.draw(*fruits[2]);
	}
};

extern mask* gameMask;

#endif
