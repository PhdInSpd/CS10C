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
	// passed test
	void allocHashTable(int tableSize);
	// passed test
	int getHashIndex(const KeyType& searchKey) const;
	// passed test
	void copy(HashedEntry<KeyType, ItemType>** inHashTable);
public:
	// passed test
	HashedDictionary();
	// passed test
	HashedDictionary(int tableSize);
	// passed test
	HashedDictionary(const HashedDictionary<KeyType, ItemType>& dict);
	// passed test
	virtual ~HashedDictionary();
	// passed test
	bool isEmpty() const;
	// passed test
	int getNumberOfItems() const;
	// passed test
	bool add(const KeyType& searchKey, const ItemType& newItem);
	// passed test
	bool remove(const KeyType& searchKey);
	// passed test
	void clear();
	// passed test
	ItemType getItem(const KeyType& searchKey) const
		throw (NotFoundException);
	// passed test
	bool contains(const KeyType& searchKey) const;
	// passed test
	void display() const;
public:
	// passed test
	static bool isPrime(int canidate);
	// if current number is prime then return that else return nex available prime
	// passed test
	static int getValidPrime(int canidate);
}; // end HashedDictionary
#include "HashedDictionary.cpp"
