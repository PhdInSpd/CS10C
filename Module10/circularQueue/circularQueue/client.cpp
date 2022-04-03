/*
student: Jose Alfredo Martinez
instructor : Dave Harden
class : CS 10C
date : April 02, 2022
file name : client.cpp
description: client to test assignment 10.1 circular queue that dynamicly resizes
*/


#include <iostream>
#include "ArrayQueue.h"

const int MAX_SIZE = 33;
int main() {
    std::cout << "ArrayQueue test\n";
    ArrayQueue<int> queue1;
	std::cout << "cap: " << queue1.getCapacity() << std::endl;
	for (size_t i = 0; i < MAX_SIZE; i++) {
		queue1.enqueue(i);
		std::cout << "cap: " << queue1.getCapacity() << std::endl;
	}
	queue1.print();

	for (size_t i = 0; i < MAX_SIZE; i++) {
		queue1.dequeue();
		std::cout << "cap: " << queue1.getCapacity() << std::endl;
	}
	queue1.print();
	std::cout << std::endl;

	try
	{
		queue1.dequeue();
		std::cout << "dequeue did not throw exception" << std::endl;
	}
	catch (PrecondViolatedExcep vio) {
		std::cout << "dequeue did throw exception" << std::endl;
	}

	auto queue2 = queue1;

	const int  CHUNK_SIZE = 4;
	for (size_t i = 0; i < MAX_SIZE; i++) {
		for (size_t j = 0; j < CHUNK_SIZE; j++) {
			queue1.enqueue(i);
		}
		std::cout << "be "; queue1.print(); std::cout << std::endl;
		for (size_t j = 0; j < CHUNK_SIZE/2; j++) {
			queue1.dequeue();
		}	
		std::cout << "bd "; queue1.print(); std::cout << std::endl;
	}
	queue1.print();
	std::cout << std::endl;

	ArrayQueue<int> aoOfQueue1;
	for (size_t i = 0; i < MAX_SIZE; i++) {
		aoOfQueue1.enqueue(2*i);
	}
	
	{

		ArrayQueue<int> ccOfQueue1(aoOfQueue1);
		std::cout << "cc"; ccOfQueue1.print(); std::cout << std::endl;
	}
	std::cout << "before assignment"; aoOfQueue1.print(); std::cout << std::endl;
	aoOfQueue1 = queue1;
	std::cout << "after assignment"; aoOfQueue1.print(); std::cout << std::endl;

}

/*
output:
ArrayQueue test
cap: 1
cap: 1
cap: 2
cap: 4
cap: 4
cap: 8
cap: 8
cap: 8
cap: 8
cap: 16
cap: 16
cap: 16
cap: 16
cap: 16
cap: 16
cap: 16
cap: 16
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 64
Here is the queue: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 32
cap: 16
cap: 16
cap: 16
cap: 16
cap: 16
cap: 16
cap: 16
cap: 16
cap: 8
cap: 8
cap: 8
cap: 8
cap: 4
cap: 4
cap: 2
cap: 1
cap: 0
Here is the queue: empty
dequeue did throw exception
be Here is the queue: 0 0 0 0
bd Here is the queue: 0 0
be Here is the queue: 0 0 1 1 1 1
bd Here is the queue: 1 1 1 1
be Here is the queue: 1 1 1 1 2 2 2 2
bd Here is the queue: 1 1 2 2 2 2
be Here is the queue: 1 1 2 2 2 2 3 3 3 3
bd Here is the queue: 2 2 2 2 3 3 3 3
be Here is the queue: 2 2 2 2 3 3 3 3 4 4 4 4
bd Here is the queue: 2 2 3 3 3 3 4 4 4 4
be Here is the queue: 2 2 3 3 3 3 4 4 4 4 5 5 5 5
bd Here is the queue: 3 3 3 3 4 4 4 4 5 5 5 5
be Here is the queue: 3 3 3 3 4 4 4 4 5 5 5 5 6 6 6 6
bd Here is the queue: 3 3 4 4 4 4 5 5 5 5 6 6 6 6
be Here is the queue: 3 3 4 4 4 4 5 5 5 5 6 6 6 6 7 7 7 7
bd Here is the queue: 4 4 4 4 5 5 5 5 6 6 6 6 7 7 7 7
be Here is the queue: 4 4 4 4 5 5 5 5 6 6 6 6 7 7 7 7 8 8 8 8
bd Here is the queue: 4 4 5 5 5 5 6 6 6 6 7 7 7 7 8 8 8 8
be Here is the queue: 4 4 5 5 5 5 6 6 6 6 7 7 7 7 8 8 8 8 9 9 9 9
bd Here is the queue: 5 5 5 5 6 6 6 6 7 7 7 7 8 8 8 8 9 9 9 9
be Here is the queue: 5 5 5 5 6 6 6 6 7 7 7 7 8 8 8 8 9 9 9 9 10 10 10 10
bd Here is the queue: 5 5 6 6 6 6 7 7 7 7 8 8 8 8 9 9 9 9 10 10 10 10
be Here is the queue: 5 5 6 6 6 6 7 7 7 7 8 8 8 8 9 9 9 9 10 10 10 10 11 11 11 11
bd Here is the queue: 6 6 6 6 7 7 7 7 8 8 8 8 9 9 9 9 10 10 10 10 11 11 11 11
be Here is the queue: 6 6 6 6 7 7 7 7 8 8 8 8 9 9 9 9 10 10 10 10 11 11 11 11 12 12 12 12
bd Here is the queue: 6 6 7 7 7 7 8 8 8 8 9 9 9 9 10 10 10 10 11 11 11 11 12 12 12 12
be Here is the queue: 6 6 7 7 7 7 8 8 8 8 9 9 9 9 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13
bd Here is the queue: 7 7 7 7 8 8 8 8 9 9 9 9 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13
be Here is the queue: 7 7 7 7 8 8 8 8 9 9 9 9 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14
bd Here is the queue: 7 7 8 8 8 8 9 9 9 9 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14
be Here is the queue: 7 7 8 8 8 8 9 9 9 9 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15
bd Here is the queue: 8 8 8 8 9 9 9 9 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15
be Here is the queue: 8 8 8 8 9 9 9 9 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16
bd Here is the queue: 8 8 9 9 9 9 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16
be Here is the queue: 8 8 9 9 9 9 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17
bd Here is the queue: 9 9 9 9 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17
be Here is the queue: 9 9 9 9 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18
bd Here is the queue: 9 9 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18
be Here is the queue: 9 9 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19
bd Here is the queue: 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19
be Here is the queue: 10 10 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20
bd Here is the queue: 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20
be Here is the queue: 10 10 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21
bd Here is the queue: 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21
be Here is the queue: 11 11 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22
bd Here is the queue: 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22
be Here is the queue: 11 11 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23
bd Here is the queue: 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23
be Here is the queue: 12 12 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24
bd Here is the queue: 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24
be Here is the queue: 12 12 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25
bd Here is the queue: 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25
be Here is the queue: 13 13 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26
bd Here is the queue: 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26
be Here is the queue: 13 13 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26 27 27 27 27
bd Here is the queue: 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26 27 27 27 27
be Here is the queue: 14 14 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26 27 27 27 27 28 28 28 28
bd Here is the queue: 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26 27 27 27 27 28 28 28 28
be Here is the queue: 14 14 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26 27 27 27 27 28 28 28 28 29 29 29 29
bd Here is the queue: 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26 27 27 27 27 28 28 28 28 29 29 29 29
be Here is the queue: 15 15 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26 27 27 27 27 28 28 28 28 29 29 29 29 30 30 30 30
bd Here is the queue: 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26 27 27 27 27 28 28 28 28 29 29 29 29 30 30 30 30
be Here is the queue: 15 15 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26 27 27 27 27 28 28 28 28 29 29 29 29 30 30 30 30 31 31 31 31
bd Here is the queue: 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26 27 27 27 27 28 28 28 28 29 29 29 29 30 30 30 30 31 31 31 31
be Here is the queue: 16 16 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26 27 27 27 27 28 28 28 28 29 29 29 29 30 30 30 30 31 31 31 31 32 32 32 32
bd Here is the queue: 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26 27 27 27 27 28 28 28 28 29 29 29 29 30 30 30 30 31 31 31 31 32 32 32 32
Here is the queue: 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26 27 27 27 27 28 28 28 28 29 29 29 29 30 30 30 30 31 31 31 31 32 32 32 32
ccHere is the queue: 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 52 54 56 58 60 62 64
before assignmentHere is the queue: 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 52 54 56 58 60 62 64
after assignmentHere is the queue: 16 16 17 17 17 17 18 18 18 18 19 19 19 19 20 20 20 20 21 21 21 21 22 22 22 22 23 23 23 23 24 24 24 24 25 25 25 25 26 26 26 26 27 27 27 27 28 28 28 28 29 29 29 29 30 30 30 30 31 31 31 31 32 32 32 32

*/