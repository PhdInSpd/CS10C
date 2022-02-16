/*
student   : Jose Alfredo Martinez
instructor: Dave Harden
class     : CS 10C
date      : Feb 02, 2022
file name : arrayStack.h

declare a stack with a dynamic memory for the items
*/
#pragma once
#include "StackInterface.h"
#include <exception>
#include <cassert>       // For assert


namespace cs_stack {
    template<typename ItemType>
    class ArrayStack : public StackInterface<ItemType>
    {
    private:
        // dynamic array memory storage
        ItemType * itemsPtr = nullptr;

        int numItems;
        int capacity;
        void handleCapacity();
        void clear();
        /// <summary>
        /// pre: itemsPtr and destinationPtr are not nullptr and
        /// numItems is valid for both pointers
        /// post: destinationPtr will hold copy of itemsPtr items
        /// </summary>
        /// <typeparam name="ItemType"></typeparam>
        static void copy( ItemType* itemsPtr, ItemType* destinationPtr, int numItems);
        void clone(const ArrayStack& copy);
    public:
        static const int DEFAULT_CAPACITY = 1;
        int getNumItems() const;
        int getCapacity() const;
        class StackEmptyError : std::exception{};
        ArrayStack();
        ArrayStack(const ArrayStack& aStack);
        ArrayStack& operator=(const ArrayStack& copyMe);
        ~ArrayStack();
        bool isEmpty() const;
        void push(const ItemType& newEntry);
        void pop();
        ItemType top() const;
    };
}
#include "arrayStack.cpp"

