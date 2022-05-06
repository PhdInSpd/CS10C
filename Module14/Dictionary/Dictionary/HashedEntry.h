
// Listing 18-5.

/** 
student     : Jose Alfredo Martinez
instructor  : Dave Harden
class       : CS 10C
date        : April 05, 2022
file name   : HashedEntry.h

Description : A class of entry objects for a hashing implementation of the ADT dictionary.
 */
 
#pragma once

#include "Entry.h"

template<typename KeyType, typename ItemType>
class HashedEntry : public Entry<KeyType, ItemType> {
private:
   HashedEntry<KeyType, ItemType>* nextPtr;
   
public:
    HashedEntry() {
        nextPtr = nullptr;
        setItem(ItemType());
        setKey(KeyType());
    }






    HashedEntry(ItemType newItem, KeyType newSearchKey) {
        nextPtr = nullptr;
        Entry<KeyType,ItemType>::setItem( newItem );
        Entry<KeyType, ItemType>::setKey( newSearchKey );
    }






    HashedEntry(    ItemType newItem,
                    KeyType newSearchKey,
                    HashedEntry<KeyType, ItemType>* nextEntryPtr) {
        nextPtr = nextEntryPtr;
        setItem(newItem);
        setKey(newSearchKey);
    }






   void setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr) {
       nextPtr = nextEntryPtr;
   }






   HashedEntry<KeyType, ItemType>* getNext() const {
       return nextPtr;
   }
}; // end HashedEntry

