#include "fruit.h"
#ifndef LIST_H
#define LIST_H

class node {
	int info;
	node *next;
public:
	node() {}
	node *newNode(int x) {
		node *q;
		q = new node();
		q->info = x;
		q->next = NULL;
		return q;
	}
	void freeNode(node *q) {
		delete(q);
	}
	~node() {}
};

class list {
	node *front;
	node *rear;
public:
	list();
	~list();
	void add_node_list(int x);
	void remove_node_list(int x);
	void list_check(int x);
	void remove_all(int x);
};

#endif
