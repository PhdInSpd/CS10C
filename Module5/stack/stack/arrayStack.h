#pragma once
#include "StackInterface.h"

namespace cs_stack {
    template<typename ItemType>
    class ArrayStack : public StackInterface<ItemType>
    {
    private:
        static const int DEFAULT_CAPACITY = 5;
        ItemType items[DEFAULT_CAPACITY] = {};
        int numItems;

    public:
        class CapacityExceededError {};
        class StackEmptyError {};
        ArrayStack();
        bool isEmpty() const;
        void push(const ItemType& newEntry);
        void pop();
        ItemType top() const;
    };
}
#include "arrayStack.cpp"

