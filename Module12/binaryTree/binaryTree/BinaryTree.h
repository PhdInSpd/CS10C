#pragma once
// Here is the file binarytree.h
#include <cstdlib>	// for size_t

class binarytree {

public:
	typedef std::size_t size_type;
	binarytree();
	void insert(int item);
	void print() const;
	void printLevel() const;
	size_type size() const;
	int find(int target, bool& found) const;
	void del(int target, bool& found);
	void readTree(int n);
private:
	struct treenode {
		int data;
		treenode* left;
		treenode* right;
	};

	treenode* root;
	static void insert_aux(treenode*& root, int item);
	static void print_aux(const treenode* root);
	static void print_level_aux(const treenode* root, int level);
	static size_type size_aux(const treenode* root);
	static int find_aux(const treenode* root, int target, bool& found);
	static void del_aux(treenode*& root, int target, bool& found);
	static void remove_max(treenode*& root, int& max);
	static treenode* read_tree_aux(int n);
};
