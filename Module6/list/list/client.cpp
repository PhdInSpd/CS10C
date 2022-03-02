#include "Sequence.h"
#include <iostream>

using namespace std;
using namespace cs_sequence;
const int MAX_SIZE = 4;

int main() {
	Sequence s;
	// start pass
	s.start();
	// current passes
	//s.current();

	// insert passes
	for (int i = 0; i < MAX_SIZE; i++) {
		s.insert(i);
	}

	for (s.start(); s.is_item(); s.advance()) {
		cout << s.current() << " ";
	}
	// current passes
	//s.current();
	
	//try {
	//    s.advance();
	//	cout << " s.advance NO assert" << endl;
	//}
	//catch (...) {
	//	cout << " s.advance assert" << endl;
	//}

	cout << endl;
}

/*
output: 
3 2 1 0
*/