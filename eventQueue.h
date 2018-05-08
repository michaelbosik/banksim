/*
 * Que.h
 *
 *  Created on: Feb 8, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_


#include "Event.h"

class Event;
class eventQueue {
public:
	eventQueue(); //Constructor for an eventQueue
	virtual ~eventQueue();
	void addToQueue(Event *e);
	Event *nextInQueue();
	bool hasNext();
	int getLen();
private:
	struct Node { //a node with a previous node, next node and an event tied to it
		Node *prev; //pointer to the previous node
		Node *next; //pointer to the next node
		Event *e; //pointer to the event
	};
	Node *head; //pointer to the head of the eventQueue
	Node *tail; //pointer to the tail of the eventQueue
};



#endif /* EVENTQUEUE_H_ */
