#include "fruit.h"
#ifndef LIST_H
#define LIST_H

class node {
public:
	node() {}
	int info;
	node *next;
	node *newNode(int x) {
		node *q;
		q = new node();
		q->info = x;
		q->next = NULL;
		return q;
	}
	node *nextNode(node *p) {
		return p->next;
	}
	void freeNode(node *q) {
		delete(q);
	}
	~node() {}
};

class list : public node {
	node *front;
	node *rear;
public:
	list();
	~list();
	list *newlist();
	list *clearList(list *p);
	void freeList(list *p);
	bool emptyList(list *p);
	list *insertAtFront(list *p, int n);
	list *insertAfter(list *p, node *w, int n);
	list *insertAtRear(list *p, int n);
	node *findInList(list *p, int n);
	bool isInList(int colour);
};

#endif
