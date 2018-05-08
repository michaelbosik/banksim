/*
 * Teller.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: Brian Earl and Michael Bosik
 */

#include "Teller.h"
#include <stdlib.h>
#include "Event.h"

float Teller::avgServTime; //Stores the average service time
int Teller::numTells; //Stores number of tellers in tells
Teller** Teller::tells;//The list of tellers
float* waitTimes;//A list of all the wait times
int waitTimeAmount;//The amount of wait times in waitTimes


Teller::Teller() :
		idleTime(600) {
	totalServiceTime = 0;
	totalIdleTime = 0;
	longestWaitTime = 0;
}

/**Returns how much time it takes the teller to complete the event
 * @param hasCusts if there are customers in the queue
 * @return how much time it takes the teller to complete the event
 */
float Teller::getTime(bool hasCusts) {

	//if: hasCust is true, calculate the service time a customer
	//else: Calculate the time being idle
	if (hasCusts)
	{
		float temp = Event::currTime + 2 * rand() / float(RAND_MAX) * avgServTime;
		totalServiceTime = totalServiceTime + temp;
		//if: temp is larger than longestWaitTime, set longestWaitTime equal to temp
			if(temp > longestWaitTime)
				longestWaitTime = temp;
			waitTimes[waitTimeAmount] = temp;
			waitTimeAmount++;
		return temp;
	}
	else
	{
		float temp = Event::currTime + rand() / float(RAND_MAX) * idleTime;
		totalIdleTime = totalIdleTime + temp;
		return temp;
	}

}

/**Changes the value of avgServTime
 * @param avgServTime the value that you want to set avgServTime to
 * @return void
 */
void Teller::setAvgTime(float avgServTime) {

	Teller::avgServTime = avgServTime;
}

/**Adds a customer to the queue
 * @param c The customer that you want to add to the queue
 * @return void
 */
void Teller::addToTellQ(Customer *c) {
	tellQ.addToQueue(c);
}

/**Returns the next customer in tellQ
 * @return The next customer in tellQ
 */
Customer *Teller::getNextCust() {

	return tellQ.nextInQueue();
}


/**Returns the length of tellQ
 * @return the length of tellQ
 */
int Teller::getLen() {

	return tellQ.getLen();
}

/**Returns whether or not all of the tellers have a queue length of 0
 * @return true of all the tellers have a queue length of 0, false otherwise
 */
bool Teller::allEmpty() {
	//Goes through the tellers in tells and checks if their length are zero
	//Before: length of tellers in tells not checked if zero
	//After: length of tellers in tells checked if zero
	for (int i = 0; i < numTells; i++) {
		//if the length of the current teller is not zero, return false;
		if (tells[i]->getLen() != 0)
			return false;
	}
	return true;
}

/**Returns a random teller from tells
 * @return a random teller from tells
 */
Teller *Teller::getRand() {
	Teller *tell;
	//While the length of tell is zero, set tell to a random teller in tells
	//Before: tell is a teller with a length of zero
	//After: tell is a teller with a length greater than zero
	do {
		tell = tells[rand() % numTells];
	} while (tell->getLen() == 0);

	return tell;
}

/**Returns totalIdleTime
 * @return totalIdleTime
 */
float Teller::getTotalIdleTime()
{
	return totalIdleTime;
}

/**Returns totalServiceTime
 * @return totalServiceTime
 */
float Teller::getTotalServiceTime()
{
	return totalServiceTime;
}

/**Returns longestWaitTime
 * @return longestWaitTime
 */
float Teller::getLongestWaitTime()
{
	return longestWaitTime;
}

// deconstructor for the class
Teller::~Teller() {

}

