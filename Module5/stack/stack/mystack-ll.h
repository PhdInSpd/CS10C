#pragma once
#include <iostream>
#include <cassert>

class mystack {
public:
	void pop();
	char top();
	void push(char ch);
	bool isEmpty();
	mystack();
	~mystack();
private:
	struct node {
		char data;
		node* next;
	};
	node* list;
};


mystack::mystack() {
	list = new node;
	list->next = NULL;
}


void mystack::pop() {
	assert(!isEmpty());
	node* temp = list->next;
	list->next = temp->next;
	delete temp;
}


char mystack::top() {
	if (!isEmpty()) {
		return list->next->data;
	}

	return '\0';
}



void mystack::push(char ch) {
	node* temp = new node;
	temp->data = ch;
	temp->next = list->next;
	list->next = temp;
}


bool mystack::isEmpty() {
	return (list->next == NULL);
}



mystack::~mystack() {
	node* temp;

	do {
		temp = list;
		list = list->next;
		delete temp;
	} while (list != NULL);
}

