/**
 * qSim.cpp
 *
 * @author Michael Bosik, Brian Earl
 *
 */



//#include <random.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Customer.h"
#include "Teller.h"
#include "eventQueue.h"
#include "tellerQueue.h"
#include "CustEvent.h"
#include "TellerEvent.h"


int main(int argc, char **argv) {

	if (argc > 6 || argc < 5){
		std::cout << "Error, incorrect number of arguments, Please enter arguments less than 5" << std::endl;
		return EXIT_FAILURE;
	}

	int custNums = atoi(argv[1]);//The sumber of customers
	int tellNums = atoi(argv[2]);//the number of tellers
	float simTime = atoi(argv[3]);//the length of the simulation
	float avgServTime = atof(argv[4]);//the average serving time of the tellers
	unsigned int seed = time(NULL);//the seed for srand
	if (argc > 5){
		seed = atoi(argv[5]);
		srand(seed);
	}
	float totalTellerIdleTime ; //stores the total time a teller spends idle
	float totalTellerServiceTime ; //store the total time a teller spends serving
	float longestCustomerWaitTime; //stores the longest customer wait time

	Teller::setAvgTime(avgServTime);
	Event::simTime = simTime;
	Event::currTime = 0;
	Teller::numTells = tellNums;
	Teller::tells = new Teller*[tellNums];

	//Creates all of the tellers and puts them in a list
	//before: there are no tellers
	//after: there are tellers
	for (int i = 0; i < tellNums; i++){
		Teller *aTell =  new Teller();
		Teller::tells[i] = aTell;
		Event *aTE = new TellerEvent(aTell);
		Event::addToEventQ(aTE);

	}

	//Creates all of the customers and puts them in a list
	//before: there are no customers
	//after: there are customers
	for (int j = 0; j < custNums; j++){
		Customer *aCust = new Customer(rand() /float(RAND_MAX) * simTime);
		Event *aCE = new CustEvent(aCust);
		Event::addToEventQ(aCE);
	}

	//while the length of the queue is more than one, run getNextEvent()
	while(Event::getLen() > 0){
		Event::getNextEvent();
	}

	//runs through all of the tellers and gets their total idle time, total serving time
	//and the longest customer wait time
	for(int i = 0; i < tellNums; i++)
	{
		totalTellerIdleTime += Teller::tells[i]->getTotalIdleTime();
		totalTellerServiceTime += Teller::tells[i]->getTotalServiceTime();
		//if longestCustomerWaitTime is greater than Teller::tells[i]->getlongestWaitTime(),
		//make longestCustomerWaitTime equal Teller::tells[i]->getlongestWaitTime()
		if(longestCustomerWaitTime < Teller::tells[i]->getLongestWaitTime())
			longestCustomerWaitTime = Teller::tells[i]->getLongestWaitTime();
	}
	std::cout << "Number of customers: " << custNums << " Total time required: " << Event::simTime <<std::endl;
	std::cout << "Number of tellers: " << tellNums << " Queuing type: One line per teller" << std::endl;
	std::cout << "Average service time: " << avgServTime <<  std::endl;
	std::cout << "Maximum amount of time in bank: " << longestCustomerWaitTime << std::endl;
	std::cout << "Total teller service time: " << totalTellerServiceTime << " Total teller idle time: " << totalTellerIdleTime <<std::endl;

	return 0;
}
