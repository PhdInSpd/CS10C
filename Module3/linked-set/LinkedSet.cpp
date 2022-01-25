//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Edited by Dave Harden

#include "Node.h"
#include <cstddef>

namespace cs_set {

    template<class ItemType>
    LinkedSet<ItemType>::LinkedSet() {
        headPtr = nullptr;
        itemCount = 0;
    }





    template<class ItemType>
    LinkedSet<ItemType>::LinkedSet(const LinkedSet<ItemType>& copyMe) {
        clone(copyMe);
    }





    // the copy constructor
    template <class ItemType>
    LinkedSet<ItemType>& LinkedSet<ItemType>::operator=(const LinkedSet<ItemType>& copyMe) {
        clone(copyMe);
        return *this;
    }






    // clone a LinkedSet
    template <class ItemType>
    void LinkedSet<ItemType>::clone(const LinkedSet<ItemType>& copyMe) {
        /*clear();
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

        Node* sourcePtr = &copyMe;
        Node* newListPtr = new Node();
        newListPtr->setItem( sourcePtr->getItem() );
        newListPtr->setNext( nullptr  );
        this->headPtr = newListPtr;

        sourcePtr = sourcePtr->getNext();

        while (sourcePtr != nullptr) {
            newListPtr->setNext( new Node() );
            newListPtr = newListPtr->getNext();
            newListPtr->setItem( sourcePtr->getItem() );
            newListPtr->setNext( nullptr );
            sourcePtr = sourcePtr->getNext();
        }*/
        clear();
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





    template<class ItemType>
    LinkedSet<ItemType>::~LinkedSet() {
        clear();
    }





    template<class ItemType>
    bool LinkedSet<ItemType>::isEmpty() const {
        return itemCount == 0;
    }





    template<class ItemType>
    int LinkedSet<ItemType>::getCurrentSize() const {
        return itemCount;
    }





    template<class ItemType>
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





    template<class ItemType>
    std::vector<ItemType> LinkedSet<ItemType>::toVector() const {
        std::vector<ItemType> setContents;
        Node<ItemType>* curPtr = headPtr;
        while ((curPtr != nullptr)) {
            setContents.push_back(curPtr->getItem());
            curPtr = curPtr->getNext();
        }

        return setContents;
    }





    template<class ItemType>
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





    template<class ItemType>
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





    /*template<class ItemType>
    int LinkedSet<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
        int frequency = 0;
        int counter = 0;
        Node<ItemType>* curPtr = headPtr;
        while ((curPtr != nullptr) && (counter < itemCount)) {
            if (anEntry == curPtr->getItem()) {
                frequency++;
            }

            counter++;
            curPtr = curPtr->getNext();
        }

        return frequency;
    }*/





    template<class ItemType>
    bool LinkedSet<ItemType>::contains(const ItemType& anEntry) const {
        return (getPointerTo(anEntry) != nullptr);
    }





    // private
    // Returns either a pointer to the node containing a given entry 
    // or nullptr if the entry is not in the set.

    template<class ItemType>
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
}

