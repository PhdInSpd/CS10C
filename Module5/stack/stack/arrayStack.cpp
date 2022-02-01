#include <cassert>       // For assert

namespace cs_stack {
    template<typename ItemType>
    ArrayStack<ItemType>::ArrayStack() {
        numItems = 0;
    }






    template<class ItemType>
    bool ArrayStack<ItemType>::isEmpty() const {
        return numItems == 0;
    }






    template<class ItemType>
    void ArrayStack<ItemType>::push(const ItemType& newEntry) {
        if (numItems < DEFAULT_CAPACITY) {
            numItems++;
            items[numItems - 1] = newEntry;
        }
        else {
            throw CapacityExceededError();
        }
    }






    template<class ItemType>
    void ArrayStack<ItemType>::pop() {
        if (!isEmpty())
        {
            numItems--;
        }
        else {
            throw StackEmptyError();
        }
    }





    template<class ItemType>
    ItemType ArrayStack<ItemType>::top() const {
        if (!isEmpty()) {
            return items[numItems - 1];
        }
        else {
            throw StackEmptyError();
        }
    }
}
