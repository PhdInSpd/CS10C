// simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
// chaptem 13 prog problem 6
/*
Implement the event-driven simulation of a bank that this chapter described. A queue of arrival events will represent
the line of customers in the bank. Maintain the arrival events and departure events in a priority queue,
sorted by the time of the event. Use stl implementation for the event list.
The input is a text fi le of arrival and transaction times. Each line of the fi le contains the arrival time and
required transaction time for a customer. The arrival times are ordered by increasing time.
Your program must 
    1   -   count customers and keep track of their cumulative waiting time.
            These statistics are sufficient to compute the average waiting time after the last event has been processed.
    2   -   Display a trace of the events executed 
    3   -   and a summary of the computed statistics 
                a   -   the total number of arrivals 
                b   -   and average time spent waiting in line. For example, the input fi le shown in the left columns of the following table should produce the
                        output shown in the right column

Input file              Output from processing file on left
1 5                     Simulation Begins
2 5                     Processing an arrival event at time:    1
4 5                     Processing an arrival event at time:    2
20 5                    Processing an arrival event at time:    4
22 5                    Processing a departure event at time:   6
24 5                    Processing a departure event at time:   11
26 5                    Processing a departure event at time:   16
28 5                    Processing an arrival event at time:    20
30 5                    Processing an arrival event at time:    22
88 3                    Processing an arrival event at time:    24
                        Processing a departure event at time:   25
                        Processing an arrival event at time:    26
                        Processing an arrival event at time:    28
                        Processing an arrival event at time:    30
                        Processing a departure event at time:   30
                        Processing a departure event at time:   35
                        Processing a departure event at time:   40
                        Processing a departure event at time:   45
                        Processing a departure event at time:   50
                        Processing an arrival event at time:    88
                        Processing a departure event at time:   91
                        Simulation Ends
                        Final Statistics:
                        Total number of people processed: 10
                        Average amount of time spent waiting: 5.6

*/

#include <iostream>
#include <queue>
#include <string>

class Event;
class Event {
private:
public:
    int customerID;
    double arrivalTime;
    double duration;
    /// <summary>
    /// arrival event == true 
    /// departute event == true
    /// </summary>
    bool   arrival;
    bool operator <(const Event& otherEvent) {
        bool lessThan = true;
        if ( this->arrivalTime < otherEvent.arrivalTime ) {
            lessThan = true;
        }
        else if (this->arrivalTime == otherEvent.arrivalTime) {
            lessThan = arrival;
        }
        else {
            lessThan = false;
        }
        return lessThan;
    }
};

class Customer {
private:
public:
    /// <summary>
    /// customer ID
    /// </summary>
    int ID;
    
    /// <summary>
    /// time arrived at back
    /// </summary>
    double arrivalTime;
    
    /// <summary>
    /// time got to teller
    /// </summary>
    double tellerTime;

    /// <summary>
    /// time of departure
    /// </summary>
    double departureTime;
    double getWaitingTime() {
        return tellerTime - arrivalTime;
    }
};
class Matrix {
public:
    bool tellerAvailable = true;
    void simulate(std::string inputFile) {
        // Create an empty queue bankQueue to represent the bank line
        std::queue<Event> bankQueue;

        //Create an empty priority queue eventListPQueue for the event list
        std::priority_queue<Event> eventListPQueue;
        tellerAvailable = true;

        // Create and add arrival events to event list
        readEvents(inputFile, eventListPQueue);


        // Event loop
        while (!eventListPQueue.empty()) {
            Event newEvent = eventListPQueue.top();
            // Get current time
            double currentTime = newEvent.arrivalTime;
            if (newEvent.arrival) {
                processArrival(newEvent, eventListPQueue, bankQueue);
            }
            else {
                processDeparture(newEvent, eventListPQueue, bankQueue)
            }
        }
    }

    // Processes an arrival event.
    void processArrival( const Event& arrivalEvent, std::priority_queue<Event>& eventListPQueue, std::queue<Event>& bankQueue ) {
        // Remove this event from the event list
        eventListPQueue.pop();
        customer = customer referenced in arrivalEvent
            if (bankQueue.isEmpty() && tellerAvailable)
            {
                departureTime = currentTime + transaction time in arrivalEvent
                    newDepartureEvent = a new departure event with departureTime
                    eventListPQueue.add(newDepartureEvent)
                    tellerAvailable = false
            }
            else
                bankQueue.enqueue(customer)
    }

    // Processes a departure event .
    void processDeparture( const Event& departureEvent, std::priority_queue<Event>& eventListPQueue, std::queue<Event>& bankQueue ) {
        // Remove this event from the event list
        eventListPQueue.pop();
        if ( !bankQueue.empty() ) {
            // Customer at front of line begins transaction
            customer = bankQueue.peek();
                bankQueue.dequeue()
                departureTime = currentTime + transaction time in customer
                newDepartureEvent = a new departure event with departureTime
                eventListPQueue.add(newDepartureEvent)
        }
        else {
            tellerAvailable = true;
        }
    }
    void readEvents( std::string inputFile, std::priority_queue<Event>& eventListPQueue ) {
        while (data file is not empty)
        {
            Get next arrival time aand transaction time t from file
                newArrivalEvent = a new arrival event containing a and t
                eventListPQueue.add(newArrivalEvent)
        }
    }
};

int main()
{
    Matrix matrix;
    matrix.simulate("1.txt");
    matrix.simulate("2.txt");
}
