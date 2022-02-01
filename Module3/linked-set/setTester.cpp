//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
/*
student   : Jose Alfredo Martinez
instructor: Dave Harden
class     : CS 10C
date      : Jan 25, 2022
file name : setTester.cpp

the client test the SetInterface.h implementation

expected user input: None

program output: results from testing union, intersection , difference,
    class assignment, copy contructor, and general set functionaly test.
*/

#include <iostream>
#include <string>
#include "LinkedSet.h"
using namespace std;
using namespace cs_set;

void displaySet( LinkedSet<string>& set, const std::string& setName = "") {
    if (!setName.empty()) {
        cout << setName << " ";
    }
    vector<string> setItems = set.toVector();

    int numberOfEntries = setItems.size();
    for (int i = 0; i < numberOfEntries; i++) {
        cout << setItems[i] << " ";
    }
    cout << endl;
}






void copyConstructorTester() {
    cout << "Testing copy constructor:" << endl;
    LinkedSet<string> set;
    set.add({ "zero", "one", "two", "three", "four", "five" });

    cout << "The original set: ";
    displaySet(set);
    cout << endl;

    LinkedSet<string> copyOfSet(set);
    cout << "Copy of set: ";
    displaySet(copyOfSet);
    cout << endl;

    cout << "Removing 'one' from copy of set." << endl;
    copyOfSet.remove("one");

    cout << "The original set: ";
    displaySet(set);
    cout << endl;

    cout << "Copy of set: ";
    displaySet(copyOfSet);
    cout << endl;
}






void assignmentTester() {
    cout << "Testing assignment:" << endl;
    LinkedSet<string> set;
    set.add({ "zero", "one", "two", "three", "four", "five", "six", "seven" });

    cout << "The original set: ";
    displaySet(set);
    cout << endl;

    LinkedSet<string> setAss;
    setAss.add("ten");
    setAss = set;
    cout << "assignment of set: ";
    displaySet(setAss);
    cout << endl;

}






void setTester() {
    LinkedSet<string> set;
    cout << "Testing the Link-Based Set:" << endl;
    cout << "isEmpty: returns " << set.isEmpty()
        << "; should be 1 (true)" << endl;
    displaySet(set);
    cout << endl;

    std::vector<string> items = { "one", "two", "three", "four", "five", "one" };
    cout << "Add " << items.size() << " items to the set : " << endl;
    for (int i = 0; i < items.size(); i++) {
        try {
            set.add(items[i]);
        }
        catch (LinkedSet<string>::DuplicateItemError e) {
            cout << "DuplicateItemError adding item " << items[i] << endl;
        }
    }

    displaySet(set);
    cout << endl;

    cout << "isEmpty: returns " << set.isEmpty()
        << "; should be 0 (false)" << endl;

    cout << "getCurrentSize: returns " << set.getCurrentSize()
        << "; should be 5" << endl;

    cout << "Add another entry: add(\"extra\") " << endl;
    set.add("extra");

    cout << "contains(\"three\"): returns " << set.contains("three")
        << "; should be 1 (true)" << endl;
    cout << "contains(\"ten\"): returns " << set.contains("ten")
        << "; should be 0 (false)" << endl;


    try {
        cout << "remove(\"one\")... ";
        set.remove("one");
        cout << "shouldn't cause exception and didn't!" << endl;
    }
    catch (LinkedSet<string>::ItemNotFoundError e) {
        cout << "shouldn't cause exception but did." << endl;
    }


    try {
        cout << "remove(\"one\")... ";
        set.remove("one");
        cout << "should cause exception but didn't" << endl;
    }
    catch (LinkedSet<string>::ItemNotFoundError e) {
        cout << "should cause exception and did!" << endl;
    }
    cout << endl;

    displaySet(set);
    cout << endl;

    cout << "After clearing the set, ";
    set.clear();

    cout << "isEmpty: returns " << set.isEmpty()
        << "; should be 1 (true)" << endl;
}






void testSetUnion() {
    cout << "testSetUnion" << endl;
    LinkedSet<string> setA;
    LinkedSet<string> setB;
    LinkedSet<string> setC;

    setA.add({ "one", "two", "three" });
    setB.add({ "four", "five", "six" });
    setC.add({ "seven", "eight", "nine", "ten" });

    displaySet(setA, "setA");
    displaySet(setB, "setB");
    displaySet(setC, "setC");

    LinkedSet<string> unionAB = setA.setUnion(setB);
    displaySet(unionAB, "unionAB");

    LinkedSet<string> unionBC = setB.setUnion(setC);
    displaySet(unionBC, "unionBC");
}






void testSetIntersection() {
    cout << "testSetIntersection" << endl;
    LinkedSet<string> setA;
    LinkedSet<string> setB;

    setA.add({ "one", "two", "three","four", "five", "six" });
    setB.add({ "four", "five", "six" });

    displaySet(setA, "setA");
    displaySet(setB, "setB");

    LinkedSet<string> intAB = setA.setIntersection(setB);
    displaySet(intAB, "intAB");
}






void testSetDifference() {
    cout << "testSetDifference" << endl;
    LinkedSet<string> setA;
    LinkedSet<string> setB;

    setA.add({ "one", "two", "three","four", "five", "six" });
    setB.add({ "four", "five", "six" });

    displaySet(setA, "setA");
    displaySet(setB, "setB");

    LinkedSet<string> diffAB = setA.setDifference(setB);
    displaySet(diffAB, "differenceAB");
}






int main() {
    testSetUnion();
    testSetIntersection();
    testSetDifference();

    assignmentTester();
    copyConstructorTester();
    setTester();
}

/*
testSetUnion
setA three two one
setB six five four
setC ten nine eight seven
unionAB four five six one two three
unionBC seven eight nine ten four five six
testSetIntersection
setA six five four three two one
setB six five four
intAB four five six
testSetDifference
setA six five four three two one
setB six five four
differenceAB one two three
Testing assignment:
The original set: seven six five four three two one zero

assignment of set: seven six five four three two one zero

Testing copy constructor:
The original set: five four three two one zero

Copy of set: five four three two one zero

Removing 'one' from copy of set.
The original set: five four three two one zero

Copy of set: four three two five zero

Testing the Link-Based Set:
isEmpty: returns 1; should be 1 (true)


Add 6 items to the set :
DuplicateItemError adding item one
five four three two one

isEmpty: returns 0; should be 0 (false)
getCurrentSize: returns 5; should be 5
Add another entry: add("extra")
contains("three"): returns 1; should be 1 (true)
contains("ten"): returns 0; should be 0 (false)
remove("one")... shouldn't cause exception and didn't!
remove("one")... should cause exception and did!

five four three two extra

After clearing the set, isEmpty: returns 1; should be 1 (true)

*/