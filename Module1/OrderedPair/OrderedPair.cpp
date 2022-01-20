//#include "orderedpair.h"
//#include <iostream>
//using namespace std;

namespace cs_pairs {
    template <class T>
    OrderedPair<T>::OrderedPair(value_type newFirst, value_type newSecond) {
        setFirst(newFirst);
        setSecond(newSecond);
    }

    template <class T>
    bool OrderedPair<T>::preconditionMet( value_type newFirst, value_type newSecond) {
        if (newFirst == DEFAULT_VALUE && newSecond == DEFAULT_VALUE) return true;
        return newFirst != newSecond;
    }
    template <class T>
    void OrderedPair<T>::setFirst(value_type newFirst) {
        // if statement to throw an exception if precondition not met goes here.  
        if (!preconditionMet( newFirst, second)) {
            throw DuplicateMemberError();
        }
        first = newFirst;
    }

    template <class T>
    void OrderedPair<T>::setSecond(value_type newSecond) {
        // if statement to throw an exception if precondition not met goes here.  
        if (!preconditionMet( first, newSecond)) {
            throw DuplicateMemberError();
        }
        second = newSecond;
    }

    template <class T>
    typename OrderedPair<T>::value_type OrderedPair<T>::getFirst() const {
        return first;
    }

    template <class T>
    typename OrderedPair<T>::value_type OrderedPair<T>::getSecond() const {
        return second;
    }

    template <class T>
    OrderedPair<T> OrderedPair<T>::operator+(const OrderedPair& right) const {
        return OrderedPair(first + right.first, second + right.second);
    }

    template <class T>
    bool OrderedPair<T>::operator<(const OrderedPair& right) const {
        return first + second < right.first + right.second;
    }

    template< class T>
    void OrderedPair<T>::print() const {
        std::cout << "(" << first << ", " << second << ")";
    }
}