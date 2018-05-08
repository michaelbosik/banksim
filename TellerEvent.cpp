/*
 * TellerEvent.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: Brian Earl and Michael Bosik
 */

#include "TellerEvent.h"
#include <stdlib.h>
#include <stdio.h>

TellerEvent::TellerEvent(Teller *t) :
		Event(t->getTime(false)) {

	this->t = t;
}

TellerEvent::TellerEvent(Teller *t, Customer *c) :
		Event(t->getTime(true)) {

	this->t = t;
}

/**Changes currTime depending on the state t is in
 *@return void
 */
void TellerEvent::doAction() {

	TellerEvent *newTE; //temporarily used TellerEvent made to set currTime
	//if: t->getLen() equals zero, goes to next if, else statements
	//else: takes the next customer in t, makes a new TellerEvent and adds it to the queue
	if (t->getLen() == 0) {
		//if: teller is empty and currTime is less than simTime, make a new teller event with t and add it to the queue
		//else: add the next customer in a random teller to t and make a new TellerEvent using the next customer in t
		if (Teller::allEmpty() && Event::currTime < Event::simTime) {
			newTE = new TellerEvent(t);
			Event::addToEventQ(newTE);
			Event::currTime = newTE -> getStart();
		} else {
			Teller *tell = Teller::getRand();
			t->addToTellQ(tell->getNextCust());
			Customer *cust = t->getNextCust();
			newTE = new TellerEvent(t, cust);
			Event::addToEventQ(newTE);
		}
	}

	else {
		Customer *nextCust = t->getNextCust();
		newTE = new TellerEvent(t, nextCust);
		Event::addToEventQ(newTE);
	}
	currTime = newTE->getStart();
}

TellerEvent::~TellerEvent() {

}

