/*
student   : Jose Alfredo Martinez
instructor: Dave Harden
class     : CS 10C
date      : April 02, 2022
file name : sequence.h

Declare a list class
*/
#pragma once
#include <stack>
#include <cassert>
namespace cs_sequence {

	template<typename ItemType>
	class SequenceTemplate {
	private:
		std::stack<ItemType> stack1;
		std::stack<ItemType> stack2;
	public:

		using value_type = ItemType;
		using size_type = size_t;

		// postcondition: Remove all items from the list
		~SequenceTemplate();

		// postcondition: The Sequence has been initialized to an empty Sequence.
		SequenceTemplate();

		// postcondition: The first item in the Sequence becomes the current item (but if the 
		// Sequence is empty, then there is no current item).
		void start();

		// precondition: is_item() returns true
		// Postcondition: If the current item was already the last item in the Sequence, then there 
		// is no longer any current item. Otherwise, the new current item is the item immediately after 
		// the original current item.
		void advance();

		// Postcondition: A new copy of entry has been inserted in the Sequence before the 
		// current item. If there was no current item, then the new entry has been inserted at the 
		// front. In either case, the new item is now the current item of the Sequence.
		void insert(const value_type& entry);
		
		// Postcondition: A new copy of entry has been inserted in the Sequence after the current 
		// item. If there was no current item, then the new entry has been attached to the end of 
		// the Sequence. In either case, the new item is now the current item of the Sequence.
		void attach(const value_type& entry);
		
		// Precondition: is_item returns true. 
		// Postcondition: The current item has been removed from the Sequence.  If the item removed 
		// was the last item in the Sequence, then there is now no current item.  Otherwise, the item
		// that was after the removed item is now the current item.
		void remove_current();

		// Postcondition: Returns the number of items in the Sequence.
		size_type size() const;

		// Postcondition: A true return value indicates that there is a valid "current" item that
		// may be retrieved by the current member function (listed below). A false return value
		// indicates that there is no valid current item.
		bool is_item() const;
		
		// Precondition: is_item() returns true
		// Postcondition: The current item in the Sequence is returned.
		value_type current() const;
		
	};

	/// <summary>
	/// An integer version of sequenceTemplate
	/// </summary>
	class Sequence : public SequenceTemplate<int> {

	};
}
#include "Sequence.cpp"	