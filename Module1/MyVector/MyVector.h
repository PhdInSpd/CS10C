#pragma once
// file myvector.h

#include <cassert>
#include <cstdlib>

template <class T>
class MyVector {
public:
    typedef std::size_t size_type;
    typedef T value_type;
    MyVector(size_type inSize = 0, const value_type& inValue = value_type());
    size_type size() const;
    size_type capacity() const;
    value_type at(size_type i) const;
    void push_back(const value_type& insertMe);
private:
    value_type* items;
    size_type mSize;
    size_type mCapacity;
public:
    class iterator {
    public:
        iterator(value_type* initial = NULL) {
            current = initial;
        }

        value_type& operator*() const {
            return *current;
        }

        iterator& operator++() {
            current++;
            return *this;
        }

        iterator operator++(int) {
            iterator original(current);
            current++;
            return original;
        }

        bool operator==(iterator other) const {
            return current == other.current;
        }

        bool operator !=(iterator other) const {
            return current != other.current;
        }
    private:
        value_type* current;
    };

    class const_iterator {
    public:
        const_iterator(const value_type* initial = NULL) {
            current = initial;
        }

        const value_type& operator*() const {
            return *current;
        }

        const_iterator& operator++() {
            current++;
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator original(current);
            current++;
            return original;
        }

        bool operator==(const const_iterator other) const {
            return current == other.current;
        }

        bool operator !=(const const_iterator other) const {
            return current != other.current;
        }
    private:
        const value_type* current;
    };

    iterator begin() {
        return iterator(items);
    }

    iterator end() {
        return iterator(&items[mSize - 1] + 1);
    }

    const_iterator begin() const {
        return const_iterator(items);
    }

    const_iterator end() const {
        return const_iterator(&items[mSize - 1] + 1);
    }


};

#include "myvector.cpp"