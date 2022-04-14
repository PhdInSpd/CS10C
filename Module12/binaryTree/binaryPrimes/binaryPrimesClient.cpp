/*
student   : Jose Alfredo Martinez
instructor : Dave Harden
class : CS 10C
	date : April 13, 2022
	file name : binaryPrimesClient.cpp
*/
#include <iostream>
#include <string>
#include "binarytree.h"
using namespace std;

void testBinaryPrimes();

int main() {
	testBinaryPrimes();
}

int getRandomPrime() {
	bool done = false;
	int r=0;
	while (!done) {
		r = rand();
		done = binarytree::isPrime(r);
	}
	return r;
}
void testBinaryPrimes() {
	binarytree myTree;
	for (int i = 0; i < 20; i++) {
		myTree.insert( rand() % 100/*getRandomPrime()*/ );
	}

	cout << "size of binary tree: " << myTree.size() << endl;
	cout << "The binary tree: ";
	myTree.print();
	cout << endl;

	LL<int> myList;
	myList = myTree.toLL();

	cout << "The linked list: ";

	// if you haven't studied iterators yet, the following may not make sense  Don't worry.
	// You just have to know that this for loop prints the contents of myList.
	for (LL<int>::iterator i = myList.begin(); i != myList.end(); i++) {
		std::string primeIndicator = "";
		if ( binarytree::isPrime(*i) ) {
			primeIndicator = "*";
		}
		cout << *i << primeIndicator << " ";
	}
	cout << endl;

	cout << "noPrimes:" << myTree.numPrimes() << endl;

	// remove all primes from tree
	for (LL<int>::iterator i = myList.begin(); i != myList.end(); i++) {
		std::string primeIndicator = "";
		if (binarytree::isPrime(*i)) {
			bool found = false;
			myTree.del(*i,found);
		}
	}
	cout << "no Primes:"; myTree.print(); cout << endl;
	cout << "noPrimes(" << myTree.size() << "):" << myTree.numPrimes() << endl;


	{
		binarytree copy(myTree);
		cout << "copy(" << copy.size() << "):"; copy.print(); cout << endl;

		LL<int> myCopyList = copy.toLL();
		int count=0;
		int target = (int)myCopyList.size() / 2;
		for (LL<int>::iterator i = myCopyList.begin(); count < target; i++, count++) {
			bool found = false;
			copy.del(*i, found);
		}

		cout << "copy with half removed:(" << copy.size() << ")"; copy.print(); cout << endl;
		cout << "noPrimes:(" << myTree.size() << ")"; myTree.print(); cout << endl;

		myTree = copy;
		cout << "myTree gets copy:(" << myTree.size() << ")"; myTree.print(); cout << endl;
	}
	cout << "The original binary tree still intact: ";
	myTree.print();

	cout << endl;
}


/*
size of binary tree: 20
The binary tree: 0 5 24 27 27 34 36 41 42 45 58 61 62 64 67 69 78 81 91 95
The linked list: 0 5* 24 27 27 34 36 41* 42 45 58 61* 62 64 67* 69 78 81 91 95
noPrimes:4
no Primes:0 24 27 27 34 36 42 45 58 62 64 69 78 81 91 95
noPrimes(16):0
copy(16):0 24 27 27 34 36 42 45 58 62 64 69 78 81 91 95
copy with half removed:(8)58 62 64 69 78 81 91 95
noPrimes:(16)0 24 27 27 34 36 42 45 58 62 64 69 78 81 91 95
myTree gets copy:(8)58 62 64 69 78 81 91 95
The original binary tree still intact: 58 62 64 69 78 81 91 95
*/