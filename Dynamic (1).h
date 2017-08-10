#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <iostream>

using namespace std;

class Dynamic {
public:
	struct Node {
		int value;	// value in the node
		Node *next; // Pointer to the next node
	};

private:
	Node *head, *tail; // pointer to the stack top

public:
	Dynamic();
	~Dynamic();
	int push(int i);
	int enqueue(int i);
	int pop(int &i);
	int dequeue(int &i);
	void clear();
	int peek(int &i) const;
	bool isFull() const;
	bool isEmpty() const;
	int length() const;
	void print() const;
};

Dynamic::Dynamic() {
	tail = nullptr, head = nullptr;
};
Dynamic::~Dynamic() {
	Node *nodePtr = head, *nextNode = nullptr;
	while (nodePtr != nullptr) {  //deleting each node
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
};
int Dynamic::push(int i) {  //pushes the argument onto the stack.
	Node *newNode = nullptr;
	newNode = new Node;
	newNode->value = i;
	if (isEmpty()) {
		head = newNode;
		newNode->next = nullptr;
		return 0;
	}
	else {
		newNode->next = head;
		head = newNode;
		return 0;
	}
	return -1;
};
int Dynamic::enqueue(int i) {
	Node *newNode = new Node;
	newNode->value = i;
	newNode->next = nullptr;
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
		return 0;
	} else {
		tail->next = newNode;
		tail = newNode;
		return 0;
	}
	return -1;
};
int Dynamic::pop(int &i) {
	//pops the value at the top
	// of the stack off, and copies it into the variable 
	//passed as an argument
	Node *temp = nullptr;
	if (isEmpty()) {
		cout << "The stack is empty." << endl;
		return -1;
	} else {
		i = head->value;
		temp = head->next;
		delete head;
		head = temp;
		return 0;
	}
};
int Dynamic::dequeue(int &i) {
	Node *temp = nullptr;
	if (isEmpty()) {
		cout << "The queue is empty." << endl;
		return -1;
	}else {
		i = head->value;
		//Remove the front node and delete it
		temp = head;
		head = head->next;
		delete temp;
		return 0;
	}
};
void Dynamic::clear() {
	Node *nodePtr = head, *nextNode = nullptr;
	while (nodePtr != nullptr) {  //deleting each node
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
};
int Dynamic::peek(int &i) const {
	if (head != nullptr) {
		i = head->value;
		return 0;
	}
	return -1;
};
bool Dynamic::isFull() const {
	Node *nodePtr = new Node;
	if (nodePtr == nullptr) {
		return true;
	}
	else {
		delete[] nodePtr;
		return false;
	}
};
bool Dynamic::isEmpty() const {
	bool status;
	if (!head) {
		status = true;
	}
	else {
		status = false;
	}
	return status;
};
int Dynamic::length() const {
	Node *nodePtr = head;
	int count = 0;
	while (nodePtr != nullptr) {
		count++;
		nodePtr = nodePtr->next;
	}
	return count;
};
void Dynamic::print() const {
	Node *nodePtr = head;
	while (nodePtr != nullptr) {
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
};
#endif