#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef NODE_H
#define NODE_H

class node {
	int info;
	//sf::color info;
	node *next;
public:
	node() {}
	~node() {}
};

#endif

