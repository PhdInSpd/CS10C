/**
student     : Jose Alfredo Martinez
instructor  : Dave Harden
class       : CS 10C
date        : April 05, 2022
file name   : HashedDictionary.h
Description : A class of entry objects for an array-based implementation of the ADT dictionary. Listing 18-2.
*/

#pragma once
#include "DictionaryInterface.h"
#include "NotFoundException.h"
#include "HashedEntry.h"
#include "Entry.h"
template < typename KeyType, typename ItemType>
class HashedDictionary : public DictionaryInterface<KeyType, ItemType> {
private:
	HashedEntry<KeyType, ItemType>** hashTable;		// Array of pointers to entries
	int itemCount;									// Count of dictionary entries
	int hashTableSize;								// Table size must be prime
	static const int DEFAULT_SIZE = 101;
	void allocHashTable(int tableSize);
	int getHashIndex(const KeyType& searchKey) const;
public:
	HashedDictionary();
	HashedDictionary(int tableSize);
	//HashedDictionary(const HashedDictionary<KeyType, ItemType>& dict);
	virtual ~HashedDictionary();
	bool isEmpty() const;
	int getNumberOfItems() const;
	bool add(const KeyType& searchKey, const ItemType& newItem);
	bool remove(const KeyType& searchKey);
	void clear();
	ItemType getItem(const KeyType& searchKey) const
		throw (NotFoundException);
	bool contains(const KeyType& searchKey) const;
	void display() const;
public:
	static bool isPrime(int canidate);
	// if current number is prime then return that else return nex available prime
	static int getValidPrime(int canidate);
}; // end HashedDictionary
#include "HashedDictionary.cpp"
