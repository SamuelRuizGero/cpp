#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include <string>
#include <iostream>
using namespace std;

class DynamicList {
public:
	struct ListNode {
		int value;
		ListNode *next;
	};

	ListNode *head;

	DynamicList();
	~DynamicList();
	void clear();
	int insert(int i);
	int append(int i);
	int remove(int i);
	int peek(int &i);
	bool isFull();
	bool isEmpty();
	int getLength();
	int find(int i);
	void print();
};

DynamicList::DynamicList() {
	head = nullptr;
}

DynamicList::~DynamicList() {
	ListNode *nextNode;
	while (head != nullptr) {
		nextNode = head;
		delete nextNode;
		head = head->next;
	}
}

void DynamicList::clear() {
	ListNode *nextNode;
	while (head != nullptr) {
		nextNode = head;
		head = head->next;
		delete nextNode;
	}
}

bool DynamicList::isFull() {
	ListNode *nodePtr = new ListNode;
	if (nodePtr == nullptr) {
		return true;
	} else {
		delete[] nodePtr;
		return false;
	}
}

bool DynamicList::isEmpty() {
	if (head == nullptr) {
		return true;
	}
	return false;
}

int DynamicList::getLength() {
	ListNode *nodePtr = head;
	int count = 0;
	while (nodePtr != nullptr) {
		count++;
		nodePtr = nodePtr->next;
	}
	return count;
}

int DynamicList::insert(int i) {
	ListNode *newNode, *nodePtr, *previousNode;
	newNode = new ListNode;
	newNode->value = i;
	newNode->next = nullptr;
	if (head == nullptr) {						// If there are no nodes in the list made newNode the first node
		head = newNode;
	}
	else {									// Otherwise, insert newNode at the end
		nodePtr = head;
		previousNode = nullptr;
		while (nodePtr != nullptr && nodePtr->value < i) {	// Skip all nodes whose value member is less than num.
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousNode == nullptr) { // If the new mode is to be the 1st in the list, insert it before all other nodes.
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
		return 0;
	}
	return -1;
}

int DynamicList::append(int i) {
	ListNode *newNode, *nodePtr;
	newNode = new ListNode;
	newNode->value = i;
	newNode->next = nullptr;
	if (head == nullptr) {					// If there are no nodes in the list made newNode the first node
		head = newNode;
		return 0;
	} else {									// Otherwise, insert newNode at the end
		nodePtr = head;
		while (nodePtr->next != nullptr) {	// Find th elast node in the list
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;			 // Insert newNode as the last node
		return 0;
	}
	return -1;
}

int DynamicList::remove(int i) {
	ListNode *nodePtr, *previousNode;
	if (head == nullptr) {
		return -1;
	}
	if (head->value == i) {
		nodePtr = head;
		head = head->next;
		delete nodePtr;
		return 0;
	}
	previousNode = head;
	while (previousNode->next != nullptr) {
		if (previousNode->next->value == i) {
			break;
		}
		previousNode = previousNode->next;
	}
	if (previousNode->next == nullptr) {
		return -1;
	}
	nodePtr = previousNode->next;
	previousNode->next = previousNode->next->next;
	delete nodePtr;
	return -1;
}

int DynamicList::peek(int &i) {
	if (head != nullptr) {
		i = head->value;
		return 0;
	}
	return -1;
}

int DynamicList::find(int i) {
	ListNode *nodePtr = head;
	int count = 0;
	while (nodePtr != nullptr) {
		if (nodePtr->value == i) {
			return count;
		}
		count++;
		nodePtr = nodePtr->next;
	}
	return 0;
}

void DynamicList::print() {
	ListNode *nodePtr = head;
	while (nodePtr != nullptr) {
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
}
#endif
