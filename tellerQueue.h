/*
 * tellerQueue.h
 *
 *  Created on: Feb 13, 2018
 *     Author: Brian Earl and Michael Bosik
 */

#ifndef TELLERQUEUE_H_
#define TELLERQUEUE_H_

#include "Customer.h"

class tellerQueue {
public:
	tellerQueue();
	virtual ~tellerQueue();
	void addToQueue(Customer *c);
	Customer *nextInQueue();
	bool hasNext();
	int getLen();
private:
	struct Node {
		Node *prev;
		Node *next;
		Customer *c;
	};
	Node *head; //The first node in the queue
	Node *tail; //The last node in the queue
};

#endif /* TELLERQUEUE_H_ */
