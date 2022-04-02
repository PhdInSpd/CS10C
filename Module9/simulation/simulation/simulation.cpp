/*
student: Jose Alfredo Martinez
instructor : Dave Harden
class : CS 10C
    date : March 29, 2022
    file name : simulation.cpp
*/

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
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <fstream>

class Event;
/// <summary>
/// transaction event for bank simulation
/// </summary>
class Event {
private:
public:
    int customerID;
    double absoluteTime;
    double duration;
    /// <summary>
    /// arrival event == true 
    /// departute event == true
    /// </summary>
    bool   arrival;

    /// <summary>
    /// selection for event
    /// </summary>
    /// <param name="left"></param>
    /// <param name="right"></param>
    /// <returns>return true if left and right should be swapped</returns>
    friend bool operator <(const Event& left, const Event& right) {
        bool swap = false;
        if ( left.absoluteTime < right.absoluteTime ) {
            swap = false;
        }
        else if ( left.absoluteTime == right.absoluteTime ) {
            // arrival has higher priority
            if (left.arrival) {
                swap = false;
            }
            else {
                swap = right.arrival;
            }
        }
        else {
            swap = true;
        }
        return swap;
    }
};

/// <summary>
/// class to keep statistics for transactions
/// </summary>
class Customer {
private:
public:
    /// <summary>
    /// customer ID
    /// </summary>
    int customerID;
    
    /// <summary>
    /// time arrived at back
    /// </summary>
    double absoluteTime;
    
    /// <summary>
    /// time got to teller
    /// </summary>
    double tellerTime;

    /// <summary>
    /// time of departure
    /// </summary>
    double departureTime;
    double getWaitTime() {
        return tellerTime - absoluteTime;
    }
};

/// <summary>
/// average wait time for customers vector
/// </summary>
/// <param name="customers"></param>
/// <returns></returns>
double getAverageWaitTime(std::vector<Customer>& customers) {
    if (customers.size() == 0) return 0;
    double sum = 0;
    for (std::vector<Customer>::iterator i= customers.begin(); i != customers.end(); i++) {
        sum += i->getWaitTime();
    }
    return sum / (double)customers.size();
}

/// <summary>
/// class to call simulation
/// </summary>
class Matrix {
private:
    bool tellerAvailable = true;
public:
    /// <summary>
    /// simulate bank transactions
    /// </summary>
    /// <param name="inputFile"></param>
    void simulate(std::string inputFile) {
        // vector of customers
        std::vector<Customer> customers;

        std::cout << "Simulation Begins\n";
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
            double currentTime = newEvent.absoluteTime;
            if (newEvent.arrival) {
                processArrival(newEvent, eventListPQueue, bankQueue, customers);
            }
            else {
                processDeparture(newEvent, eventListPQueue, bankQueue, customers);
            }
        }
        std::cout << "Final Statistics:\n";
        std::cout << "\tTotal number of people processed: " << customers.size() << std::endl;
        std::cout << "\tAverage amount of time spent waiting: " << getAverageWaitTime(customers) << std::endl;
    }

    // Processes an arrival event.
    void processArrival(    const Event& arrivalEvent,
                            std::priority_queue<Event>& eventListPQueue,
                            std::queue<Event>& bankQueue,
                            std::vector<Customer> & customers ) {
        std::cout << "Processing customer #" << arrivalEvent.customerID << " arrival at time: " << arrivalEvent.absoluteTime << std::endl;
        Customer customer;
        customer.customerID = arrivalEvent.customerID;
        customer.absoluteTime = arrivalEvent.absoluteTime;

        // Remove this event from the event list
        eventListPQueue.pop();

        //customer = customer referenced in arrivalEvent
        if (bankQueue.empty() && tellerAvailable) {
            double currentTime = arrivalEvent.absoluteTime;
            double departureTime = currentTime + arrivalEvent.duration;
            Event newDepartureEvent;
            newDepartureEvent.arrival       = false;
            newDepartureEvent.customerID    = customer.customerID;
            newDepartureEvent.duration      = 0;
            newDepartureEvent.absoluteTime  = departureTime;
            eventListPQueue.push(newDepartureEvent);
            tellerAvailable                 = false;
            customer.tellerTime             = currentTime;
            customer.departureTime          = departureTime;
        }
        else {
            bankQueue.push(arrivalEvent);
        }
        customers.push_back(customer);
    }

    // Processes a departure event .
    void processDeparture(  const Event& departureEvent, 
                            std::priority_queue<Event>& eventListPQueue,
                            std::queue<Event>& bankQueue,
                            std::vector<Customer>& customers) {
        std::cout << "Processing customer #" << departureEvent.customerID << " departure at time: " << departureEvent.absoluteTime << std::endl;
       
        double currentTime = departureEvent.absoluteTime;
        
        // Remove this event from the event list
        eventListPQueue.pop();
        if ( !bankQueue.empty() ) {
            // Customer at front of line begins transaction
            Event customer = bankQueue.front();
            bankQueue.pop();

            double departureTime    = currentTime + customer.duration;

            // find customer statistics
            // what should be the type?
            // auto finder = [customer](const Customer& inCust) { return inCust.customerID == customer.customerID; };
            std::vector<Customer>::iterator foundCustomer = std::find_if(
                                                                    begin(customers),
                                                                    end(customers),
                                                                    /*finder*/[customer](const Customer& inCust) { return inCust.customerID == customer.customerID; });
            foundCustomer->tellerTime = currentTime;
            foundCustomer->departureTime = departureTime;

            Event newDepartureEvent;
            newDepartureEvent.customerID = customer.customerID;
            newDepartureEvent.duration = 0;
            newDepartureEvent.absoluteTime = departureTime;
            newDepartureEvent.arrival = false;
            eventListPQueue.push(newDepartureEvent);
        }
        else {
            tellerAvailable = true;
        }
    }

    /// <summary>
    /// read Events into priority queue
    /// </summary>
    /// <param name="inputFile"></param>
    /// <param name="eventListPQueue"></param>
    void readEvents( std::string inputFile, std::priority_queue<Event>& eventListPQueue ) {
        std::ifstream infile;
        infile.open(inputFile, std::ios::in);
        if ( !infile.is_open() ) {
            std::cout << "Failed to open " << inputFile << std::endl;
            return;
        }
        std::cout << "File read " << inputFile << std::endl;
        int customerID = 1;
        do{
            Event newArrivalEvent;
            std::string line;
            if( std::getline(infile, line) ) {
                //std::cout << line << '\n';

                std::string::size_type sz;     // alias of size_t

                newArrivalEvent.absoluteTime =  std::stod(line, &sz);
                newArrivalEvent.duration    =  std::stod(line.substr(sz));
                newArrivalEvent.arrival     = true;
                newArrivalEvent.customerID = customerID;
                eventListPQueue.push(newArrivalEvent);
                customerID++;
            }
        } while ( !infile.eof() );
        infile.close();
    }
};

int main() {
    Matrix matrix;
    matrix.simulate("a26.2in1.txt");
    matrix.simulate("a26.2in2.txt");
}

/*
Simulation Begins
File read a26.2in1.txt
Processing customer #1 arrival at time: 1
Processing customer #2 arrival at time: 2
Processing customer #3 arrival at time: 4
Processing customer #1 departure at time: 6
Processing customer #2 departure at time: 11
Processing customer #3 departure at time: 16
Processing customer #4 arrival at time: 20
Processing customer #5 arrival at time: 22
Processing customer #6 arrival at time: 24
Processing customer #4 departure at time: 25
Processing customer #7 arrival at time: 26
Processing customer #8 arrival at time: 28
Processing customer #9 arrival at time: 30
Processing customer #5 departure at time: 30
Processing customer #6 departure at time: 35
Processing customer #7 departure at time: 40
Processing customer #8 departure at time: 45
Processing customer #9 departure at time: 50
Processing customer #10 arrival at time: 88
Processing customer #10 departure at time: 91
Final Statistics:
        Total number of people processed: 10
        Average amount of time spent waiting: 5.6


Simulation Begins
File read a26.2in2.txt
Processing customer #1 arrival at time: 5
Processing customer #2 arrival at time: 7
Processing customer #1 departure at time: 10
Processing customer #3 arrival at time: 13
Processing customer #2 departure at time: 17
Processing customer #4 arrival at time: 22
Processing customer #3 departure at time: 24
Processing customer #5 arrival at time: 26
Processing customer #6 arrival at time: 31
Processing customer #4 departure at time: 31
Processing customer #5 departure at time: 34
Processing customer #7 arrival at time: 35
Processing customer #6 departure at time: 38
Processing customer #7 departure at time: 42
Processing customer #8 arrival at time: 43
Processing customer #9 arrival at time: 45
Processing customer #8 departure at time: 45
Processing customer #10 arrival at time: 47
Processing customer #11 arrival at time: 51
Processing customer #9 departure at time: 51
Processing customer #10 departure at time: 54
Processing customer #12 arrival at time: 56
Processing customer #11 departure at time: 57
Processing customer #12 departure at time: 60
Processing customer #13 arrival at time: 61
Processing customer #14 arrival at time: 64
Processing customer #13 departure at time: 67
Processing customer #15 arrival at time: 70
Processing customer #16 arrival at time: 73
Processing customer #14 departure at time: 73
Processing customer #17 arrival at time: 77
Processing customer #15 departure at time: 77
Processing customer #18 arrival at time: 80
Processing customer #16 departure at time: 82
Processing customer #19 arrival at time: 86
Processing customer #17 departure at time: 87
Processing customer #20 arrival at time: 92
Processing customer #18 departure at time: 92
Processing customer #21 arrival at time: 97
Processing customer #19 departure at time: 97
Processing customer #20 departure at time: 100
Processing customer #22 arrival at time: 101
Processing customer #23 arrival at time: 107
Processing customer #21 departure at time: 108
Processing customer #24 arrival at time: 110
Processing customer #25 arrival at time: 113
Processing customer #22 departure at time: 115
Processing customer #26 arrival at time: 118
Processing customer #23 departure at time: 121
Processing customer #28 arrival at time: 123
Processing customer #27 arrival at time: 123
Processing customer #29 arrival at time: 126
Processing customer #24 departure at time: 128
Processing customer #30 arrival at time: 131
Processing customer #25 departure at time: 133
Processing customer #31 arrival at time: 136
Processing customer #26 departure at time: 136
Processing customer #32 arrival at time: 141
Processing customer #28 departure at time: 142
Processing customer #33 arrival at time: 147
Processing customer #27 departure at time: 150
Processing customer #34 arrival at time: 152
Processing customer #29 departure at time: 153
Processing customer #35 arrival at time: 160
Processing customer #30 departure at time: 160
Processing customer #36 arrival at time: 164
Processing customer #31 departure at time: 164
Processing customer #32 departure at time: 164
Processing customer #37 arrival at time: 169
Processing customer #33 departure at time: 169
Processing customer #34 departure at time: 171
Processing customer #35 departure at time: 176
Processing customer #36 departure at time: 176
Processing customer #38 arrival at time: 178
Processing customer #37 departure at time: 180
Processing customer #39 arrival at time: 184
Processing customer #38 departure at time: 186
Processing customer #40 arrival at time: 189
Processing customer #39 departure at time: 191
Processing customer #40 departure at time: 194
Processing customer #41 arrival at time: 195
Processing customer #41 departure at time: 196
Processing customer #42 arrival at time: 197
Processing customer #42 departure at time: 200
Processing customer #43 arrival at time: 201
Processing customer #44 arrival at time: 205
Processing customer #43 departure at time: 206
Processing customer #44 departure at time: 208
Processing customer #45 arrival at time: 211
Processing customer #46 arrival at time: 216
Processing customer #45 departure at time: 217
Processing customer #46 departure at time: 222
Processing customer #47 arrival at time: 223
Processing customer #47 departure at time: 225
Processing customer #48 arrival at time: 230
Processing customer #48 departure at time: 233
Processing customer #49 arrival at time: 235
Processing customer #50 arrival at time: 238
Processing customer #49 departure at time: 240
Processing customer #50 departure at time: 243
Final Statistics:
        Total number of people processed: 50
        Average amount of time spent waiting: 6.38
*/