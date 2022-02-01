//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
/*
    student: Jose Alfredo Martinez
    instructor : Dave Harden
    class : CS 10C
    date : Jan 25, 2022
    @file Node.h
*/
#pragma once

namespace cs_set {

    template<typename ItemType>
    class Node {
    private:
        ItemType item;
        Node<ItemType>* next;

    public:
        Node(const ItemType& anItem = ItemType(), Node<ItemType>* nextNodePtr = nullptr);
        void setItem(const ItemType& anItem);
        void setNext(Node<ItemType>* nextNodePtr);
        ItemType getItem() const;
        Node<ItemType>* getNext() const;
    };
}

#include "Node.cpp"
