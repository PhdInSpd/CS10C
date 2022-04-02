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

	const int  CHUNK_SIZE = 4;
	for (size_t i = 0; i < MAX_SIZE; i++) {
		for (size_t j = 0; j < CHUNK_SIZE; j++)
		{
			queue1.enqueue(i);
		}
		for (size_t j = 0; j < CHUNK_SIZE/2; j++)
		{
			queue1.dequeue();
		}	
	}
	queue1.print();
	std::cout << std::endl;

}

