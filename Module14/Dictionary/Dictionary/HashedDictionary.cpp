//  Created by Frank M. Carrano and Tim Henry.
//  Edited by David Harden
//  Edited by Jose Martinez
#include <cmath>
#include <iostream>
/// <summary>
/// convert ascii letter a-z and A-Z to 1-26 number 1 else return 0
/// </summary>
/// <param name="input"></param>
/// <returns></returns>
char asciiToDigit(char input) {
    if (input >= 'a' && input <= 'z') {
        return input - 'a' + 1;
    }
    if (input >= 'A' && input <= 'Z') {
        return input - 'A' + 1;
    }
    return 0;
}







template <typename KeyType, typename ItemType>
void HashedDictionary<KeyType, ItemType>::allocHashTable(int tableSize) {
    hashTable = new  HashedEntry<KeyType, ItemType>*[tableSize];
    for (size_t i = 0; i < tableSize; i++) {
        hashTable[i] = nullptr;
    }
}






template <typename KeyType, typename ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary() {
    itemCount = 0;
    hashTableSize = getValidPrime( DEFAULT_SIZE );
    allocHashTable(hashTableSize);
}






template <typename KeyType, typename ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary() {
    clear();
    delete[] hashTable;
    hashTable = nullptr;
}






template <typename KeyType, typename ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary(int tableSize) {
    itemCount = 0;
    hashTableSize = getValidPrime( tableSize );
    allocHashTable(hashTableSize);
}






template <typename KeyType, typename ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary(const HashedDictionary<KeyType, ItemType>& dict) {
    itemCount = 0;
    hashTableSize = getValidPrime(dict.hashTableSize);
    allocHashTable(hashTableSize);
    copy(dict.hashTable);
}






template <typename KeyType, typename ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem) {
   // Create entry to add to dictionary
   HashedEntry<KeyType, ItemType>* entryToAddPtr =
                  new HashedEntry<KeyType, ItemType>(newItem, searchKey);
   
   // Compute the hashed index into the array
   int itemHashIndex = getHashIndex(searchKey);
   
   // Add the entry to the chain at itemHashIndex
   if (hashTable[itemHashIndex] == nullptr) {
      hashTable[itemHashIndex] = entryToAddPtr;
   }
   else {
      entryToAddPtr->setNext(hashTable[itemHashIndex]);
      hashTable[itemHashIndex] = entryToAddPtr;
   }
   itemCount++;
   return true;
}






template <typename KeyType, typename ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType& searchKey) {
   bool itemFound = false;
   
   // Compute the hashed index into the array
   int itemHashIndex = getHashIndex(searchKey);
   if (hashTable[itemHashIndex] != nullptr) {
      // Special case - first node has target
      if (searchKey == hashTable[itemHashIndex]->getKey()) {
         HashedEntry<KeyType, ItemType>* entryToRemovePtr = hashTable[itemHashIndex];
         hashTable[itemHashIndex] = hashTable[itemHashIndex]->getNext();
         delete entryToRemovePtr;
         entryToRemovePtr = nullptr; // For safety
         itemFound = true;
         itemCount--;
      }
      else { // Search the rest of the chain
         HashedEntry<KeyType, ItemType>* prevPtr = hashTable[itemHashIndex];
         HashedEntry<KeyType, ItemType>* curPtr = prevPtr->getNext();
         while ((curPtr != nullptr) && !itemFound ) {
            // Found item in chain so remove that node
            if (searchKey == curPtr->getKey()) {
               prevPtr->setNext(curPtr->getNext());
               delete curPtr;
               curPtr = nullptr; // For safety
               itemFound = true;
               itemCount--;
            }
            else {// Look at next entry in chain
               prevPtr = curPtr;
               curPtr = curPtr->getNext();
            } 
         }
      } 
   } 
   return itemFound;
} 






template <typename KeyType, typename ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType& searchKey) const
                                            throw (NotFoundException) { 
    bool itemFound = false;
    ItemType item;
    // Compute the hashed index into the array
    int itemHashIndex = getHashIndex(searchKey);
    if (hashTable[itemHashIndex] == nullptr) {
        throw NotFoundException();
    }

    // Special case - first node has target
    if (searchKey == hashTable[itemHashIndex]->getKey()) {
        item = hashTable[itemHashIndex]->getItem();
        itemFound = true;
    }
    else { // Search the rest of the chain
        HashedEntry<KeyType, ItemType>* prevPtr = hashTable[itemHashIndex];
        HashedEntry<KeyType, ItemType>* curPtr = prevPtr->getNext();
        while ((curPtr != nullptr) && !itemFound) {
            // Found item in chain so remove that node
            if (searchKey == curPtr->getKey()) {
                item = curPtr->getItem();
                itemFound = true;
            }
            else {// Look at next entry in chain
                prevPtr = curPtr;
                curPtr = curPtr->getNext();
            }
        }
    }
    if (!itemFound) {
        throw NotFoundException();
    }
    return item;
}






template <typename KeyType, typename ItemType>
void HashedDictionary<KeyType, ItemType>::clear() {
    for (size_t i = 0; i < hashTableSize; i++) {
        if (hashTable[i] != nullptr) {
            HashedEntry<KeyType, ItemType>* prevPtr = hashTable[i];
            HashedEntry<KeyType, ItemType>* curPtr  = prevPtr->getNext();

            while ( prevPtr != nullptr ) {                    
                delete prevPtr;
                if (curPtr != nullptr) {
                    prevPtr = curPtr;
                    curPtr = curPtr->getNext();
                }
                else {
                    prevPtr = nullptr;
                }
                itemCount--;
            }
            hashTable[i] = nullptr;
        }
    }
}






template <typename KeyType, typename ItemType>
void HashedDictionary<KeyType, ItemType>::copy(HashedEntry<KeyType, ItemType>** inHashTable) {
    for (size_t i = 0; i < hashTableSize; i++) {
        if (inHashTable[i] != nullptr) {
            HashedEntry<KeyType, ItemType>* prevPtr = inHashTable[i];
            HashedEntry<KeyType, ItemType>* curPtr = prevPtr->getNext();

            while (prevPtr != nullptr) {
                this->add(prevPtr->getKey(), prevPtr->getItem());
                if (curPtr != nullptr) {
                    prevPtr = curPtr;
                    curPtr = curPtr->getNext();
                }
                else {
                    prevPtr = nullptr;
                }
            }
        }
    }
}






template <typename KeyType, typename ItemType>
void HashedDictionary<KeyType, ItemType>::display() const {
    for (size_t i = 0; i < hashTableSize; i++) {
        if (hashTable[i] != nullptr) {
            HashedEntry<KeyType, ItemType>* curPtr = hashTable[i];

            while (curPtr != nullptr) {
                std::cout << curPtr->getItem();
                curPtr = curPtr->getNext();
            }
            std::cout << std::endl;
        }
    }
}






template <typename KeyType, typename ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType& searchKey) const{
    try {
        ItemType item = getItem(searchKey);
        return true;
    }
    catch (NotFoundException nfe) {
        return false;
    }
}






template <typename KeyType, typename ItemType>
bool HashedDictionary<KeyType, ItemType>::isPrime(int canidate) {
    bool prime = true;
    double canidatePeak = canidate;
    if (canidate <= 1) {
        prime = false;
        return prime;
    }
    canidatePeak = sqrt(canidate);

    for (size_t i = 2; i <= canidatePeak; i++) {
        if (canidate % i == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}






template <typename KeyType, typename ItemType>
int HashedDictionary<KeyType, ItemType>::getValidPrime(int canidate) {
    int prime = canidate;
    while (!isPrime(prime)) {
        prime++;
    }
    return prime;
}






template <typename KeyType, typename ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& searchKey) const {
    int length = searchKey.size();
    if (length == 0) return 0;

    // because ascii if 8 bits max
    long shift = 5;

    long result = asciiToDigit( searchKey[0] );
    for (size_t i = 1; i < length; i++) {
        result = (result << shift) + asciiToDigit( searchKey[i] );
        result = result % hashTableSize;
    }
    result = result % hashTableSize;
    return (int)result;
}






template <typename KeyType, typename ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const {    
    return getNumberOfItems()<=0;
}






template <typename KeyType, typename ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const {
    return itemCount;
}