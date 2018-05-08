/*
 * Event.h
 *
 *  Created on: Feb 8, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "eventQueue.h"

class eventQueue;
class Event {
public:
	Event(); //Constructor for an Event
	Event(float); //Constructor for an Event given a float
	virtual void doAction() = 0;
	float getStart();
	static void addToEventQ(Event *e);
	static void getNextEvent();
	static int getLen();
	static float currTime; //the current time in the simulation
	static float simTime; //the total time of the simulation
	virtual ~Event();
private:
	float startTime; //the time in the simulation that the event starts at
	static eventQueue *eventQ; //a pointer to the eventQueue that events get added to
};

#endif /* EVENT_H_ */
