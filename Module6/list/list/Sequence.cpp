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
    typename Sequence<ItemType>::size_type  Sequence<ItemType>::size() const {
        return numItems;
    }

    template<typename ItemType>
    Sequence<ItemType>::Sequence() :    numItems(0),
                                        headPtr(nullptr),
                                        tailPtr(nullptr),
                                        cursor(nullptr),
                                        precursor(nullptr) {
    }

    template<typename ItemType>
    Sequence<ItemType>::~Sequence() {
        start();
        while (numItems > 0) {
            remove_current();
        }
    }

    template<typename ItemType>
    void Sequence<ItemType>::start() {
        cursor = headPtr;
        precursor = nullptr;
    }

    template<typename ItemType>
    void Sequence<ItemType>::advance() {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->nextPtr;
    }

    template<typename ItemType>
    void Sequence<ItemType>::insert(const value_type& entry) {
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
    void Sequence<ItemType>::attach(const value_type& entry) {

    }

    template<typename ItemType>
    void Sequence<ItemType>::remove_current() {
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
    bool Sequence<ItemType>::is_item() const{
        return cursor != nullptr;
    }

    template<typename ItemType>
    typename Sequence<ItemType>::value_type Sequence<ItemType>::current() const {
        assert(is_item());
        return cursor->data;
    }
}