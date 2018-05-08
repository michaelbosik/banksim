/*
 * tellerQueue.cpp
 *
 *  Created on: Feb 13, 2018
 *      Author: Brian Earl and Michael Bosik
 */

#include "tellerQueue.h"

tellerQueue::tellerQueue() {
	tellerQueue::head = 0;
	tellerQueue::tail = 0;
}


/**Adds a customer to the end of the queue
 *@param c The customer that you want to add to the end of the queue
 *@return void
 */
void tellerQueue::addToQueue(Customer *c){
	Node *n = new Node; //A temporary node used for moving nodes around the queue
	n -> c = c;

	//if: getLen() equals zero, make head and tail equal to n
	//else: put n in the queue and push tail back
	if (getLen() == 0){
		head = n;
		tail = n;
	}

	else {
		tail -> prev = n;
		n -> next = tail;
		tail = n;
	}
}

/**returns the customer that in the front of the line and puts the previous person in line in the front
 *@return the customer that in the front of the line
 */
Customer *tellerQueue::nextInQueue(){

	Node *headNode = head; //The first node in the queue

	//if: getLen() equals 1, make head and tail equal to zero
	//else: set head equal to prev
	if (getLen() == 1){
		head = 0;
		tail = 0;
	}

	else {
		head -> prev -> next = 0;
		head = head -> prev;
	}

	return headNode -> c;
}

/**Returns if the length of the length of the queue is zero or not
 *@return if the length of the length of the queue is zero or not
 */
bool tellerQueue::hasNext(){
	return getLen() != 0;
}

/**Returns the length of the queue
 *@return the length of the queue
 */
int tellerQueue::getLen(){
	Node *temp = head;
	int i = 0;
	while (temp != 0){
		i++;
		temp = temp -> prev;
	}
		return i;
}

tellerQueue::~tellerQueue() {
}

