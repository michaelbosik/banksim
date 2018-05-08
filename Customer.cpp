/*
 * Customer.cpp
 *
 *  Created on: Feb 8, 2018
 *      @author Michael Bosik, Brian Earl
 */

#include "Customer.h"
#include <iostream>

// Constructor for the class
Customer::Customer(float arrTime) {
	this -> arrTime = arrTime;
}

/**Returns the arrival time of this customer
 * @return the arrival time of this customer
 */
float Customer::getArrTime(){
	return arrTime;
}

// Deconstructor for the class
Customer::~Customer() {

}

