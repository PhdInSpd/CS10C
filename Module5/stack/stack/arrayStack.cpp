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
    ArrayStack<ItemType>::ArrayStack():
                            capacity(0),
                            numItems(0),
                            itemsPtr(nullptr) {
        itemsPtr = new ItemType[DEFAULT_CAPACITY];
        capacity = DEFAULT_CAPACITY;
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
        bool reSize = false;
        if (numItems >= capacity) {
            if (capacity <= 0) {
                capacity = DEFAULT_CAPACITY;
            }
            else {
                capacity *= 2;
            }
            reSize = true;
        }
        else {
            int middle = capacity / 2;
            if (numItems < middle) {
                capacity = capacity / 2;
                reSize = true;
            }
        }
        if (!reSize) return;
        
         
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

    stack is empty:1
push test
0:i 0:top 1:capacity 1:getNumItems()
1:i 1:top 2:capacity 2:getNumItems()
2:i 2:top 4:capacity 3:getNumItems()
3:i 3:top 4:capacity 4:getNumItems()
4:i 4:top 8:capacity 5:getNumItems()
5:i 5:top 8:capacity 6:getNumItems()
6:i 6:top 8:capacity 7:getNumItems()
7:i 7:top 8:capacity 8:getNumItems()
8:i 8:top 16:capacity 9:getNumItems()
9:i 9:top 16:capacity 10:getNumItems()
10:i 10:top 16:capacity 11:getNumItems()
11:i 11:top 16:capacity 12:getNumItems()
12:i 12:top 16:capacity 13:getNumItems()
13:i 13:top 16:capacity 14:getNumItems()
14:i 14:top 16:capacity 15:getNumItems()
15:i 15:top 16:capacity 16:getNumItems()
16:i 16:top 32:capacity 17:getNumItems()
17:i 17:top 32:capacity 18:getNumItems()
18:i 18:top 32:capacity 19:getNumItems()
19:i 19:top 32:capacity 20:getNumItems()
20:i 20:top 32:capacity 21:getNumItems()
21:i 21:top 32:capacity 22:getNumItems()
22:i 22:top 32:capacity 23:getNumItems()
23:i 23:top 32:capacity 24:getNumItems()
24:i 24:top 32:capacity 25:getNumItems()
25:i 25:top 32:capacity 26:getNumItems()
26:i 26:top 32:capacity 27:getNumItems()
27:i 27:top 32:capacity 28:getNumItems()
28:i 28:top 32:capacity 29:getNumItems()
29:i 29:top 32:capacity 30:getNumItems()
30:i 30:top 32:capacity 31:getNumItems()
31:i 31:top 32:capacity 32:getNumItems()
0:i 0:top 16:capacity 1:getNumItems()
1:i 1:top 8:capacity 2:getNumItems()
2:i 2:top 4:capacity 3:getNumItems()
3:i 3:top 4:capacity 4:getNumItems()
4:i 4:top 8:capacity 5:getNumItems()
5:i 5:top 8:capacity 6:getNumItems()
6:i 6:top 8:capacity 7:getNumItems()
7:i 7:top 8:capacity 8:getNumItems()
8:i 8:top 16:capacity 9:getNumItems()
9:i 9:top 16:capacity 10:getNumItems()
10:i 10:top 16:capacity 11:getNumItems()
11:i 11:top 16:capacity 12:getNumItems()
12:i 12:top 16:capacity 13:getNumItems()
13:i 13:top 16:capacity 14:getNumItems()
14:i 14:top 16:capacity 15:getNumItems()
15:i 15:top 16:capacity 16:getNumItems()
16:i 16:top 32:capacity 17:getNumItems()
17:i 17:top 32:capacity 18:getNumItems()
18:i 18:top 32:capacity 19:getNumItems()
19:i 19:top 32:capacity 20:getNumItems()
20:i 20:top 32:capacity 21:getNumItems()
21:i 21:top 32:capacity 22:getNumItems()
22:i 22:top 32:capacity 23:getNumItems()
23:i 23:top 32:capacity 24:getNumItems()
24:i 24:top 32:capacity 25:getNumItems()
25:i 25:top 32:capacity 26:getNumItems()
26:i 26:top 32:capacity 27:getNumItems()
27:i 27:top 32:capacity 28:getNumItems()
28:i 28:top 32:capacity 29:getNumItems()
29:i 29:top 32:capacity 30:getNumItems()
30:i 30:top 32:capacity 31:getNumItems()
31:i 31:top 32:capacity 32:getNumItems()
stack is empty:0
print original stackDouble
31
30
29
28
27
26
25
24
23
22
21
20
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
31
30
29
28
27
26
25
24
23
22
21
20
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
    */
}
