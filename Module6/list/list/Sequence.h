/*
student   : Jose Alfredo Martinez
instructor: Dave Harden
class     : CS 10C
date      : Feb 06, 2022
file name : sequence.h

Declare a list class
*/
#pragma once
#include <cassert>
namespace cs_sequence {

	template<typename ItemType>
	class SequenceTemplate {
	public:
		class Node {
		public:
			Node() :data(0), nextPtr(nullptr)/*, lastPtr(nullptr)*/ {
			}
			ItemType data;
			Node* nextPtr;
			/*Node* lastPtr;*/
		};
	private:
		/// <summary>
		/// The number of items stored
		/// </summary>
		int numItems;

		/// <summary>
		///  The head and tail pointers of the linked list. If the Sequence has no items, 
		/// then these pointers are both nullptr. The reason for the tail pointer is the 
		/// attach function. Normally this function adds a new item immediately after the 
		/// current node. But if there is no current node, then attach places its new item
		///  at the tail of the list, so it makes sense to keep a tail pointer around.
		/// </summary>
		Node* headPtr;
		Node* tailPtr;
		/// <summary>
		///  Points to the node with the current item (or nullptr if there is no current item).
		/// </summary>
		Node* cursor;
		/// <summary>
		/// precursor. Points to the node before current item, or nullptr if there is no
		///  current item or if the current item is the first node. Note that precursor 
		/// points to nullptr if there is no current item, or, to put it another way,
		///  points to nullptr whenever cursor points to nullptr. Can you figure out why
		///  we propose a precursor? The answer is the insert function, which normally
		///  adds a new item immediately before the current node. But the linked-list
		///  functions have no way of inserting a new node before a speci- fied node.
		///  We can only add new nodes after a specified node. Therefore, the insert
		///  function will work by adding the new item after the precursor node -- which
		///  is also just before the cursor node.
		/// </summary>
		Node* precursor;


	public:

		using value_type = ItemType;
		using size_type = size_t;
		
		~SequenceTemplate();
		// postcondition: Remove all items from the list

		SequenceTemplate();
		// postcondition: The Sequence has been initialized to an empty Sequence.

		void start();
		// postcondition: The first item in the Sequence becomes the current item (but if the 
		// Sequence is empty, then there is no current item).

		void advance();
		// precondition: is_item() returns true
		// Postcondition: If the current item was already the last item in the Sequence, then there 
		// is no longer any current item. Otherwise, the new current item is the item immediately after 
		// the original current item.

		void insert(const value_type& entry);
		// Postcondition: A new copy of entry has been inserted in the Sequence before the 
		// current item. If there was no current item, then the new entry has been inserted at the 
		// front. In either case, the new item is now the current item of the Sequence.

		void attach(const value_type& entry);
		// Not required this week
		// Postcondition: A new copy of entry has been inserted in the Sequence after the current 
		// item. If there was no current item, then the new entry has been attached to the end of 
		// the Sequence. In either case, the new item is now the current item of the Sequence.

		void remove_current();
		// Not required this week
		// Precondition: is_item returns true. 
		// Postcondition: The current item has been removed from the Sequence.  If the item removed 
		// was the last item in the Sequence, then there is now no current item.  Otherwise, the item
		// that was after the removed item is now the current item.


		size_type size() const;
		// Postcondition: Returns the number of items in the Sequence.

		bool is_item() const;
		// Postcondition: A true return value indicates that there is a valid "current" item that
		// may be retrieved by the current member function (listed below). A false return value
		// indicates that there is no valid current item.

		value_type current() const;
		// Precondition: is_item() returns true
		// Postcondition: The current item in the Sequence is returned.
	};

	/// <summary>
	/// An integer version of sequenceTemplate
	/// </summary>
	class Sequence : public SequenceTemplate<int> {

	};
}
#include "Sequence.cpp"	