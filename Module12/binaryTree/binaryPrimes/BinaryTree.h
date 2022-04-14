#pragma once
/*
student   : Jose Alfredo Martinez
instructor : Dave Harden
class : CS 10C
	date : April 13, 2022
	file name : binarytree.h
*/
#include <cstdlib>	// for size_t
#include "ll.h"

class binarytree {

public:
	using size_type = std::size_t;
	binarytree();
	binarytree(const binarytree& copy);
	binarytree& operator=( const binarytree& copy);
	~binarytree();
	
	void insert(int item);
	void print() const;
	size_type size() const;
	int find(int target, bool& found) const;
	void del(int target, bool& found);

	// assignment 12.2
	size_type numPrimes();
	LL<int> toLL();

private:
	struct treenode {
		int data;
		treenode* left;
		treenode* right;
	};

	treenode* root;
	static void insert_aux(treenode*& root, int item);
	static void print_aux(const treenode* root);
	static size_type size_aux(const treenode* root);
	static int find_aux(const treenode* root, int target, bool& found);
	static void del_aux(treenode*& root, int target, bool& found);
	static void remove_max(treenode*& root, int& max);

	// assignment 12.2
	// size of binarytree
	size_type mSize;

	static size_type numPrimesAux(const treenode * root);
	static void toLLAux(const treenode* root, LL<int>& copy);
	static void copy( const treenode* srcRoot, treenode*& dstRoot);
	static void clear( treenode* & dstRoot);
public:
	static bool isPrime(int canidate);
};
