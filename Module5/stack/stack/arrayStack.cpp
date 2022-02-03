/*
student   : Jose Alfredo Martinez
instructor: Dave Harden
class     : CS 10C
date      : Feb 02, 2022
file name : arrayStack.cpp

implement a stack with a dynamic memory for the items
*/

namespace cs_stack {
    template<typename ItemType>
    ArrayStack<ItemType>::ArrayStack(int inMemoryChunk):
                            capacity(0),
                            numItems(0),
                            memoryIndex(3),
                            memoryChunk(inMemoryChunk),
                            itemsPtr(nullptr) {
    }
    





    template<typename ItemType>
    ArrayStack<ItemType>::ArrayStack(const ArrayStack<ItemType>& copy) {
        clone(copy);
    }






    template<typename ItemType>
    void ArrayStack<ItemType>::copy(ItemType* itemsPtr, ItemType* destinationPtr, int numToCopy) {
        for (size_t i = 0; i < numToCopy; i++) {
            destinationPtr[i] = itemsPtr[i];
        }
    }






    template<typename ItemType>
    void ArrayStack<ItemType>::clear() {
        if (itemsPtr == nullptr) return;
        delete[]itemsPtr;
        itemsPtr = nullptr;
    }






    template<typename ItemType>
    bool ArrayStack<ItemType>::getDoubleCapacity() {
        return memoryChunk <= 0;
    }






    template<typename ItemType>
    ArrayStack<ItemType>::~ArrayStack() {
        clear();
    }






    template<typename ItemType>
    bool ArrayStack<ItemType>::isEmpty() const {
        return numItems == 0;
    }





    template<typename ItemType>
    int ArrayStack<ItemType>::getNumItems() const {
        return numItems;
    }





    template<typename ItemType>
    int ArrayStack<ItemType>::getCapacity() const {
        return capacity;
    }






    template<typename ItemType>
    void ArrayStack<ItemType>::clone(const ArrayStack<ItemType>& other) {
        capacity = other.capacity;
        memoryIndex = other.memoryIndex;
        memoryChunk = other.memoryChunk;
        numItems = other.numItems;
        if (numItems == 0) return;

        // copy the items
        ItemType* destinationPtr = new ItemType[capacity];

        // copy the data
        copy(other.itemsPtr, destinationPtr, numItems);

        itemsPtr = destinationPtr;
    }





    template<typename ItemType>
    ArrayStack<ItemType>& ArrayStack<ItemType>::operator=(const ArrayStack<ItemType>& other) {
        clear();
        clone(other);
        return *this;
    }

    template<typename ItemType>
    void ArrayStack<ItemType>::handleCapacity() {
        if (numItems < capacity) return;
        if (getDoubleCapacity()) {
            if (capacity <= 0) {
                capacity = 1;
            }
            else {
                capacity *= 2;
            }
        }
        else { // 3k, 5k, 7k, ... increment
            capacity += memoryIndex * memoryChunk;
            memoryIndex += 2;
        }
            
        ItemType* destinationPtr = new ItemType[capacity];

        // copy the data
        copy(itemsPtr, destinationPtr, numItems);

        // delete old memory
        clear();

        itemsPtr = destinationPtr;
    }
    

    template<typename ItemType>
    void ArrayStack<ItemType>::push(const ItemType& newEntry) {
        handleCapacity();
        numItems++;
        itemsPtr[numItems - 1] = newEntry;
    }






    template<typename ItemType>
    void ArrayStack<ItemType>::pop() {
        if (!isEmpty())
        {
            numItems--;
        }
        else {
            throw StackEmptyError();
        }
    }





    template<typename ItemType>
    ItemType ArrayStack<ItemType>::top() const {
        if (!isEmpty()) {
            return itemsPtr[numItems - 1];
        }
        else {
            throw StackEmptyError();
        }
    }





    /*
    output

    apacity should double
    0:i 0:top 1:capacity 1:getNumItems
    1:i 1:top 2:capacity 2:getNumItems
    2:i 2:top 4:capacity 3:getNumItems
    3:i 3:top 4:capacity 4:getNumItems
    4:i 4:top 8:capacity 5:getNumItems
    5:i 5:top 8:capacity 6:getNumItems
    6:i 6:top 8:capacity 7:getNumItems
    7:i 7:top 8:capacity 8:getNumItems
    8:i 8:top 16:capacity 9:getNumItems
    9:i 9:top 16:capacity 10:getNumItems
    10:i 10:top 16:capacity 11:getNumItems
    11:i 11:top 16:capacity 12:getNumItems
    12:i 12:top 16:capacity 13:getNumItems
    13:i 13:top 16:capacity 14:getNumItems
    14:i 14:top 16:capacity 15:getNumItems
    15:i 15:top 16:capacity 16:getNumItems
    16:i 16:top 32:capacity 17:getNumItems
    17:i 17:top 32:capacity 18:getNumItems
    18:i 18:top 32:capacity 19:getNumItems
    19:i 19:top 32:capacity 20:getNumItems
    capacity increase by (2n+1)*2
    0:i 0:top 6:capacity 1:getNumItems
    1:i 10:top 6:capacity 2:getNumItems
    2:i 20:top 6:capacity 3:getNumItems
    3:i 30:top 6:capacity 4:getNumItems
    4:i 40:top 6:capacity 5:getNumItems
    5:i 50:top 6:capacity 6:getNumItems
    6:i 60:top 16:capacity 7:getNumItems
    7:i 70:top 16:capacity 8:getNumItems
    8:i 80:top 16:capacity 9:getNumItems
    9:i 90:top 16:capacity 10:getNumItems
    10:i 100:top 16:capacity 11:getNumItems
    11:i 110:top 16:capacity 12:getNumItems
    12:i 120:top 16:capacity 13:getNumItems
    13:i 130:top 16:capacity 14:getNumItems
    14:i 140:top 16:capacity 15:getNumItems
    15:i 150:top 16:capacity 16:getNumItems
    16:i 160:top 30:capacity 17:getNumItems
    17:i 170:top 30:capacity 18:getNumItems
    18:i 180:top 30:capacity 19:getNumItems
    19:i 190:top 30:capacity 20:getNumItems
    print original stackDouble
    19
    18
    17
    16
    15
    14
    13
    12
    11
    10
    9
    8
    7
    6
    5
    4
    3
    2
    1
    0
    print copy of stackDouble
    19
    18
    17
    16
    15
    14
    13
    12
    11
    10
    9
    8
    7
    6
    5
    4
    3
    2
    1
    0
    print original stack3K
    190
    180
    170
    160
    150
    140
    130
    120
    110
    100
    90
    80
    70
    60
    50
    40
    30
    20
    10
    0
    print assignment of stack3K
    190
    180
    170
    160
    150
    140
    130
    120
    110
    100
    90
    80
    70
    60
    50
    40
    30
    20
    10
    0
    first pop should not throw exception
    no exception
    2nd pop should  throw exception
    StackEmptyError exception
    */
}
