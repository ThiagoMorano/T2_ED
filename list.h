#include "node.h"
#ifndef LIST_H
#define LIST_H

class list {
	node *header_list;
public:
	list();
	~list();
	void add_node_list(int x);
	void remove_node_list(int x);
	void list_check(int x);
	void remove_all(int x);
};

#endif
