#include "node.h"
#ifndef QUEUE_H
#define QUEUE_H

class queue {
	node *header_queue;
public:
	queue();
	~queue();
	void add_node_queue();
	void remove_node_queue();
	void check_queue();
};

#endif
