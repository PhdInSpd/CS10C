//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include "LinkedSet.h"
using namespace std;
using namespace cs_set;

void displaySet(LinkedSet<string>& set) {
    vector<string> setItems = set.toVector();

    int numberOfEntries = setItems.size();
    for (int i = 0; i < numberOfEntries; i++) {
        cout << setItems[i] << " ";
    }
}






void copyConstructorTester()
{
    cout << "Testing copy constructor:" << endl;
    LinkedSet<string> set;
    string items[] = { "zero", "one", "two", "three", "four", "five" };
    for (int i = 0; i < 6; i++) {
        cout << "Adding " << items[i] << endl;
        set.add(items[i]);
    }

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






void setTester() {
    LinkedSet<string> set;
    cout << "Testing the Link-Based Set:" << endl;
    cout << "isEmpty: returns " << set.isEmpty()
        << "; should be 1 (true)" << endl;
    displaySet(set);
    cout << endl;

    string items[] = { "one", "two", "three", "four", "five", "one" };
    cout << "Add 6 items to the set: " << endl;
    for (int i = 0; i < 6; i++) {
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
    /*cout << "getFrequencyOf(\"one\"): returns "
        << set.getFrequencyOf("one") << " should be 2" << endl;*/


    try {
        cout << "remove(\"one\")... ";
        set.remove("one");
        cout << "shouldn't cause exception and didn't!" << endl;
    }
    catch (LinkedSet<string>::ItemNotFoundError e) {
        cout << "shouldn't cause exception but did." << endl;
    }

    /*cout << "getFrequencyOf(\"one\"): returns "
        << set.getFrequencyOf("one") << " should be 1" << endl;*/


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





int main() {
    copyConstructorTester();
    setTester();
}