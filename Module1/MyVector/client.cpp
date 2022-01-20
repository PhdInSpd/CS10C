
#include <iostream>
#include "myvector.h"
using namespace std;

void print(const MyVector<int>& v);

int main() {
    MyVector<int> v;
    MyVector<int>::size_type currentSize;

    for (int i = 0; i < 20; i++) {
        v.push_back(i);

        currentSize = v.size();
        cout << "size: " << currentSize << " capacity: " << v.capacity() << endl;
    }

    print(v);
}



void print(const MyVector<int>& printMe) {
    for (MyVector<int>::const_iterator i = printMe.begin(); i != printMe.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}