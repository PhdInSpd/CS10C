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

    /* use this before you've implemented the exception handling in the class:
    */

   /* x.setFirst(num1);
    x.setSecond(num2);*/

    // use this after you've implemented the exception handling in the class:
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
}