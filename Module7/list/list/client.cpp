//
//  CS2B a10unittester.cpp
//  C++Utility
//
//  Created by JAMES O'HARA on 4/12/17.
//  Copyright © 2017 JAMES O'HARA. All rights reserved.
//

//#include <cstddef>
//#include "studentWork/sequence.h"
#include "sequence.h"

#include <iostream>
#include <cassert>
#include <cstring>


//using namespace daveharden_sequence;
//using namespace cs_Sequence;
using namespace cs_sequence;
using namespace std;

void print(const Sequence& s);
void testAttach();
void test_remove_current();
void test_etc();
void checkData(const Sequence& s, const string& right);
void appendData(int data, string& left);

int main() {

    cout << "Testing attach()" << endl;
    testAttach();
    cout << "Testing remove_current()" << endl;
    test_remove_current();

    test_etc();

    return 0;
}






void test_remove_current() {
    cout << "Scenario 1, remove current from one-item list" << endl;
    Sequence s_rc;
    s_rc.attach(1);
    cout << "Declared Sequence s_rc and attached 1" << endl;
    print(s_rc);
    cout << "Call remove_current" << endl;
    s_rc.remove_current();
    cout << "assert all pointers null and size is 0" << endl;
    assert(s_rc.headPtr == s_rc.tailPtr && s_rc.tailPtr == nullptr
        && s_rc.cursor == s_rc.precursor && s_rc.cursor == nullptr);
    print(s_rc);
    cout << "size() is " << s_rc.size();
    cout << endl;

    cout << "Scenario 2, remove current from multi-item list, cursor == headPtr" << endl;
    s_rc.attach(1);
    s_rc.attach(2);
    s_rc.start();
    print(s_rc);
    cout << "assert size() == 1 && headPtr->data == 2 && headPtr == tailPtr" <<
        " && tailPtr->next == nullptr" << endl;
    s_rc.remove_current();
    assert(s_rc.size() == 1 && s_rc.headPtr->data == 2 && s_rc.headPtr == s_rc.tailPtr &&
        s_rc.tailPtr->next == nullptr);
    print(s_rc);
    cout << endl;

    cout << "Scenario 3, remove current from multi-item list, cursor in middle" << endl;
    s_rc.insert(1);
    s_rc.advance();
    s_rc.attach(3);
    s_rc.start();
    s_rc.advance();
    print(s_rc);
    cout << "Calling remove_current()" << endl;
    s_rc.remove_current();
    cout << "assert cursor == tailPtr" << endl;
    assert(s_rc.cursor = s_rc.tailPtr);
    cout << "assert precursor->data == 1" << endl;
    assert(s_rc.precursor->data == 1);
    cout << "assert precursor->next = cursor" << endl;
    assert(s_rc.precursor->next == s_rc.cursor);
    cout << "assert tailPtr->data == 3 && tailPtr->next == nullptr" << endl;
    assert(s_rc.tailPtr->data == 3 && s_rc.tailPtr->next == nullptr);
    cout << "assert headPtr->data == 1" << endl;
    assert(s_rc.headPtr->data == 1);
    print(s_rc);
    cout << endl;

    cout << "Scenario 4, remove current from multi-item list when " <<
        "cursor equals tailPtr" << endl;
    cout << "Current list:" << endl;
    print(s_rc);
    cout << "Calling remove_current()" << endl;
    s_rc.remove_current();
    cout << "assert precursor == nullptr" << endl;
    assert(s_rc.precursor == nullptr);
    cout << "assert cursor == nullptr" << endl;
    assert(s_rc.cursor == nullptr);
    cout << "assert tailPtr->data == 1" << endl;
    assert(s_rc.tailPtr->data == 1);
    cout << "headPtr->data == 1" << endl;
    assert(s_rc.headPtr->data == 1);
    cout << "assert tailPtr->next == nullptr" << endl;
    assert(s_rc.tailPtr->next == nullptr);
    print(s_rc);
    cout << endl;
}








void print(const Sequence& s) {
    Sequence::node* ptr = s.headPtr;
    cout << endl;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
    if (s.is_item())
        cout << "current is " << s.current() << endl;
    else
        cout << "No current item." << endl;
    cout << "size() returns " << s.size() << endl;
    cout << "numItems is " << s.numItems << endl;
    assert(s.size() == s.numItems);
    cout << endl;
}

void testAttach() {
    cout << "Declare s_attach; assert all pointers null, numItems == size() == 0" << endl;
    Sequence s_attach;
    assert(s_attach.headPtr == s_attach.tailPtr && s_attach.cursor ==
        s_attach.precursor && s_attach.headPtr == nullptr && s_attach.cursor == nullptr);
    assert(s_attach.numItems == 0 && s_attach.size() == s_attach.numItems);
    cout << "Scenario 1, attach to an empty list" << endl;

    s_attach.attach(1);
    cout << "assert is_item()" << endl;
    assert(s_attach.is_item());
    cout << "assert cursor == headPtr" << endl;
    assert(s_attach.cursor == s_attach.headPtr);
    cout << "assert precursor is nullptr" << endl;
    assert(s_attach.precursor == nullptr);
    cout << "assert tailPtr == headPtr" << endl;
    assert(s_attach.tailPtr == s_attach.tailPtr);
    cout << "assert tailPtr->data == 1" << endl;
    assert(s_attach.tailPtr->data == 1);
    cout << "assert tailPtr->next is nullptr" << endl;
    assert(s_attach.tailPtr->next == nullptr);
    cout << "assert size() equals numItems equals 1" << endl;
    assert(s_attach.size() == s_attach.numItems && s_attach.numItems == 1);
    cout << "assert current() == 1" << endl;
    assert(s_attach.current() == 1);
    print(s_attach);
    cout << endl;

    cout << "Scenario 2, attach to 1-item list" << endl;
    s_attach.attach(2);
    cout << "assert precursor->data == headPtr->data == 1" << endl;
    assert(s_attach.precursor->data == s_attach.headPtr->data && s_attach.headPtr->data == 1);
    cout << "assert cursor == tailPtr && tailPtr->data == 2" << endl;
    assert(s_attach.cursor == s_attach.tailPtr && s_attach.tailPtr->data == 2);
    cout << "assert tailPtr->next is nullptr" << endl;
    assert(s_attach.tailPtr->next == nullptr);
    cout << "assert size() equals numItems equals 2" << endl;
    assert(s_attach.size() == s_attach.numItems && s_attach.numItems == 2);
    cout << "assert current() == 2" << endl;
    assert(s_attach.current() == 2);
    print(s_attach);
    cout << endl;

    cout << "Scenario 3, attach to list with cursor == tailPtr" << endl;
    s_attach.attach(3);
    cout << "assert precursor->data == 2" << endl;
    assert(s_attach.precursor->data == 2);
    cout << "assert cursor == tailPtr && tailPtr->data == 3" << endl;
    assert(s_attach.cursor == s_attach.tailPtr && s_attach.tailPtr->data == 3);
    cout << "assert tailPtr->next is nullptr" << endl;
    assert(s_attach.tailPtr->next == nullptr);
    cout << "assert headPtr->data still == 1" << endl;
    assert(s_attach.headPtr->data == 1);
    cout << "assert size() equals numItems equals 3" << endl;
    assert(s_attach.size() == s_attach.numItems && s_attach.numItems == 3);
    cout << "assert current() == 3" << endl;
    assert(s_attach.current() == 3);
    print(s_attach);
    cout << endl;

    cout << "advance when current item is last item" << endl;
    s_attach.advance();
    cout << "assert cursor and precursor are nullptr" << endl;
    assert(s_attach.cursor == nullptr && s_attach.precursor == nullptr);
    cout << "assert size() and numItems still equal 3" << endl;
    assert(s_attach.size() == 3 && s_attach.numItems == 3);
    cout << "assert headPtr->data equals 1 && headPtr->next->data equals 2 " <<
        "and tailPtr->data equals 3" << endl;
    assert(s_attach.headPtr->data == 1 && s_attach.headPtr->next->data == 2
        && s_attach.tailPtr->data == 3);
    cout << "assert tailPtr->next is nullptr" << endl;
    assert(s_attach.tailPtr->next == nullptr);
    print(s_attach);
    cout << endl;

    cout << "Scenario 4, attach when cursor is nullptr" << endl;
    s_attach.attach(4);
    cout << "assert tailPtr->data == 4 && cursor == tailPtr && precursor->data == 3";
    assert(s_attach.tailPtr->data == 4 &&
        s_attach.cursor == s_attach.tailPtr &&
        s_attach.precursor->data == 3);
    cout << "assert tailPtr->next is nullptr" << endl;
    assert(s_attach.tailPtr->next == nullptr);
    cout << "assert headPtr->data still == 1" << endl;
    assert(s_attach.headPtr->data == 1);
    cout << "assert size() equals numItems equals 4" << endl;
    assert(s_attach.size() == s_attach.numItems && s_attach.numItems == 4);
    cout << "assert current() == 4" << endl;
    assert(s_attach.current() == 4);
    print(s_attach);
    cout << endl;

    cout << "Scenario 2a, attach to 1-item list with null cursor" << endl;
    Sequence s2a;
    s2a.attach(1);
    s2a.advance();
    cout << "assert cursor and precursor are null" << endl;
    assert(s2a.cursor == s2a.precursor && s2a.cursor == nullptr);
    s2a.attach(2);
    cout << "assert precursor->data == headPtr->data == 1" << endl;
    assert(s2a.precursor->data == s2a.headPtr->data && s2a.headPtr->data == 1);
    cout << "assert cursor == tailPtr && tailPtr->data == 2" << endl;
    assert(s2a.cursor == s2a.tailPtr && s2a.tailPtr->data == 2);
    cout << "assert tailPtr->next is nullptr" << endl;
    assert(s_attach.tailPtr->next == nullptr);
    cout << "assert size() equals numItems equals 2" << endl;
    assert(s2a.size() == s2a.numItems && s2a.numItems == 2);
    cout << "assert current() == 2" << endl;
    assert(s2a.current() == 2);
    print(s2a);
    cout << endl;

    cout << "Scenario 5, attach with cursor in middle" << endl;
    cout << "Test start()" << endl;
    s_attach.start();
    cout << "assert headPtr->data equals 1 && headPtr->next->data equals 2 " <<
        "and headPtr->next->next->data equals 3 and tailPtr->data equals 4" << endl;
    assert(s_attach.headPtr->data == 1 && s_attach.headPtr->next->data == 2
        && s_attach.headPtr->next->next->data == 3 && s_attach.tailPtr->data == 4);
    print(s_attach);
    checkData(s_attach, "1234");
    cout << "assert tailPtr->next is nullptr" << endl;
    assert(s_attach.tailPtr->next == nullptr);
    cout << "assert cursor == headPtr and precursor is null" << endl;
    assert(s_attach.cursor == s_attach.headPtr && s_attach.precursor == nullptr);
    cout << "Test advance() when cursor != tailPtr" << endl;
    s_attach.advance();
    cout << "assert cursor->data == 2 and precursor->data == 1";
    assert(s_attach.precursor->data == 1 && s_attach.cursor->data == 2);
    print(s_attach);
    cout << "attach(22)" << endl;
    s_attach.attach(22);
    cout << "assert headPtr->data == 1 && headPtr->next->data == 2 && " <<
        "headPtr->next->next->data == 22 && headPtr->next->next->data == 3 && tailPtr->" <<
        "data == 4" << endl;
    assert(s_attach.headPtr->data == 1 &&
        s_attach.headPtr->next->data == 2 &&
        s_attach.headPtr->next->next->data == 22 &&
        s_attach.headPtr->next->next->next->data == 3 &&
        s_attach.tailPtr->data == 4);
    cout << "assert precursor->data == 2 && cursor->data == 22" << endl;
    assert(s_attach.precursor->data == 2 && s_attach.cursor->data == 22);
    print(s_attach);
    cout << endl;
}






//#include <vector>
//void checkData(const Sequence& s, const string& right){
//    string left;
//    Sequence::node *ptr = s.headPtr;
//
//    while (ptr != nullptr){
//        double power = 0.0;
//        int data = ptr->data;
//        int datasegment;
//        vector<char> charVector;
//        while (data >= pow(10.0, power + 1 )){
//            ++power;
//        }
//        while (power >= 0.0){
//            datasegment = data / pow(10.0, power);
//            data %= static_cast<int>(pow(10.0, power));
//            charVector.push_back(datasegment + 48);
//            --power;
//        }
//        vector<char>::iterator it(charVector.begin());
//        while (it != charVector.end()){
//            left += *it;
//            ++it;
//        }
//        ptr = ptr->next;
//    }
//    assert(strcmp(left.c_str(),right.c_str()) == 0);
//}


/*  @parm right predicts the series of numerals in the sequence.
    Convert the ints in the sequence to char values (e.g. 123 is converted to '1'
    and '2' and '3'), and append them to a string for comparison with right.
    assert that the string version of the sequence matches the predictive string.
 */
void checkData(const Sequence& s, const string& right) {
    string left;  // string version of the sequence
    Sequence::node* ptr = s.headPtr;

    while (ptr != nullptr) {
        int data = ptr->data;
        if (data < 0) {
            left += '-';
            data *= -1;
        }
        appendData(data, left);
        ptr = ptr->next;
    }
    assert(strcmp(left.c_str(), right.c_str()) == 0);
}






/* @parm data, left
   Tease out each digit in data by recursively dividing by 10.  Convert each
   digit to a char and append it to the string, left.
 */
const int charZero = 48;  // '0' is ascii 48
void appendData(int data, string& left) {
    if (data > 9) {
        appendData(data / 10, left);
    }
    // '1' equals '0' + 1, '2' equals '0' + 2, etc.
    left += (charZero + (data % 10));
}






void test_etc() {
    cout << "Declare Sequence s and insert 5, 4, 3, 2, 1." << endl;
    Sequence s;

    s.insert(5);
    s.insert(4);
    s.insert(3);
    s.insert(2);
    s.insert(1);

    checkData(s, "12345");
    cout << "Display Sequence s.  Should be 1 2 3 4 5.\nCurrent should be 1." << endl;
    print(s);
    if (s.current() != 1) cout << "FAILED " << endl;
    assert(s.current() == 1);


    cout << "Call advance() 4 times.\nCurrent should be 5." << endl;
    s.advance();
    s.advance();
    s.advance();
    s.advance();
    print(s);
    if (s.current() != 5) cout << "FAILED " << endl;
    assert(s.current() == 5);

    cout << "Call advance().\nThere should be no current item." << endl;
    s.advance();
    print(s);
    if (s.is_item()) cout << "FAILED" << endl;
    assert(!s.is_item());


    cout << "Call start().\nCurrent should be 1." << endl;
    s.start();
    print(s);
    if (s.current() != 1) cout << "FAILED " << endl;
    assert(s.current() == 1);

    cout << "Call remove_current() 5 times.\nSequence should be empty." << endl;
    s.remove_current();
    s.remove_current();
    s.remove_current();
    s.remove_current();
    s.remove_current();   //s.remove_current();  should catch exception or the like
    print(s);
    if (s.is_item()) cout << "FAILED" << endl;
    cout << endl;
    checkData(s, "");
    assert(!s.is_item());

    cout << "Insert 10.  Current should be 10, size should be 1." << endl;
    s.insert(10);
    print(s);
    if (!(s.size() == 1 && s.current() == 10)) cout << "FAILED" << endl;
    checkData(s, "10");
    assert(s.size() == 1 && s.current() == 10);
    cout << endl;

    cout << "Call advance.\nThere should be no currrent item." << endl;
    s.advance();
    print(s);
    if (s.is_item()) cout << "FAILED" << endl;
    assert(!s.is_item());
    cout << endl;

    cout << "Declare Sequence s2 and attach 1 2 3 4 5.  " << endl;
    Sequence s2;

    cout << "Sequence should be 1 2 3 4 5.\nCurrent should be 5." << endl;
    s2.attach(1);
    s2.attach(2);
    s2.attach(3);
    s2.attach(4);
    s2.attach(5);
    print(s2);
    if (s2.current() != 5) cout << "FAILED " << endl;
    assert(s2.current() == 5);
    checkData(s2, "12345");

    cout << "Call start().\nCurrent should be 1." << endl;
    s2.start();
    print(s2);
    if (s2.current() != 1) cout << "FAILED " << endl;
    assert(s2.current() == 1);

    cout << "Call advance() 4 times.\nCurrent should be 5." << endl;
    s2.advance();
    s2.advance();
    s2.advance();
    s2.advance();
    print(s2);
    if (s2.current() != 5) cout << "FAILED " << endl;
    assert(s2.current() == 5);

    cout << "Call advance().\nThere should be no current item." << endl;
    s2.advance();
    print(s2);
    if (s2.is_item()) cout << "FAILED " << endl;
    assert(!s2.is_item());
    s2.attach(6);
    cout << "Attach 6.\nCurrent should be 6." << endl;
    print(s2);
    if (s2.current() != 6) cout << "FAILED " << endl;
    assert(s2.current() == 6);
    checkData(s2, "123456");

    cout << "Call start().\nCurrent should be 1." << endl;
    s2.start();
    print(s2);
    if (s2.current() != 1) cout << "FAILED " << endl;
    assert(s2.current() == 1);

    cout << "Call remove_current().\nCurrent should be 2." << endl;
    s2.remove_current();
    print(s2);
    if (s2.current() != 2) cout << "FAILED " << endl;
    assert(s2.current() == 2);
    checkData(s2, "23456");

    cout << "Assign s to itself.  s before self-assignment:" << endl;
    print(s);
    s = s;
    cout << "s after self-assignment:" << endl;
    print(s);
    checkData(s, "10");

    cout << "Test copy constructor.  Create s3 as copy of s2." << endl;
    Sequence s3(s2);
    cout << "s2:" << endl;
    print(s2);
    cout << "s3:" << endl;
    print(s3);
    if (s2.cursor == nullptr)
        assert(s3.cursor == nullptr && s3.precursor == nullptr);
    else if (s2.precursor == nullptr)
        assert(s3.precursor == nullptr && s3.cursor->data == s2.cursor->data);
    else
        assert(s3.cursor->data == s2.cursor->data && s3.precursor->data == s2.precursor->data);
    assert(s2.numItems == s3.numItems);
    checkData(s2, "23456");
    checkData(s3, "23456");

    cout << "Test assignment operation." << endl;
    cout << "Assign s to s3.  s:" << endl;
    print(s);
    cout << "s3:" << endl;
    print(s3);
    s3 = s;
    cout << "s3 after s assigned:" << endl;
    print(s3);
    if (s.cursor == nullptr)
        assert(s3.cursor == nullptr && s3.precursor == nullptr);
    else if (s.precursor == nullptr)
        assert(s3.precursor == nullptr && s3.cursor->data == s.cursor->data);
    else
        assert(s3.cursor->data == s2.cursor->data && s3.precursor->data == s.precursor->data);
    checkData(s3, "10");

    cout << "Assign s2 to s3.  s2:" << endl;
    print(s2);
    cout << "s3:" << endl;
    print(s3);
    s3 = s2;
    cout << "s3 after s2 assigned:" << endl;
    print(s3);
    if (s2.cursor == nullptr)
        assert(s3.cursor == nullptr && s3.precursor == nullptr);
    else if (s2.precursor == nullptr)
        assert(s3.precursor == nullptr && s3.cursor->data == s2.cursor->data);
    else
        assert(s3.cursor->data == s2.cursor->data && s3.precursor->data == s2.precursor->data);
    checkData(s3, "23456");

    cout << "Assign an empty sequence to s3." << endl;
    cout << "s3:" << endl;
    print(s3);
    Sequence empty;
    s3 = empty;
    cout << "s3 after empty sequence assigned:" << endl;
    print(s3);
    assert(s3.numItems == 0 && s3.cursor == nullptr && s3.precursor == nullptr &&
        s3.headPtr == nullptr && s3.tailPtr == nullptr);
    checkData(s3, "");

    cout << "Test copy constructor with null cursor in source." << endl;
    cout << "Take cursor off end of s2, and then make s4 a copy of s2." << endl;
    while (s2.is_item())
        s2.advance();
    Sequence s4(s2);
    cout << "s4 after copy:" << endl;
    print(s4);
    if (s2.cursor == nullptr)
        assert(s4.cursor == nullptr && s4.precursor == nullptr);
    else if (s2.precursor == nullptr)
        assert(s4.precursor == nullptr && s4.cursor->data == s2.cursor->data);
    else
        assert(s4.cursor->data == s2.cursor->data && s4.precursor->data == s2.precursor->data);
    checkData(s4, "23456");

}