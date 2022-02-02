#pragma once
#include "StackInterface.h"
#include <exception>

namespace cs_stack {
    template<typename ItemType>
    class ArrayStack : public StackInterface<ItemType>
    {
    private:
        static const int DEFAULT_CAPACITY = 1;
        ItemType items[DEFAULT_CAPACITY] = {};
        int numItems;
        int capacity = DEFAULT_CAPACITY;

    public:
        class CapacityExceededError : std::exception {};
        class StackEmptyError : std::exception{};
        ArrayStack();
        bool isEmpty() const;
        void push(const ItemType& newEntry);
        void pop();
        ItemType top() const;
    };
}
#include "arrayStack.cpp"

