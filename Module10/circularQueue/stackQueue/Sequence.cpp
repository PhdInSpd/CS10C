/*
student   : Jose Alfredo Martinez
instructor: Dave Harden
class     : CS 10C
date      : April 02, 2022
file name : sequence.cpp

sequence.h implementation
*/
namespace cs_sequence {
    template<typename ItemType>
    typename SequenceTemplate<ItemType>::size_type  SequenceTemplate<ItemType>::size() const {
        int total = stack1.size() + stack2.size();
        return total;
    }

    template<typename ItemType>
    SequenceTemplate<ItemType>::SequenceTemplate() {
    }

    template<typename ItemType>
    SequenceTemplate<ItemType>::~SequenceTemplate() {
        start();
        while ( size() > 0 ) {
            remove_current();
        }
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::start() {
        if ( size() == 0 ) return;

        if ( stack1.size() == 0) {
            ItemType top2 = stack2.top();
            stack2.pop();
            stack1.push(top2);
        }
        else {
            while (stack1.size() > 1) {
                ItemType top1 = stack1.top();
                stack1.pop();
                stack2.push(top1);
            }
        }
        
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::advance() {
        assert(is_item());
        // current at end of sequence
        if (stack2.size() == 0) {
            //set no current item
            while (stack1.size() > 0) {
                ItemType top1 = stack1.top();
                stack1.pop();
                stack2.push(top1);
            }
        }
        else {
            ItemType top2 = stack2.top();
            stack2.pop();
            stack1.push(top2);
        }
        
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::insert(const value_type& entry) {
        if (!is_item()) {
            stack1.push(entry);
        }
        else {
            ItemType top1 = stack1.top();
            stack1.pop();
            stack2.push(top1);
            stack1.push(entry);
        }
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::attach(const value_type& entry) {
        bool currentItem = is_item();
        if (!currentItem) {
            // place current at the end of sequence
            while (stack2.size() > 0) {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        stack1.push(entry);
    }

    template<typename ItemType>
    void SequenceTemplate<ItemType>::remove_current() {
        assert(is_item());
        stack1.pop();
        bool lastItem = stack2.size() == 0;
        if (lastItem) {
            // no current item
            while (stack1.size() > 0) {
                stack2.push( stack1.top() );
                stack1.pop();
            }
        }
        else if ( stack2.size() > 0 ) {
            stack1.push( stack2.top() );
            stack2.pop();
        }
    }

    template<typename ItemType>
    bool SequenceTemplate<ItemType>::is_item() const{        
        int size = stack1.size();
        return size > 0;
    }

    template<typename ItemType>
    typename SequenceTemplate<ItemType>::value_type SequenceTemplate<ItemType>::current() const {
        assert(is_item());
        return stack1.top();
    }
}