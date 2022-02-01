// file myvector.cpp

template <typename T>
MyVector<T>::MyVector(size_type inSize, const value_type& inValue) {
    mSize = inSize;
    mCapacity = inSize;
    items = new value_type[inSize];
    for (size_type i = 0; i < mSize; i++) {
        items[i] = inValue;
    }
}




template <typename T>
typename MyVector<T>::size_type MyVector<T>::size() const {
    return mSize;
}



template <typename T>
void MyVector<T>::push_back(const value_type& inValue) {
    if (mSize < mCapacity) {
        items[mSize] = inValue;
        mSize++;
    }
    else {
        if (mCapacity == 0) {
            mCapacity = 1;
        }
        else {
            mCapacity *= 2;
        }
        value_type* temp = new value_type[mCapacity];
        for (size_type i = 0; i < mSize; i++) {
            temp[i] = items[i];
        }
        temp[mSize] = inValue;
        mSize++;
        delete[] items;
        items = temp;
    }
}


template <typename T>
typename MyVector<T>::size_type MyVector<T>::capacity() const {
    return mCapacity;
}




template <typename T>
typename MyVector<T>::value_type MyVector<T>::at(size_type i) const {
    assert(i >= 0 && i < size());
    return items[i];
}

