#pragma once
//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
/*
student    : Jose Alfredo Martinez
instructor : Dave Harden
class      : CS 10C
date       : Jan 25, 2022
file name  : linkeSet.h

SetInterface header file for class implementation.

*/

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
        virtual ~LinkedSet() override;
        int getCurrentSize() const override;
        bool isEmpty() const override;
        void add(const ItemType& newEntry) override;
        void remove(const ItemType& anEntry) override; 
        void clear() override;
        bool contains(const ItemType& anEntry) const override;
        std::vector<ItemType> toVector() const override;

        void add(const LinkedSet<ItemType>& otherSet);
        void add(const std::vector<ItemType>& itemList);

        /** Perform the union of this set and otherSet.
        @param otherSet  The other set.
        @return  the union between this set and otherSet. */
        LinkedSet setUnion(const LinkedSet& otherSet);
        /** Perform the intersection of this set and otherSet.
        @param otherSet  The other set.
        @return  the intersection between this set and otherSet. */
        LinkedSet setIntersection(const LinkedSet& otherSet);
        /** Perform the difference of this set and otherSet.
        @param otherSet  The other set.
        @return  the difference between this set and otherSet. */
        LinkedSet setDifference(const LinkedSet& otherSet);

    private:
        void clone(const LinkedSet<ItemType>& copyMe);
    };
}

#include "LinkedSet.cpp"
