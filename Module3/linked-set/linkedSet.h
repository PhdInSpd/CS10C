#pragma once
//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#pragma once
#include "SetInterface.h"
#include "Node.h"

namespace cs_set {

    template<class ItemType>
    class LinkedSet : public SetInterface<ItemType>
    {
    private:
        Node<ItemType>* headPtr;
        int itemCount;

        // Returns either a pointer to the node containing a given entry
        // or nullptr if the entry is not in the set.
        Node<ItemType>* getPointerTo(const ItemType& target) const;

    public:
        // exception classes
        class ItemNotFoundError : public std::exception {};
        class DuplicateItemError : public std::exception {};

        LinkedSet();
        LinkedSet( const LinkedSet<ItemType>& copyMe );
        LinkedSet& operator=(const LinkedSet<ItemType>& copyMe);
        virtual ~LinkedSet();
        int getCurrentSize() const;
        bool isEmpty() const;
        void add(const ItemType& newEntry);
        void remove(const ItemType& anEntry);
        void clear();
        bool contains(const ItemType& anEntry) const;
        //int getFrequencyOf(const ItemType& anEntry) const;
        std::vector<ItemType> toVector() const;
    private:
        void clone(const LinkedSet<ItemType>& copyMe);
    };
}

#include "LinkedSet.cpp"
