//  This is the file LL.cpp

#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
LL<T>::LL() {
    list = nullptr;
}

template <typename T>
void LL<T>::delete_after(iterator& position) {
    assert(position.link()->next != nullptr);
    node* tempptr = position.link()->next;
    position.link()->next = position.link()->next->next;
    delete tempptr;
}



template <typename T>
void LL<T>::insert_after(iterator& position, const value_type& insertMe) {
    node* newnode = new node;
    newnode->data = insertMe;
    newnode->next = position.link()->next;
    position.link()->next = newnode;
    position.link() = newnode;
}



template <typename T>
void LL<T>::pop_front() {
    if (empty()) {
        throw Empty_List_Error();
    }
    else {
        node* deleteMe = list;
        list = list->next;
        delete deleteMe;
    }

}





template <typename T>
typename LL<T>::value_type& LL<T>::front() {
    if (empty()) {
        throw Empty_List_Error();
    }
    else {
        return list->data;
    }
}





template <typename T>
const typename LL<T>::value_type& LL<T>::front()  const {
    if (empty()) {
        throw Empty_List_Error();
    }
    else {
        return list->data;
    }
}






template <typename T>
void LL<T>::clear() {
    node* deleteMe;
    while (list != nullptr) {
        deleteMe = list;
        list = list->next;
        delete deleteMe;
        deleteMe = nullptr;
    }
}





// Note this is an exact copy of the clone() function from SimpleList

template <typename T>
void LL<T>::clone(const LL<T>& copyMe) {
    //clear();
    if (copyMe.list == nullptr) {
        list = nullptr;
        return;
    }
    /*
    list = new node;
    list->data = copyMe.list->data;

    node* newListPtr = list;
    node* sourcePtr = copyMe.list->next;
    while (sourcePtr != nullptr) {
        newListPtr->next = new node;
        newListPtr = newListPtr->next;
        newListPtr->data = sourcePtr->data;
        newListPtr->next = nullptr;
        sourcePtr = sourcePtr->next;
    }*/
        
    //node* sourcePtr = &copyMe;
    node* sourcePtr = copyMe.list;
    node* newListPtr = new node();
    newListPtr->data = sourcePtr->data;
    newListPtr->next = nullptr;
    list = newListPtr;

    sourcePtr = sourcePtr->next;
        
    while ( sourcePtr != nullptr ) {
        newListPtr->next = new node();
        newListPtr       = newListPtr->next;
        newListPtr->data = sourcePtr->data;
        newListPtr->next = nullptr;
        sourcePtr        = sourcePtr->next;
    }
}





// returns the number of items in the LL object.
template <typename T>
typename LL<T>::size_type LL<T>::size() const {
    LL<T>::size_type numberOfItems = 0;
    node* curPtr = list;
    while (curPtr != nullptr) {
        ++numberOfItems;
        curPtr = curPtr->next;
    }
    return numberOfItems;
}





// returns true if the LL object is empty, false otherwise.
template <typename T>
bool LL<T>::empty() const {
    return list == nullptr;
}





// insert x at the front of the LL object.
template <typename T>
void LL<T>::push_front(const value_type& item) {
    node* oldList = list;
    list = new node;
    list->next = oldList;
    list->data = item;
}











// THE BIG-3

template <typename T>
LL<T>  LL<T>::operator=(const LL<T>& right) {
    if (this != &right) {
        clear();
        clone(right);
    }
    return *this;
}





template <typename T>
LL<T>::LL(const LL<T>& copyMe) {
    clone(copyMe);
}






template <typename T>
LL<T>::~LL() {
    clear();
}