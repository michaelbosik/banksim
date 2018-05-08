/*
 * CustEvent.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#include "CustEvent.h"

//Constructor for a CustEvent given a pointer to a customer
CustEvent::CustEvent(Customer *c) : Event(c->getArrTime()) {
	CustEvent::c = c;
}

/**Triggers the TellerEvent addToTellQ with a Customer
 * @return void
 */
void CustEvent::doAction() {
	Teller *aTell = findShort(); //Make a temporary teller array to what is returned from findShort()
	aTell->addToTellQ(c); //add the Customer to the teller queue
}

/**Returns a Teller that has the shortest teller queue for a customer to join
 *@return the place in the array of Tellers that has the shortest teller queue
 */
Teller *CustEvent::findShort() {
	int shortest = Teller::tells[0]->getLen(); //The shortest teller queue is set to the length of the first teller queue

	//Sets shortest to the length of the teller queue in the ith place of the amount of tellers
	for (int i = 1; i < Teller::numTells; i++) {
		if (Teller::tells[i]->getLen() < shortest) //check if the current teller has a shorter queue length then the shortest
			shortest = Teller::tells[i]->getLen(); //set the shortest to the length of the shortest teller queue length
	}

	Teller *newArr[Teller::numTells]; //Make an array of Tellers the size of the amount of Tellers in the simulation
	int numShort = 0; //keeps track of the place of the Teller with the shortest teller queue

	//Inserts the Teller with the shortest teller queue to the numShort place in the array of Tellers
	for (int j = 0; j < Teller::numTells; j++) {
		if (Teller::tells[j]->getLen() == shortest) //check if the length of the jth tellers teller queue in the list of tellers is the shortest
			newArr[numShort] = Teller::tells[j]; //puts the jth teller in the numShort place of the Teller array
		numShort++; //increase the value of the position of the shortest teller queue
	}

	return newArr[rand() % numShort];
}

CustEvent::~CustEvent() {

}

