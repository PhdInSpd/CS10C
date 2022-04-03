/*
student: Jose Alfredo Martinez
instructor : Dave Harden
class : CS 10C
date : April 02, 2022
file name : ArrayQueue.h
description: Array Queue for circular list that automaticly resizes
*/
#pragma once

#include "QueueInterface.h"
#include "PrecondViolatedExcep.h"

template<typename ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
    public:
        ArrayQueue();
        ArrayQueue(const ArrayQueue& copy);
        ArrayQueue& operator=(const ArrayQueue& copyMe);
        ~ArrayQueue();
        bool isEmpty() const;
        void enqueue(const ItemType& newEntry);
        void dequeue();
        ItemType peekFront() const;
        void print() const;
        int getCapacity() const;
    private:
        static const int DEFAULT_CAPACITY = 1;
        int capacity;
        ItemType * items;
        int front;
        int back;
        int numItems;
        void deallocate();
        void allocDefaultCapacity();
        void clone(const ArrayQueue& copy);
};

#include "ArrayQueue.cpp"
