# Set CFLAGS to activate all warnings and enable debugger
CFLAGS = -Wall -g

# Default rule is to build the executable called aSim
all: qSim

# Rule for building the executable.
qSim: qSim.o Customer.o Teller.o CustEvent.o TellerEvent.o tellerQueue.o eventQueue.o Event.o
	g++ $(CFLAGS) qSim.o Customer.o Teller.o CustEvent.o TellerEvent.o tellerQueue.o eventQueue.o Event.o -o qSim

# Rules for building each object file.
qSim.o: qSim.cpp 
	g++ $(CFLAGS) -c qSim.cpp

Customer.o: Customer.cpp Customer.h
	g++ $(CFLAGS) -c Customer.cpp
	
Teller.o: Teller.cpp Teller.h
	g++ $(CFLAGS) -c Teller.cpp

CustEvent.o: CustEvent.cpp CustEvent.h
	g++ $(CFLAGS) -c CustEvent.cpp
	
TellerEvent.o: TellerEvent.cpp TellerEvent.h
	g++ $(CFLAGS) -c TellerEvent.cpp
	
eventQueue.o: eventQueue.cpp eventQueue.h
	g++ $(CFLAGS) -c eventQueue.cpp
	
tellerQueue.o: tellerQueue.cpp tellerQueue.h
	g++ $(CFLAGS) -c tellerQueue.cpp

Event.o: Event.cpp Event.h
	g++ $(CFLAGS) -c Event.cpp
	
# Give command "make clean" to remove object files,
#  executable, and documentation.
clean:
	rm -f *.o qSim
	rm -f -r html latex

# Give command "make docs" to create documentation.
docs:
	doxygen
