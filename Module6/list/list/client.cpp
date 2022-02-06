#include "Sequence.h"
#include <iostream>

using namespace std;
using namespace cs_sequence;

int main() {
	Sequence s;
	for (int i = 0; i < 6; i++) {
		s.insert(i);
	}

	for (s.start(); s.is_item(); s.advance()) {
		cout << s.current() << " ";
	}

	cout << endl;
}

/*
output: 
5 4 3 2 1 0
*/