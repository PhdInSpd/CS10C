/*
student: Jose Alfredo Martinez
instructor : Dave Harden
class : CS 10C
    file name : pairClient.cpp
date: Jan 20, 2022

what the program does and how the code works :
    Test if pairClient is able to handle multiple type creation and if exceptions is thrown when expected.

expected user input :
    enter two number used to initialize and order pair

program output :
    the default value after constructor call of OrderedPair<int>
    A MAX_LIST_SIZE list of OrderedPair<int> are printed.
    An exception is logged if the 2 numbers entered are equal and not zero.
    The output for a created OrderdPair<string> is displayed
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "orderedpair.h"
using namespace std;
using namespace cs_pairs;

const int MAX_LIST_SIZE = 10;






int main() {
   
    OrderedPair<int> myList[MAX_LIST_SIZE];

    srand(static_cast<unsigned>(time(0)));
    cout << "default value: ";
    myList[0].print();
    cout << endl;

    for (int i = 0; i < MAX_LIST_SIZE; i++) {
        myList[i].setFirst(rand() % 50);
        myList[i].setSecond(rand() % 50 + 50);
    }

    myList[2] = myList[0] + myList[1];

    if (myList[0] < myList[1]) {
        myList[0].print();
        cout << " is less than ";
        myList[1].print();
        cout << endl;
    }

    for (int i = 0; i < MAX_LIST_SIZE; i++) {
        myList[i].print();
        cout << endl;
    }

    int num1, num2;
    cout << "Enter two numbers to use in an OrderedPair.  Make sure they are different numbers: ";
    cin >> num1 >> num2;
    OrderedPair<int> x;

    // exception handling for similar non default value
    try {
        x.setFirst(num1);
        x.setSecond(num2);
        
    } catch (OrderedPair<int>::DuplicateMemberError e) {
        cout << "Error, you attempted to set both members of the OrderedPair to the same number."
             << endl;
        x.setFirst(OrderedPair<int>::DEFAULT_VALUE);
        x.setSecond(OrderedPair<int>::DEFAULT_VALUE);
    }

    cout << "The resulting int OrderedPair: ";
    x.print();
    cout << endl;

    // string template
    string stringNum1, stringNum2;
    string empty = "";
    OrderedPair<string> myStringPair;
    myStringPair.setFirst(empty + char('a' + rand() % 26));
    myStringPair.setSecond(empty + char('A' + rand() % 26));

    cout << "The resulting string OrderedPair: ";
    myStringPair.print();
    cout << endl;
    return 0;
}