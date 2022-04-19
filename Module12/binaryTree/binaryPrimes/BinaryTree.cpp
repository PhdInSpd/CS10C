/*
student   : Jose Alfredo Martinez
instructor : Dave Harden
class : CS 10C
	date : April 13, 2022
	file name : binarytree.cpp
*/
#include <iostream>
#include "binarytree.h"
using namespace std;






binarytree::binarytree() {
	root = nullptr;
}






binarytree::binarytree(const binarytree& copyMe) {
	copy( copyMe.root, root );
	mSize = copyMe.mSize;
}






binarytree& binarytree::operator=( const binarytree& copyMe) {
	if (this != &copyMe) {
		clear(root);
		copy(copyMe.root, root);
		mSize = copyMe.mSize;
	}
	return *this;
}






binarytree::~binarytree() {
	clear( root );
	mSize = 0;
}






void binarytree::print() const {
	print_aux(root);
}






void binarytree::insert(int item) {
	insert_aux(root, item);
	mSize++;
}






binarytree::size_type binarytree::size() const {
	return mSize;
	//return size_aux(root);
}






int binarytree::find(int target, bool& found) const {
	return find_aux(root, target, found);
}






void binarytree::del(int target, bool& found) {
	del_aux(root, target, found);
	if (found) {
		mSize--;
	}
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






binarytree::size_type binarytree::numPrimesAux(const treenode* root) {
	if (root == nullptr) {
		return 0;
	}
	else {
		size_type foundRootPrime = 0;
		if (isPrime(root->data)) {
			foundRootPrime++;
		}

		return numPrimesAux(root->left)
			+ numPrimesAux(root->right)
			+ foundRootPrime;
	}
}






binarytree::size_type binarytree::numPrimes() {
	return numPrimesAux(root);
}






LL<int> binarytree::toLL() {
	LL<int> copy;
	toLLAux( root, copy);
	return copy;
}






void binarytree::toLLAux(const treenode* root, LL<int> & copyMe) {
	if (root == nullptr) {
		return ;
	}
	else {
		// reverse inorder visit to build Linked List copy
		toLLAux(root->right, copyMe);
		copyMe.push_front(root->data);
		toLLAux(root->left, copyMe);

	}
}






// todo - trace
void binarytree::copy( const treenode* srcRoot, treenode*& dstRoot) {
	if (srcRoot == nullptr) {
		return;
	}
	else {
		dstRoot = new treenode();
		dstRoot->data = srcRoot->data;
		copy( srcRoot->left, dstRoot->left );
		copy(srcRoot->right, dstRoot->right);		
	}
}






void binarytree::clear(treenode*& dstRoot) {
	if (dstRoot == nullptr) {
		return;
	}
	else {
		clear(dstRoot->left);
		clear(dstRoot->right);
		delete dstRoot;
		dstRoot = nullptr;
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






bool binarytree::isPrime(int canidate) {
	bool prime = true;
	double canidatePeak = canidate;
	if (canidate <= 1) {
		prime = false;
		return prime;
	}
	canidatePeak = sqrt(canidate);
	
	for (size_t i = 2; i <= canidatePeak; i++) {
		if (canidate % i == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}