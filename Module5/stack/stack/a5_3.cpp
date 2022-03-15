/*
student   : Jose Alfredo Martinez
instructor: Dave Harden
class     : CS 10C
date      : Feb 02, 2022
file name : a5_3.cpp

test the arrayStack.h 
*/
#include <iostream>
#include <sstream>
#include <string>

#include "arrayStack.h"
using namespace std;
using namespace cs_stack;

void testStack();

template<typename T>
void printStack(string message, ArrayStack<T>& printMe);

int main() {
	testStack();
}



template<typename T>
void printStack(string message, ArrayStack<T>& printMe) {
	cout << message << endl;
	while (!printMe.isEmpty()) {
		cout << printMe.top() << endl;
		printMe.pop();
	}
}

void testStack() {

	// capacity double test
	const int STACK_SIZE = 32;
	ArrayStack<string> stackDouble;
	cout << "stack is empty:" << stackDouble.isEmpty() << endl;
	cout << "push test" << endl;
	size_t i;
	for (i = 0; i < STACK_SIZE; i++) {
		stringstream ss;
		ss << i;
		string number = ss.str();
		stackDouble.push(number);
		cout << i << ":i "
			<< stackDouble.top() << ":top "
			<< stackDouble.getCapacity() << ":capacity "
			<< stackDouble.getNumItems() << ":getNumItems() "
			<< endl;
	}
	cout << "pop test" << endl;
	for (i = 0; i < STACK_SIZE; i++) {
		
		stackDouble.pop();
		if (!stackDouble.isEmpty()) {
			cout << i << ":i "
				<< stackDouble.top() << ":top "
				<< stackDouble.getCapacity() << ":capacity "
				<< stackDouble.getNumItems() << ":getNumItems() "
				<< endl;
		}
		else {
			cout << i << ":i "
				<< "empty" << ":top "
				<< stackDouble.getCapacity() << ":capacity "
				<< stackDouble.getNumItems() << ":getNumItems() "
				<< endl;
		}
		
	}
	for (i = 0; i < STACK_SIZE; i++) {
		stringstream ss;
		ss << i;
		string number = ss.str();
		stackDouble.push(number);
		cout << i << ":i "
			<< stackDouble.top() << ":top "
			<< stackDouble.getCapacity() << ":capacity "
			<< stackDouble.getNumItems() << ":getNumItems() "
			<< endl;
	}
	

	cout << "stack is empty:" << stackDouble.isEmpty() << endl;

		


	//test copy constructor
	ArrayStack<string> copied(stackDouble);


	//test assignment operator
	ArrayStack<string> assignment;
	assignment = stackDouble;

	//test 
	printStack("print original stackDouble", stackDouble);
	printStack("print copy of stackDouble", copied);

	// pop
	cout << "pop test" << endl;
	for (size_t i = 0; !stackDouble.isEmpty(); i++) {
		cout << stackDouble.top() << ":top "
			<< stackDouble.getCapacity() << ":capacity "
			<< stackDouble.getNumItems() << ":getNumItems() "
			<< endl;
		stackDouble.pop();
	}




	// test exception
	stackDouble.push("salt n peppa");
	try {
		cout << "first pop should not throw exception" << endl;
		stackDouble.pop();
		cout << "no exception" << endl;
	}
	catch (ArrayStack<string>::StackEmptyError e) {
		cout << "StackEmptyError exception" << endl;
	}

	try {
		cout << "2nd pop should  throw exception" << endl;
		stackDouble.pop();
		cout << "no exception" << endl;
	}
	catch (ArrayStack<string>::StackEmptyError e) {
		cout << "StackEmptyError exception" << endl;
	}
}
