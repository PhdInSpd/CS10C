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
    SequenceTemplate<ItemType>::SequenceTemplate(const SequenceTemplate<ItemType> & copyMe) : SequenceTemplate(){
        copy(copyMe);
    }

    template<typename ItemType>
    SequenceTemplate<ItemType>::~SequenceTemplate() {
        clear();
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::clear() {
        start();
        while (numItems > 0) {
            remove_current();
        }
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::copy( const SequenceTemplate<ItemType>& copyMe) {
        node* start = copyMe.headPtr;
        for (size_t i = 0; i < copyMe.size(); i++) {
            attach(start->data);
            start = start->next;
        }

        // copy the cursors
        if (copyMe.cursor == nullptr) {
            cursor = nullptr;
            precursor = nullptr;
        }
        else {
            findData(copyMe.cursor->data);
        }

        if (copyMe.precursor == nullptr) {
            precursor = nullptr;
        }
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::findData(const ItemType& target) {
        start();
        while (cursor != nullptr) {
            if (cursor->data == target) {
                return;
            }
            advance();
        }
        // failed 
        cursor = nullptr;
        precursor = nullptr;
    }

    template<typename ItemType>
    SequenceTemplate<ItemType>& SequenceTemplate<ItemType>::operator=( const SequenceTemplate<ItemType>& copyMe) {
        if (this != &copyMe) {
            clear();
            copy(copyMe);
        }
        return *this;
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
        cursor = cursor->next;
        if (cursor == nullptr) {
            precursor = nullptr;
        }
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::insert(const value_type& entry) {
        node* new_node = new node;
        new_node->data = entry;
        numItems++;

        if (cursor == headPtr || cursor == nullptr) {   // insert at front (or into empty list).
            new_node->next = headPtr;                   // precursor remains nullptr.
            headPtr = new_node;
            if (numItems == 1) {
                tailPtr = new_node;
            }
            precursor = nullptr;
        }
        else {                                          // inserting anywhere else
            new_node->next = cursor;                    // tailPtr, headPtr and precursor don't change.
            precursor->next = new_node;
            // new node was insired before current. precursor is now new_node
            precursor = new_node;

        }

        cursor = new_node;
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::attach(const value_type& entry) {
        /*
        (1) attaching to an empty list,
        (2) attaching at the end of a list with at least one item,
        (3) attaching anywhere else.
        */
        node* new_node = new node();
        new_node->data = entry;
        numItems++;

        if (headPtr == nullptr) { // empty list
            new_node->next = nullptr;
            headPtr = new_node;
            tailPtr = new_node;
            cursor = headPtr;
            precursor = nullptr;
        }
        else if(cursor == nullptr || cursor == tailPtr) {
            new_node->next = nullptr;
            tailPtr->next = new_node;
            precursor = tailPtr;
            tailPtr = new_node;
            cursor = new_node;
        }
        else {
            new_node->next = cursor->next;
            cursor->next = new_node;
            precursor = cursor;
            cursor = new_node;
        }
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::remove_current() {
        assert(is_item());
        numItems--;
        if (cursor == headPtr) { // at the head
            node* next = cursor->next;
            delete cursor;
            cursor = next;
            headPtr = next;
            precursor = nullptr;
            if (size() <= 1) {
                tailPtr = headPtr;
            }
            
        }
        else if (cursor == tailPtr) { // at the tail
            precursor->next = cursor->next;
            tailPtr = precursor;
            delete cursor;
            cursor =nullptr;
            precursor = nullptr;
        }
        else { // middle of the body
            precursor->next = cursor->next;
            delete cursor;
            cursor = precursor->next;
        }
        
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