//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file Node.h
    Listing 4-1 */
#pragma once

namespace cs_set {

    template<class ItemType>
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
