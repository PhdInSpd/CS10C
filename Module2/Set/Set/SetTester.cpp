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
    ArraySet<string> setD;

    setA.add({ "one", "two", "three" } );
    setD.add({ "one", "five", "seven" });

    setB.add({ "four", "five", "six" } );
    setC.add({ "seven", "eight", "nine", "ten"} );

    displaySet( setA, "setA" );
    displaySet( setB, "setB" );
    displaySet( setC, "setC" );
    displaySet( setD, "setD");

    ArraySet<string> unionAB = setA.setUnion(setB);
    displaySet(unionAB, "unionAB");

    ArraySet<string> unionBC;
    try {
        ArraySet<string> unionBC = setB.setUnion(setC);
        displaySet(unionBC, "unionBC");
    }
    catch (ArraySet<string>::CapacityExceededError e) {
        cout << "unionBC capacityExceededError" << endl;
    }

    ArraySet<string> unionAD;
    try {
        ArraySet<string> unionAD = setA.setUnion(setD);
        displaySet(unionAD, "unionAD");
        cout << "unionAD no exception thrown" << endl;
    }
    catch (ArraySet<string>::DuplicateItemError) {
        cout << "unionAD DuplicateItemError" << endl;
    }

    try {
        ArraySet<string> unionDA = setA.setUnion(setA);
        displaySet(unionDA, "unionDA");
        cout << "unionAD no exception thrown" << endl;
    }
    catch (ArraySet<string>::DuplicateItemError) {
        cout << "unionDA DuplicateItemError" << endl;
    }

    ArraySet<string> set1;
    ArraySet<string> set2;
    set1.add({ "6", "5", "0", "2", "8" });
    set2.add( "6");

    try {
        ArraySet<string> union12 = set1.setUnion(set2);
        displaySet(union12, "union12");
        cout << "union12 no exception thrown" << endl;
    }
    catch (ArraySet<string>::DuplicateItemError) {
        cout << "union12 DuplicateItemError" << endl;
    }
    
    try {
        ArraySet<string> union21 = set2.setUnion(set1);
        displaySet(union21, "union21");
        cout << "union21 no exception thrown" << endl;
    }
    catch (ArraySet<string>::DuplicateItemError) {
        cout << "union21 DuplicateItemError" << endl;
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


/*
Testing the Array-Based Set:
The initial set is empty.
isEmpty: returns 1; should be 1 (true)
The set contains 0 items:


Add 6 unique items to the set :
The set contains 6 items:
one two three four five six

isEmpty: returns 0; should be 0 (false)
getCurrentSize: returns 6; should be 6
Try to add another entry: add("extra")... should cause exception and did!
remove("one")... shouldn't cause exception and didn't!
Try to add a copy entry: add("six")... should cause exception and did!
contains("three"): returns 1; should be 1 (true)
contains("ten"): returns 0; should be 0 (false)
remove("one")... should cause exception and did!

The set contains 5 items:
six two three four five

After clearing the set, isEmpty: returns 1; should be 1 (true)
testSetUnion
setA The set contains 3 items:
one two three

setB The set contains 3 items:
four five six

setC The set contains 4 items:
seven eight nine ten

setD The set contains 3 items:
one size seven

unionAB The set contains 6 items:
one two three four five six

unionBC capacityExceededError
unionAD DuplicateItemError
unionDA DuplicateItemError
union12 DuplicateItemError
union21 DuplicateItemError
testSetIntersection
setA The set contains 6 items:
one two three four five six

setB The set contains 3 items:
four five six

intAB The set contains 3 items:
four five six

testSetDifference
setA The set contains 6 items:
one two three four five six

setB The set contains 3 items:
four five six

differenceAB The set contains 3 items:
one two three

All done!
*/