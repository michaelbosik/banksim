Michael Bosik, Brian Earl
Assignment 4

Included Files:
 - Examples (Folder)
 	- Log1.txt
 	- Log2.txt
 	- Log3.txt
 - README.txt
 - makefile
 - doxyfile
 - qSim.cpp
 - Customer.cpp
 - Customer.h
 - Teller.cpp
 - Teller.h
 - Event.cpp
 - Event.h
 - CustEvent.cpp
 - CustEvent.h
 - TellerEvent.cpp
 - TellerEvent.h
 - eventQueue.cpp
 - eventQueue.h
 - tellerQueue.cpp
 - tellerQueue.h

Program Summary:
  The qSim simulation is a program that will simulate customers arriving at a bank and waiting in lines to be helped by tellers. The customers have random arrival times
  and will go to the line that is shortest out of all the teller lines. In a different simulation, all of the customers will go to one same line. The tellers will help
  customers for an average service time and then move on to the next customer. If there are no more customers in the line, the teller will become idle and wait until a
  new customer comes along. After the simulation time is over, or there are no more customers in the simulation, statistics of the simulation will be displayed such as:
  total number of customers served, total time to serve all customers, amount of tellers and type of queuing, mean amount of time a customer was in the bank, max wait time
  from the time a customer arrived to the time they were seen by the teller, and total amount of teller service time and idle time.

How to Run:
 - Open the terminal
 - Navigate to the directory that the project is located in
 - Type the command "make clean && make"
 - Type the command "./qSim [Customers] [Tellers] [Simulation Time] [Average Service Time] <seed>"
  - Customers is the amount of Customers in the simulation entered as an int
  - Tellers is the amount of Tellers in the simulation entered as an int
  - Simulation Time is the total time of the simulation entered as a float
  - Average Service Time is the average time it takes for a Teller to help a Customer entered as a float
  - Seed is an optional argument that will change the seed of the simulation

Problems During Assignment:
 - One of the biggest issues in completing this assignment was to understand and determine how the class hierarchy should
 have been laid out.
 - Another issue was creating the LinkedList in which the eventQueue is represented

Events:
 - Events are a parent of both Customer Events (CustEvent) or Teller Events (TellerEvent)
 - They are represented as nodes inside a LinkedList
 - They are added to the event queue (eventQueue) and organized in the order in which they should happen in the simulation

Customers:
 - A Customer can only perform one type of CustEvent; the arrival time (arrTime) of each Customer determines when they will arrive at the bank in the
 simulation
 - A Customer is represented as a node within a Tellers LinkedList or the communal LinkedList of Customers depending on the simulation

Tellers:
 - A Teller can have two types of TellerEvents; the Teller could go idle if there are no more customers in their respective tellerQueue. They will go
 idle for idleTime in the simulation.
 - Tellers can also retrieve the next Customer from the tellerQueue as a TellerEvent
 - A Teller is represented as a node in within an array of Tellers

Analysis of Results:
-analysis of results (when is single queue better or worse than lots of queues)
