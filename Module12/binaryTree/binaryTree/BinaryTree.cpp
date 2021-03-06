// Here is the file binarytree.cpp

#include <iostream>
#include <iomanip>
#include "binarytree.h"
using namespace std;



binarytree::binarytree() {
	root = nullptr;
}


void binarytree::print() const {
	print_aux(root);
}


void binarytree::printLevel() const {
	print_level_aux(root,0);
}

void binarytree::insert(int item) {
	insert_aux(root, item);
}


binarytree::size_type binarytree::size() const {
	return size_aux(root);
}


int binarytree::find(int target, bool& found) const {
	return find_aux(root, target, found);
}


void binarytree::del(int target, bool& found) {
	del_aux(root, target, found);
}


void binarytree::del_aux(treenode*& root,
	int target,
	bool& found) {

	if (root == nullptr) {
		found = false;
	}
	else if (target < root->data) {
		del_aux(root->left, target, found);
	}
	else if (target > root->data) {
		del_aux(root->right, target, found);
	}
	else if (root->left == nullptr) {
		treenode* tempptr = root;
		root = root->right;
		delete tempptr;
		found = true;
	}
	else {
		int max;
		// step 1
		remove_max(root->left, max);
		// step 2
		root->data = max;
		found = true;
	}
}

// pre: root != nullptr
// when removing a node 
//	1) find find the max value in the left tree, return that max value and delete that max node
//	2) replace max value in root node
void binarytree::remove_max( treenode*& root, int& max ) {
	if (root->right == nullptr) {
		max = root->data;
		treenode* tempptr = root;
		root = root->left;
		delete tempptr;
	}
	else {
		remove_max(root->right, max);
	}
}



int binarytree::find_aux(const treenode* root,
	int target,
	bool& found) {

	if (root == nullptr) {
		found = false;
		return 0;
	}
	else if (target == root->data) {
		found = true;
		return root->data;
	}
	else if (target < root->data) {
		return find_aux(root->left, target, found);
	}
	else {
		return find_aux(root->right, target, found);
	}
}


binarytree::size_type binarytree::size_aux(const treenode* root) {
	if (root == nullptr) {
		return 0;
	}
	else {
		return size_aux(root->left)
			+ size_aux(root->right)
			+ 1;
	}
}


void binarytree::insert_aux(treenode*& root, int item) {
	if (root == nullptr) {
		root = new treenode;
		root->data = item;
		root->left = nullptr;
		root->right = nullptr;
	}
	else if (item <= root->data) {
		insert_aux(root->left, item);
	}
	else {
		insert_aux(root->right, item);
	}
}


void binarytree::print_aux(const treenode* root) {
	if (root != nullptr) {
		print_aux(root->left);
		cout << root->data << " ";
		print_aux(root->right);
	}
}


void binarytree::print_level_aux(const treenode* root, int level) {
	if (root != nullptr) {
		print_level_aux(root->right, level + 1);
		cout << std::setw((level +1) * 7) << root->data << endl << endl;
		print_level_aux(root->left, level + 1);
	}
}


binarytree::treenode* binarytree::read_tree_aux(int n) {
	int rootItem;
	if (n > 0) {
		treenode* treePtr = new treenode;
		treePtr->left = nullptr;
		treePtr->right = nullptr;


		//      cin >> rootItem;
		//      treePtr -> data = rootItem;

		treePtr->left = read_tree_aux(n / 2);


		cin >> rootItem;
		treePtr->data = rootItem;


		treePtr->right = read_tree_aux((n - 1) / 2);
		return treePtr;
	}
	else {
		return nullptr;
	}
}

void binarytree::readTree(int n) {
	root = read_tree_aux(n);
}
