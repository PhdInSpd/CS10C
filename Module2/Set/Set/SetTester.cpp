/*
    student: Jose Alfredo Martinez
    instructor : Dave Harden
    class : CS 10C
    date : Jan 21, 2022
*/

#include <iostream>
#include <string>
#include "ArraySet.h"

using std::cout;
using std::endl;
using std::string;
using namespace cs_set;

void displaySet(ArraySet<string>& set, const std::string & setName="") {
    if ( !setName.empty() ) {
        cout << setName<< " ";
    }
    cout << "The set contains " << set.getCurrentSize()
        << " items:" << endl;
    std::vector<string> setItems = set.toVector();

    int numEntries = setItems.size();
    for (int i = 0; i < numEntries; i++) {
        cout << setItems[i] << " ";
    }
    cout << endl << endl;
}





void setTester(ArraySet<string>& set) {
    cout << "isEmpty: returns " << set.isEmpty()
        << "; should be 1 (true)" << endl;
    displaySet(set);

    std::vector<std::string> items = { "one", "two", "three", "four", "five", "six" };
    cout << "Add "<< items.size() << " unique items to the set : " << endl;
    for (size_t i = 0; i < items.size(); i++) {
        set.add(items[i]);
    }

    displaySet(set);

    cout << "isEmpty: returns " << set.isEmpty()
        << "; should be 0 (false)" << endl;

    cout << "getCurrentSize: returns " << set.getCurrentSize()
        << "; should be " << items.size() << endl;

    try {
        cout << "Try to add another entry: add(\"extra\")... ";
        set.add("extra");
        cout << "should cause exception but didn't" << endl;
    }
    catch (ArraySet<string>::CapacityExceededError e) {
        cout << "should cause exception and did!" << endl;
    }

    try {
        cout << "remove(\"one\")... ";
        set.remove("one");
        cout << "shouldn't cause exception and didn't!" << endl;
    }
    catch (ArraySet<string>::ItemNotFoundError e) {
        cout << "shouldn't cause exception but did." << endl;
    }

    try {
        cout << "Try to add a copy entry: add(\"six\")... ";
        set.add("six");
        cout << "should cause exception but didn't" << endl;
    }
    catch (ArraySet<string>::DuplicateItemError e) {
        cout << "should cause exception and did!" << endl;
    }

    cout << "contains(\"three\"): returns " << set.contains("three")
        << "; should be 1 (true)" << endl;
    cout << "contains(\"ten\"): returns " << set.contains("ten")
        << "; should be 0 (false)" << endl;

    try {
        cout << "remove(\"one\")... ";
        set.remove("one");
        cout << "should cause exception but didn't" << endl;
    }
    catch (ArraySet<string>::ItemNotFoundError e) {
        cout << "should cause exception and did!" << endl;
    }

    cout << endl;

    displaySet(set);

    cout << "After clearing the set, ";
    set.clear();
    cout << "isEmpty: returns " << set.isEmpty()
         << "; should be 1 (true)" << endl;
}






void testSetUnion() {
    cout << "testSetUnion" << endl;
    ArraySet<string> setA;
    ArraySet<string> setB;
    ArraySet<string> setC;

    setA.add({ "one", "two", "three" } );
    setB.add({ "four", "five", "six" } );
    setC.add({ "seven", "eight", "nine", "ten"} );

    displaySet( setA, "setA" );
    displaySet( setB, "setB" );
    displaySet( setC, "setC" );

    ArraySet<string> unionAB = setA.setUnion(setB);
    displaySet(unionAB, "unionAB");

    try {
        ArraySet<string> unionBC = setB.setUnion(setC);
        displaySet(unionBC, "unionBC");
    }
    catch (ArraySet<string>::CapacityExceededError e) {
        cout << "unionBC capacityExceededError" << endl;
    }
}





void testSetIntersection() {
    cout << "testSetIntersection" << endl;
    ArraySet<string> setA;
    ArraySet<string> setB;

    setA.add({ "one", "two", "three","four", "five", "six" });
    setB.add({ "four", "five", "six" });

    displaySet(setA, "setA");
    displaySet(setB, "setB");

    ArraySet<string> intAB = setA.setIntersection(setB);
    displaySet(intAB, "intAB");
}






void testSetDifference() {
    cout << "testSetDifference" << endl;
    ArraySet<string> setA;
    ArraySet<string> setB;

    setA.add({ "one", "two", "three","four", "five", "six" });
    setB.add({ "four", "five", "six" });

    displaySet(setA, "setA");
    displaySet(setB, "setB");

    ArraySet<string> diffAB = setA.setDifference(setB);
    displaySet(diffAB, "differenceAB");
}







int main() {
    ArraySet<string> set;
    cout << "Testing the Array-Based Set:" << endl;
    cout << "The initial set is empty." << endl;
    setTester(set);
    testSetUnion();
    testSetIntersection();
    testSetDifference();
    cout << "All done!" << endl;
}
