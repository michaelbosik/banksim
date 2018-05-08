/*
 * Que.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#include "eventQueue.h"

//Constructor for an eventQueue
eventQueue::eventQueue() {
	head = 0; //the first item in the queue is nothing
	tail = 0; //the last item in the queue is nothing
}

/**Add the given event to the eventQueue
 * @return void
 */
void eventQueue::addToQueue(Event *e) {
	Node *n = new Node; //a temporary pointer to a node
	n->e = e; //set the nodes event to the given event

	if (getLen() == 0) { //check if the length of the queue is 0
		head = n; //set the first event in the queue to the n node
		tail = n; //set the last event in the queue to the n node
	} else {
		tail->prev = n; //set the last nodes previous node to the n node
		n->next = tail; //set the n nodes next node to the last node
		tail = n; //set the last node to the n node
	}
}

/**Return the Event that is the next in the eventQueue
 * @return the Event that is next in the eventQueue
 */
Event *eventQueue::nextInQueue() {

	Node *headNode = head; //a temporary node set to the first node

	if (getLen() == 1) { //check if the length of the queue is 1
		head = 0; //set the first node to 0
		tail = 0; //set the last node to 0
	}

	else {
		head->prev->next = 0; //set the first nodes previous nodes next node to 0
		head = head->prev; //set the first node to the first nodes previous node
	}

	return headNode->e;
}

/**Return true if the length of the eventQueue is greater than 0, false if not
 * @return true if the length of the eventQueue is greater than 0, false if not
 */
bool eventQueue::hasNext() {
	return getLen() != 0;
}

/**Return the length of the eventQueue
 * @return the length of the eventQueue as an int
 */
int eventQueue::getLen() {
	Node *temp = head; //temporary node equal to the first node
	int i = 0; //i keeps track of the length of the queue

	//increases i by one every iteration and changes the temporary node
	while (temp != 0) {
		i++; //increase the i, the length of the queue
		temp = temp->prev; //set the temporary node to the temporary nodes previous node
	}
	return i;
}

//Deconstructor for an eventQueue
eventQueue::~eventQueue() {

}

