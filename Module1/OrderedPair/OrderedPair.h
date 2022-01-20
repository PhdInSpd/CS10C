#pragma once
#include <iostream>
#include <exception>
using namespace std;
/* precondition for setFirst and setSecond: the values of first and second cannot be equal,
except when they are both equal to DEFAULT_VALUE.
*/


namespace cs_pairs {
    template <class T>
    class OrderedPair {
    public:
        typedef T value_type;
        static const value_type DEFAULT_VALUE;

        OrderedPair(value_type newFirst = DEFAULT_VALUE, value_type newSecond = DEFAULT_VALUE);
        void setFirst(value_type newFirst);
        void setSecond(value_type newSecond);
        value_type getFirst() const;
        value_type getSecond() const;
        OrderedPair operator+(const OrderedPair& right) const;
        bool operator<(const OrderedPair& right) const;
        void print() const;
    public:
        class DuplicateMemberError : public exception {
        };
    private:
        value_type first = DEFAULT_VALUE;
        value_type second = DEFAULT_VALUE;
    private:
        bool preconditionMet(value_type newFirst, value_type newSecond);
    };

    template<class T>
    typename const OrderedPair<T>::value_type OrderedPair<T>::DEFAULT_VALUE = OrderedPair<T>::value_type();



}
// include this file will ensure header and implementation file are compiled together
#include "OrderedPair.cpp""