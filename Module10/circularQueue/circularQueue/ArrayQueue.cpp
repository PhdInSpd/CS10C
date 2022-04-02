#include <iostream>

template<typename ItemType>
ArrayQueue<ItemType>::ArrayQueue() {
    front = 0;
    back = DEFAULT_CAPACITY - 1;
    numItems = 0;
    capacity = 0;

    allocDefaultCapacity();
}

template<typename ItemType>
void ArrayQueue<ItemType>::allocDefaultCapacity() {
    if (capacity <= 0) {
        capacity = DEFAULT_CAPACITY;
        items = new ItemType[capacity];
    }
}

template<typename ItemType>
ArrayQueue<ItemType>::ArrayQueue(const ArrayQueue& copy) {
    clone(copy);
}

template<typename ItemType>
void ArrayQueue<ItemType>::clone(const ArrayQueue& copy) {
    capacity = copy.capacity;
    items = new ItemType[capacity];

    numItems = copy.numItems;
    front = copy.front;
    back = copy.back;

    for (size_t i = 0; i < numItems; i++) {
        items[i] = copy.items[i];
    }
}

template<typename ItemType>
ArrayQueue<ItemType>::~ArrayQueue() {
    deallocate();
}

template<typename ItemType>
ArrayQueue<ItemType>& ArrayQueue<ItemType>::operator=(const ArrayQueue<ItemType>& copyMe) {
    if (this != &copyMe) {
        deallocate();
        clone(copyMe);
    }
    return *this;
}

template<typename ItemType>
void ArrayQueue<ItemType>::deallocate() {
    if (items == nullptr) return;
    numItems = 0;
    front = 0;
    back = 0;
    delete[] items;
    items = nullptr;
}

template<typename ItemType>
bool ArrayQueue<ItemType>::isEmpty() const {
   return numItems == 0;
}

template<typename ItemType>
void ArrayQueue<ItemType>::enqueue(const ItemType& newEntry) {
    allocDefaultCapacity();
#pragma region resize buffer if needed
    int newNumItems = numItems + 1;
    if (newNumItems > capacity) {
        int newCapacity = 2 * capacity;
        ItemType* newItems = new ItemType[newCapacity];

        // copy items to newItems;
        int frontIndex = front;
        for (size_t i = 0; i < numItems; i++) {
            newItems[i] = items[frontIndex];
            frontIndex = (frontIndex + 1) % capacity;
        }
        // delete old items
        delete[]items;

        // update with new items
        items = newItems;
        capacity = newCapacity;

        front = 0;
        back = numItems - 1;
    }
#pragma endregion
    
    back = (back + 1) % capacity;
    items[back] = newEntry;
    numItems++;
}

template<typename ItemType>
void ArrayQueue<ItemType>::dequeue() {
   if (isEmpty()) {
       throw PrecondViolatedExcep("dequeue() called with empty queeu");
   }

   // remove front
   front = (front + 1) % capacity;
   numItems--;

#pragma region resize buffer if needed
   if (numItems <= capacity/2) {
       int newCapacity = capacity/2;
       ItemType* newItems = nullptr;
       if (newCapacity > 0) {
            newItems = new ItemType[newCapacity];
       }

       // copy items to newItems;
       int frontIndex = front;
       for (size_t i = 0; i < numItems; i++) {
           newItems[i] = items[frontIndex];
           frontIndex = (frontIndex + 1) % capacity;
       }
       // delete old items
       delete[]items;

       // update with new items
       items = newItems;
       capacity = newCapacity;

       front = 0;
       back = 0;
       if (numItems > 0) {
           back = numItems - 1;
       }
   }
#pragma endregion
}

template<typename ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const
{
    if (isEmpty()) {
        throw PrecondViolatedExcep("peekFront() called with empty queue");
    }

   return items[front];
}

template<typename ItemType>
void ArrayQueue<ItemType>::print() const {
    std::cout << "Here is the queue: ";
    if (isEmpty()) {
        std::cout << "empty";
    } else {
        for (int i = front; i != back; i = (i + 1) % capacity) {
            std::cout << items[i] << " ";
        }
        std::cout << items[back];
    }
}

template<typename ItemType>
int ArrayQueue<ItemType>::getCapacity() const {
    return capacity;
}