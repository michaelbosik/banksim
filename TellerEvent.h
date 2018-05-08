/*
 * TellerEvent.h
 *
 *  Created on: Feb 8, 2018
 *      Author: Brian Earl and Michael Bosik
 */


#ifndef TELLEREVENT_H_
#define TELLEREVENT_H_

#include "Event.h"
#include "Teller.h"
#include "Customer.h"

class TellerEvent : public Event{
public:
	TellerEvent(Teller *t);
	TellerEvent(Teller *t, Customer *c);
	void doAction();
	~TellerEvent();
private:
	Teller *t; //The teller the event is tied to
};

#endif /* TELLEREVENT_H_ */
