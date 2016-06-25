#include "list.h"
#include <iostream>

list::list() {
} 

list::~list() {
}

list *list::newlist() {
	list *p;
	p = new list();
	p->front = NULL;
	p->rear = NULL;
	return p;
}

list *list::clearList(list *p) {
	node *q, *w;
	q = p->front;
	while (q != NULL) {
		w = nextNode(q);
		freeNode(q);
		q = w;
	}
	p->front = NULL;
	p->rear = NULL;
	return p;
}

void list::freeList(list *p) {
	// Memoria usada por cada node
	clearList(p);
	// Memoria usada pela estrutura
	delete(p);
}

bool list::emptyList(list *p) {
	if (p->front == NULL)
		return true;
	else
		return false;
}

list *list::insertAtFront(list *p, int n) {
	node *q;
	q = newNode(n);
	q->next = p->front;
	p->front = q;
	if (p->rear == NULL)
		p->rear = q;
	return p;
}

list *list::insertAfter(list *p, node *w, int n) {
	node *q;
	if (w == NULL || p->front == NULL)
		return insertAtFront(p, n);
	q = newNode(n);
	q->next = w->next;
	w->next = q;
	if (w == p->rear)
		p->rear = q;
	return p;
}

list *list::insertAtRear(list *p, int n) {
	node *q;
	q = p->rear;
	return insertAfter(p, q, n);
}

node *list::findInList(list *p, int n) {
	node *q;
	q = p->front;
	while (q != NULL) {
		if (q->info == n)
			break;
		q = nextNode(q);
	}
	// retorna NULL se nao encontrar
	return q;
}

bool list::isInList(int colour) {
	if((findInList(this, colour)) != null) {
		return true;
	}
	else
		return false;
}