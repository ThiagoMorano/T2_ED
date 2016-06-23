#include <iostream>

class node {
	int info;
	node *next;
public:
	node();
	~node();
};

class list {
	node header;
public:
	void add(int x);
	void remove(int x);
	void list_check(int x);
	void remove_all(int x);
};
