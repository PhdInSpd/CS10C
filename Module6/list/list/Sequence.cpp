/*
student   : Jose Alfredo Martinez
instructor: Dave Harden
class     : CS 10C
date      : Feb 06, 2022
file name : sequence.cpp

sequence.h implementation

*/
namespace cs_sequence {
    template<typename ItemType>
    typename SequenceTemplate<ItemType>::size_type  SequenceTemplate<ItemType>::size() const {
        return numItems;
    }

    template<typename ItemType>
    SequenceTemplate<ItemType>::SequenceTemplate() :    numItems(0),
                                        headPtr(nullptr),
                                        tailPtr(nullptr),
                                        cursor(nullptr),
                                        precursor(nullptr) {
    }

    template<typename ItemType>
    SequenceTemplate<ItemType>::~SequenceTemplate() {
        start();
        while (numItems > 0) {
            remove_current();
        }
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::start() {
        cursor = headPtr;
        precursor = nullptr;
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::advance() {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->nextPtr;
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::insert(const value_type& entry) {
        Node* new_node = new Node;
        new_node->data = entry;
        numItems++;

        if (cursor == headPtr || cursor == nullptr) {   // insert at front (or into empty list).
            new_node->nextPtr = headPtr;                   // precursor remains nullptr.
            headPtr = new_node;
            if (numItems == 1) {
                tailPtr = new_node;
            }
            precursor = nullptr;
        }
        else {                                          // inserting anywhere else
            new_node->nextPtr = cursor;                    // tailPtr, headPtr and precursor don't change.
            precursor->nextPtr = new_node;
            // new node was insired before current. precursor is now new_node
            precursor = new_node;

        }

        cursor = new_node;
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::attach(const value_type& entry) {

    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::remove_current() {
        assert(is_item());
        if (precursor == nullptr) {
            Node* next = cursor->nextPtr;
            delete cursor;
            cursor = next;
        }
        else {
            precursor->nextPtr = cursor->nextPtr;
            delete cursor;
            cursor = precursor->nextPtr;
        }
        numItems--;
    }

    template<typename ItemType>
    bool SequenceTemplate<ItemType>::is_item() const{
        return cursor != nullptr;
    }

    template<typename ItemType>
    typename SequenceTemplate<ItemType>::value_type SequenceTemplate<ItemType>::current() const {
        assert(is_item());
        return cursor->data;
    }
}