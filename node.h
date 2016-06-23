#include <SFML/Graphics.h>

#ifndef NODE_H
#define NODE_H

class node {
	sf::color info;
	node *next;
public:
	node();
	~node();
};

#endif

