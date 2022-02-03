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
	const int STACK_SIZE = 20;
	int inMemoryChunk = 0;
	ArrayStack<string> stackDouble(inMemoryChunk);
	cout << "capacity should double" << endl;
	for (size_t i = 0; i < STACK_SIZE; i++) {
		stringstream ss;
		ss << i;
		string number = ss.str();
		stackDouble.push(number);
		cout << i << ":i "
			<< stackDouble.top() << ":top "
			<< stackDouble.getCapacity() << ":capacity "
			<< stackDouble.getNumItems() << ":getNumItems "
			<< endl;
	}

	inMemoryChunk = 2;
	ArrayStack<string> stack3K(inMemoryChunk);
	cout << "capacity increase by (2n+1)*" << inMemoryChunk << endl;
	for (size_t i = 0; i < STACK_SIZE; i++) {
		stringstream ss;
		ss << i * 10;
		string number = ss.str();
		stack3K.push(number);
		cout << i << ":i "
			<< stack3K.top() << ":top "
			<< stack3K.getCapacity() << ":capacity "
			<< stack3K.getNumItems() << ":getNumItems "
			<< endl;
	};

	//test copy constructor
	ArrayStack<string> copied(stackDouble);


	//test assignment operator
	ArrayStack<string> assignment;
	assignment = stack3K;

	//test 
	printStack("print original stackDouble", stackDouble);
	printStack("print copy of stackDouble", copied);

	printStack("print original stack3K", stack3K);
	printStack("print assignment of stack3K", assignment);

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

