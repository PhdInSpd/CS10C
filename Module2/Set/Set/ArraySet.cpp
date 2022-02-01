/*
    student: Jose Alfredo Martinez
    instructor : Dave Harden
    class : CS 10C
    date : Jan 21, 2022
*/
namespace cs_set {

    template<typename ItemType>
    void ArraySet<ItemType>::add(const ItemType& newEntry) {
        if (itemCount >= maxItems) {
            throw CapacityExceededError();
        }
        if (contains(newEntry)) {
            throw DuplicateItemError();
        }
        items[itemCount] = newEntry;
        itemCount++;
    }






    template<typename ItemType>
    void ArraySet<ItemType>::add(const ArraySet<ItemType> & otherSet) {
        for (size_t i = 0; i < otherSet.itemCount; i++) {
            add(otherSet.items[i]);
        }
    }






    template<typename ItemType>
    void ArraySet<ItemType>::add(const std::vector<ItemType>& itemList) {
        // std::vector<T>::const_iterator give compiler error C2760
        // typename std::vector<ItemType>::const_iterator it fixes error
        for (typename std::vector<ItemType>::const_iterator it/*auto it*/ = itemList.begin(); it != itemList.end(); it++ ) {
            add(*it);
        }
    }
    
    
    
    
    
    
    template<typename ItemType>
    ArraySet<ItemType>::ArraySet() {
        itemCount = 0;
        maxItems = DEFAULT_CAPACITY;
    }





    template<typename ItemType>
    int ArraySet<ItemType>::getCurrentSize() const {
        return itemCount;
    }





    template<typename ItemType>
    bool ArraySet<ItemType>::isEmpty() const {
        return itemCount == 0;
    }




    template<typename ItemType>
    std::vector<ItemType> ArraySet<ItemType>::toVector() const {
        std::vector<ItemType> setContents;
        for (size_t i = 0; i < itemCount; i++) {
            setContents.push_back(items[i]);
        }

        return setContents;
    }




    template <typename ItemType>
    bool ArraySet<ItemType>::contains(const ItemType& anEntry) const {
        for (size_t i = 0; i < itemCount; i++) {
            if (items[i] == anEntry) {
                return true;
            }
        }
        return false;
    }





    template<typename ItemType>
    void ArraySet<ItemType>::clear() {
        itemCount = 0;
    }





    template<typename ItemType>
    int ArraySet<ItemType>::getIndexOf(const ItemType& target) const {
        for (rsize_t i = 0; i < itemCount; i++) {
            if (items[i] == target) {
                return i;
            }
        }

        return -1;
    }






    template<typename ItemType>
    void ArraySet<ItemType>::remove(const ItemType& anEntry) {
        int locatedIndex = getIndexOf(anEntry);
        if (locatedIndex > -1) {
            itemCount--;
            items[locatedIndex] = items[itemCount];
        }
        else {
            throw ItemNotFoundError();
        }
    }






    template<typename ItemType>
    ArraySet<ItemType> ArraySet<ItemType>::setUnion(const ArraySet& otherSet) {
        ArraySet<ItemType> union1;
        union1.add(*this);
        union1.add(otherSet);
        return union1;
    }
    





    template<typename ItemType>
    ArraySet<ItemType> ArraySet<ItemType>::setIntersection(const ArraySet& otherSet) {
        ArraySet<ItemType> intersection;
        for (size_t i = 0; i < otherSet.itemCount; i++) {
            if ( this->contains(otherSet.items[i]) ) {
                intersection.add(otherSet.items[i]);
            }
        }
        return intersection;
    }
    





    template<typename ItemType>
    ArraySet<ItemType> ArraySet<ItemType>::setDifference(const ArraySet& otherSet) {
        ArraySet<ItemType> intersection = setIntersection(otherSet);
        ArraySet<ItemType> difference;
        difference.add(*this);
        for (size_t i = 0; i < intersection.itemCount; i++) {
            difference.remove(intersection.items[i]);
        }
        return difference;
    }
}