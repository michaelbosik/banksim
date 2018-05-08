/*
 * CustEvent.h
 *
 *  Created on: Feb 8, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#ifndef CUSTEVENT_H_
#define CUSTEVENT_H_

#include "Event.h"
#include "Customer.h"
#include "Teller.h"
#include <stdlib.h>

class CustEvent: public Event {
public:
	CustEvent(Customer *c); //The constructor for a CustEvent given a customer pointer
	void doAction();
	Teller *findShort();
	~CustEvent();
private:
	Customer *c; //A pointer to a customer that is involved in the CustEvent
};

#endif /* CUSTEVENT_H_ */
