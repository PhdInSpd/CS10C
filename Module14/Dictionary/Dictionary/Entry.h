/**
student     : Jose Alfredo Martinez
instructor  : Dave Harden
class       : CS 10C
date        : April 05, 2022
file name   : Entry.h 
Description : A class of entry objects for an array-based implementation of the ADT dictionary. Listing 18-2.
*/

#pragma once
template <typename KeyType, typename ItemType>
class Entry {
private:
   ItemType item;
   KeyType searchKey;
   
protected:
	void setKey(const KeyType& newSearchKey) {
		searchKey = newSearchKey;
   }
   





public:
   Entry() : item(ItemType()), searchKey(KeyType()) {}






   Entry(ItemType newItem, KeyType newSearchKey) {
	   item = newItem;
	   searchKey = newSearchKey;
   }






   ItemType getItem() const {
	   return item;
   }
   





   void setItem(const ItemType& newEntry) {
	   item = newEntry;
   }








   KeyType getKey() const {
	   return searchKey;
   }
}; // end Entry
