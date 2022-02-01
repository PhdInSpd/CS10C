//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Edited by Dave Harden
/*
student   : Jose Alfredo Martinez
instructor: Dave Harden
class     : CS 10C
date      : Jan 25, 2022
file name : LinkedSet.cpp

LinkedSet class implementation
*/
#include "Node.h"
#include <cstddef>

namespace cs_set {

    template<typename ItemType>
    LinkedSet<ItemType>::LinkedSet() {
        headPtr = nullptr;
        itemCount = 0;
    }





    template<typename ItemType>
    LinkedSet<ItemType>::LinkedSet(const LinkedSet<ItemType>& copyMe) {
        clone(copyMe);
    }





    // the copy constructor
    template <typename ItemType>
    LinkedSet<ItemType>& LinkedSet<ItemType>::operator=(const LinkedSet<ItemType>& copyMe) {
        clear();
        clone(copyMe);
        return *this;
    }






    // clone a LinkedSet
    template <typename ItemType>
    void LinkedSet<ItemType>::clone(const LinkedSet<ItemType>& copyMe) {
        itemCount = copyMe.itemCount;
        Node<ItemType>* origChainPtr = copyMe.headPtr;

        if (origChainPtr == nullptr) {
            headPtr = nullptr;
            return;
        }
        if (copyMe.headPtr == nullptr) {
            this->headPtr = nullptr;
            return;
        }

        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        // Copy remaining nodes
        Node<ItemType>* newChainPtr = headPtr;
        origChainPtr = origChainPtr->getNext();

        while (origChainPtr != nullptr) {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            // Create a new node containing the next item
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);

            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();
            newChainPtr->setNext(nullptr);

            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }
    }





    template<typename ItemType>
    LinkedSet<ItemType>::~LinkedSet() {
        clear();
    }





    template<typename ItemType>
    bool LinkedSet<ItemType>::isEmpty() const {
        return itemCount == 0;
    }





    template<typename ItemType>
    int LinkedSet<ItemType>::getCurrentSize() const {
        return itemCount;
    }





    template<typename ItemType>
    void LinkedSet<ItemType>::add(const ItemType& newEntry) {
        if (contains(newEntry)) {
            throw DuplicateItemError();
        }
        Node<ItemType>* nextNodePtr = new Node<ItemType>();
        nextNodePtr->setItem(newEntry);
        nextNodePtr->setNext(headPtr);

        headPtr = nextNodePtr;          // New node is now first node
        itemCount++;
    }






    template<typename ItemType>
    void LinkedSet<ItemType>::add(const LinkedSet<ItemType>& otherSet) {
        if (otherSet.isEmpty()) return;
        Node<ItemType>* curPtr = otherSet.headPtr;

        do {
            add(curPtr->getItem());
            curPtr = curPtr->getNext();
        } while (curPtr != nullptr);
    }






    template<class ItemType>
    void LinkedSet<ItemType>::add(const std::vector<ItemType>& itemList) {
        for (typename std::vector<ItemType>::const_iterator it = itemList.begin(); it < itemList.end(); it++) {
            add(*it);
        }
    }






    template<typename ItemType>
    std::vector<ItemType> LinkedSet<ItemType>::toVector() const {
        std::vector<ItemType> setContents;
        Node<ItemType>* curPtr = headPtr;
        while ((curPtr != nullptr)) {
            setContents.push_back(curPtr->getItem());
            curPtr = curPtr->getNext();
        }

        return setContents;
    }





    template<typename ItemType>
    void LinkedSet<ItemType>::remove(const ItemType& anEntry) {
        Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
        if (entryNodePtr == nullptr) {
            throw ItemNotFoundError();
        }
        else {
            // replace data of node to delete with data from first node
            entryNodePtr->setItem(headPtr->getItem());

            // Delete first node
            Node<ItemType>* nodeToDeletePtr = headPtr;
            headPtr = headPtr->getNext();
            delete nodeToDeletePtr;

            itemCount--;
        }
    }





    template<typename ItemType>
    void LinkedSet<ItemType>::clear() {
        Node<ItemType>* nodeToDeletePtr = headPtr;
        while (headPtr != nullptr) {
            headPtr = headPtr->getNext();
            delete nodeToDeletePtr;
            nodeToDeletePtr = headPtr;
        }

        headPtr = nullptr;
        itemCount = 0;
    }






    template<typename ItemType>
    bool LinkedSet<ItemType>::contains(const ItemType& anEntry) const {
        return (getPointerTo(anEntry) != nullptr);
    }





    // private
    // Returns either a pointer to the node containing a given entry 
    // or nullptr if the entry is not in the set.

    template<typename ItemType>
    Node<ItemType>* LinkedSet<ItemType>::getPointerTo(const ItemType& anEntry) const {
        bool found = false;
        Node<ItemType>* curPtr = headPtr;

        while (!found && (curPtr != nullptr)) {
            if (anEntry == curPtr->getItem()) {
                found = true;
            }
            else {
                curPtr = curPtr->getNext();
            }
        }

        return curPtr;
    }





    template<typename ItemType>
    LinkedSet<ItemType> LinkedSet<ItemType>::setUnion(const LinkedSet& otherSet) {
        LinkedSet<ItemType> union1;
        union1.add(*this);
        union1.add(otherSet);
        return union1;
    }






    template<typename ItemType>
    LinkedSet<ItemType> LinkedSet<ItemType>::setIntersection(const LinkedSet& otherSet) {
        LinkedSet<ItemType> intersection;

        Node<ItemType>* curPtr = otherSet.headPtr;
        do {

            if ( this->contains( curPtr->getItem() ) ) {
                intersection.add( curPtr->getItem() );
            }
            curPtr = curPtr->getNext();
        } while (curPtr != nullptr);
        return intersection;
    }






    template<typename ItemType>
    LinkedSet<ItemType> LinkedSet<ItemType>::setDifference(const LinkedSet& otherSet) {
        //LinkedSet<ItemType> intersection = setIntersection(otherSet);
        LinkedSet<ItemType> intersection;
        Node<ItemType>* curPtr = otherSet.headPtr;
        do {

            if (this->contains(curPtr->getItem())) {
                intersection.add(curPtr->getItem());
            }
            curPtr = curPtr->getNext();
        } while (curPtr != nullptr);

        
        LinkedSet<ItemType> difference;
        difference.add(*this);

        curPtr = intersection.headPtr;
        do {
            difference.remove( curPtr->getItem() );
            curPtr = curPtr->getNext();
        } while (curPtr != nullptr);

        return difference;
    }

}

