#include <iostream>
// comment out one of the two following lines, depending on which implementation
// you want to use
#include "arrayStack.h"
//#include "mystack-ll.h"
#include <string>
using namespace std;
using namespace cs_stack;

bool isBalanced(const string& mystring);

int main() {
	string astring;

	cout << "enter a string of parens: ";
	cin >> astring;
	while (astring != "quit") {
		if (isBalanced(astring)) {
			cout << "balanced" << endl;
		}
		else {
			cout << "not balanced" << endl;
		}
		cout << "enter a string of parens: ";
		cin >> astring;
	}
}


bool isBalanced(const string& mystring) {
	int i = 0;
	ArrayStack<char> s;
	while (i < mystring.length()) {
		if (mystring[i] == '(') {
			s.push('(');
		}
		else if (mystring[i] == ')') {
			if (s.isEmpty()) {
				return false;
			}
			else {
				s.pop();
			}
		}
		i++;
	}

	return s.isEmpty();
}
