/*
    student: Jose Alfredo Martinez
    instructor : Dave Harden
    class : CS 10C
    date : Jan 21, 2022
*/
/** Header file for an array-based implementation of the ADT set. Listing 3-1.
 @file ArraySet.h */

#pragma once
#include <exception>
#include "SetInterface.h"

namespace cs_set {
    template<typename ItemType>
    class ArraySet : public SetInterface<ItemType>
    {
    public:
        class CapacityExceededError {};
        class ItemNotFoundError {};
        class DuplicateItemError : public std::exception {};

        typedef ItemType value_type;

        ArraySet();
        int getCurrentSize() const override;
        bool isEmpty() const override;
        void add(const ItemType& newEntry) override;
        void remove(const ItemType& anEntry) override;
        void clear() override;
        bool contains(const ItemType& anEntry) const override;

        //int getFrequencyOf(const ItemType& anEntry) const;
        std::vector<ItemType> toVector() const override;

        void add(const ArraySet& otherSet);
        void add(const std::vector<ItemType>& itemList);

        // is there a reason this are not declared in interface file? */
        /** Perform the union of this set and otherSet.
        @param otherSet  The other set.
        @return  the union between this set and otherSet. */
        ArraySet setUnion(const ArraySet & otherSet);
        /** Perform the intersection of this set and otherSet.
        @param otherSet  The other set.
        @return  the intersection between this set and otherSet. */
        ArraySet setIntersection(const ArraySet& otherSet);
        /** Perform the difference of this set and otherSet.
        @param otherSet  The other set.
        @return  the difference between this set and otherSet. */
        ArraySet setDifference(const ArraySet& otherSet);

        
    private:
        static const int DEFAULT_CAPACITY = 6;
        ItemType items[DEFAULT_CAPACITY];
        unsigned int itemCount;
        unsigned int maxItems;

        // Returns either the index of the element in the array items that
        // contains the given target or -1, if the array does not contain 
        // the target.
        int getIndexOf(const ItemType& target) const;
    };
}

#include "ArraySet.cpp"
