/*
 * Teller.h
 *
 *  Created on: Feb 8, 2018
 *      Author: Brian Earl and Michael Bosik
 */

#ifndef TELLER_H_
#define TELLER_H_

#include "tellerQueue.h"
#include <iostream>
#include "Customer.h"

class Teller {
private:
	tellerQueue tellQ; //The queue of the teller
	const float idleTime; //The idleTime of the teller
	static float avgServTime; //The average time it takes the teller to serve a customer
	float totalServiceTime; //keeps track of the total service time
	float totalIdleTime; //keeps track of the total idle time
	float longestWaitTime; //keeps track of the longest wait time of a customer

public:
	static Teller **tells; //A list of tellers
	static int numTells; //The number of tellers in tells
	Teller();
	float getTime(bool);
	static void setAvgTime(float);
	void addToTellQ(Customer *c);
	int getLen();
	Customer *getNextCust();
	static bool allEmpty();
	static Teller *getRand();
	float getTotalIdleTime();
	float getTotalServiceTime();
	float getLongestWaitTime();
	virtual ~Teller();
};

#endif /* TELLER_H_ */
