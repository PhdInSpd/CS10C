// circularQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

