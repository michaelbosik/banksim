/*
 * Event.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#include "Event.h"

eventQueue* Event::eventQ; //a pointer the queue of events that the event goes in
float Event::currTime; //the current time that the event will take place in the simulation
float Event::simTime; //the total time of the simulation

//Constructor for an Event given the startTime of the Event as a float
Event::Event(float startTime){
	this -> startTime = startTime;
	eventQ = new eventQueue();
}

/**Adds the event to the eventQueue
 * @param *e a pointer to the event that will be added
 * @return void
 */
void Event::addToEventQ(Event *e){
	eventQ->addToQueue(e); //add the given event to the eventQueue
}

/**Makes the next Event in the eventQueue perform its action
 * @return void
 */
void Event::getNextEvent(){
	eventQ->nextInQueue() -> doAction(); //makes the next Event in the eventQueue perform its action
}

/**Returns the length of the eventQueue
 * @return the length of the eventQueue
 */
int Event::getLen(){
	return eventQ->getLen(); //return the length of the eventQueue
}

/**Returns the startTime of the Event
 * @return the startTime of the Event
 */
float Event::getStart(){
	return startTime; //return the startTime of the Event
}

//Deconstructor for the Event
Event::~Event(){}





