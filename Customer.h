/*
 * Customer.h
 *
 *  Created on: Feb 8, 2018
 *      Author: Michael Bosik, Brian Earl
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Customer {
public:
	Customer(float arrTime); //Constructor for a Customer given an arrival time as a float
	float getArrTime();
	virtual ~Customer();
private:
	float arrTime; //The time in the simulation in which the customer arrives at the bank
};

#endif /* CUSTOMER_H_ */
