#include <iostream>
#include "LL.h"
using namespace std;

void print(const LL<int>& printMe);


int main() {
	LL<int> l1, l2;

	l1.push_front(1000);
	LL<int>::iterator it = l1.begin();
	for (int i = 0; i < 10; i++) {
		l1.insert_after(it, i);
		l2.push_front(i);
	}

	cout << "l1: ";
	print(l1);

	cout << "l2: ";
	print(l2);

	cout << "Size of l1: " << l1.size() << endl;
	it = l1.begin();
	l1.delete_after(it);
	cout << "Setting iterator to first item in l1 and calling delete_after(): "
		<< endl;
	cout << "l1: ";
	print(l1);
	cout << "New size of l1: " << l1.size() << endl;

	l1.front() = 1001;
	cout << "Using front to set first item in l1 to 1001: ";
	cout << "l1: ";
	print(l1);

	cout << "Using front() to print first item in l1: " << l1.front() << endl;

	cout << "Using empty(), pop_front(), and front() to print l1 and "
		<< "also clear it: " << endl;

	while (!l1.empty()) {
		cout << l1.front() << " ";
		l1.pop_front();
	}
	cout << endl;

	cout << "l1 should be empty, so testing Empty_List_Error on it: " << endl;
	try {
		l1.pop_front();
	}
	catch (LL<int>::Empty_List_Error e) {
		cout << "oops, tried to pop_front() from l1 but it was empty! " << endl;
	}
}


void print(const LL<int>& printMe) {
	for (LL<int>::const_iterator i = printMe.begin(); i != printMe.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
}