#ifndef DCLIST_H  
#define DCLIST_H 

#include <iostream>

using namespace std;

class DCList {
private:
	struct Node {
		char value;
		Node *next, *prev;
	};
	Node *head, *tail, *cur;
public:
	DCList();
	~DCList();
	void clear();
	int append(char c);
	int insert(char c);
	int remove(char c);
	int next(char &c);
	void print();
	void reverse();
	int length();
	bool isEmpty();
	bool isFull();
};
DCList::DCList() {
	head = nullptr, tail = nullptr, cur = head;
}
DCList::~DCList() {
	clear(); // destroys the linked list
}
void DCList::clear() {
	Node *nodePtr = head;
	if (isEmpty()) {
		cout << "The list is empty" << endl;
	}
	else {
		do {
			head = nodePtr->next;
			delete nodePtr;
			nodePtr = head;
		} while (nodePtr->next != tail->next);
		head = nullptr, tail = nullptr, cur = nullptr;
	}
}
int DCList::next(char &c) {
	if (isEmpty()) {
		cout << "The list is empty!" << endl;
		return -1;
	}
	else {
		cur = cur->next;
		c = cur->value;
		return 0;
	}
}
int DCList::append(char c) {
	Node *nodePtr = tail, *newNode = new Node;
	newNode->value = c;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
		cur = head;
		newNode->next = newNode;					//pointing to itself
		newNode->prev = newNode;					//pointing to itself
		return 0;
	}
	else {
		nodePtr->next = newNode;
		newNode->prev = nodePtr;
		newNode->next = head;						//pointing to the first node
		tail = newNode;
		head->prev = tail;
		return 0;
	}
	return -1;
}
int DCList::insert(char c) {
	Node *nodePtr = head, *prevNode = nullptr, *newNode = new Node;
	newNode->value = c;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
		cur = head;
		newNode->next = newNode;					//pointing to itself
		newNode->prev = newNode;					//pointing to itself
		return 0;
	}
	else {
		while (nodePtr->value < c && nodePtr != tail) {
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (prevNode == nullptr) {				//insert node at the beginning
			head = newNode;
			newNode->next = nodePtr;
			newNode->prev = tail;
			nodePtr->prev = newNode;
			tail->next = newNode;

		}
		else if (nodePtr->next == head) {		//insert node at the end
			nodePtr->next = newNode;
			newNode->prev = nodePtr;
			newNode->next = head;						//pointing to the first node
			tail = newNode;
			head->prev = tail;
		}
		else {										//insert node in the middle
			prevNode->next = newNode;
			newNode->prev = nodePtr->prev;			//nodePtr->prev == prevNode?
			newNode->next = nodePtr;
			nodePtr->prev = newNode;
		}
		return 0;
	}
	return -1;
}
int DCList::remove(char c) {
	Node *nodePtr = head, *prevNode = nullptr, *newNode = new Node;
	newNode->value = c;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (isEmpty()) {
		cout << "The list is empty!";
		return 0;
	}
	else {
		while (nodePtr->value != c && nodePtr != tail) {
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (prevNode == nullptr && head == tail) {					//remove node from the beginning
			delete nodePtr;
			head = nullptr;
			tail = nullptr;
		}
		else if (nodePtr->prev == tail) {
			head = nodePtr->next;
			head->prev = nodePtr->prev;
			delete nodePtr;
		}
		else if (nodePtr->next == head) {		//remove node form the back
			tail = prevNode;
			prevNode->next = tail->next;
			head->prev = tail->prev;
			delete nodePtr;
		}
		else {									//remove node form the middle
			prevNode->next = nodePtr->next;
			nodePtr->next->prev = prevNode;
			delete nodePtr;
		}
		return 0;
	}
	return -1;
}
void DCList::print() {
	Node *nodePtr = head;
	if (isEmpty()) {
		cout << "The list is empty!" << endl;
	}
	else {
		do {
			cout << nodePtr->value << " ";
			nodePtr = nodePtr->next;
		} while (nodePtr != tail->next);
		cout << endl;
	}
}
int DCList::length() {
	Node *nodePtr = head;
	int count = 0;
	if (isEmpty()) {
		cout << "The list is empty!" << endl;
		return 0;
	}
	else {
		do {
			nodePtr = nodePtr->next;
			count++;
		} while (nodePtr != tail->next);
		return count;
	}
	return -1;
}
void DCList::reverse() {
	Node *nodePtr = tail;
	if (isEmpty()) {
		cout << "The list is empty!" << endl;
	}
	else {
		do {
			cout << nodePtr->value << " ";
			nodePtr = nodePtr->prev;
		} while (nodePtr != head->prev);
		cout << endl;
	}
}
bool DCList::isEmpty() {
	if (head == nullptr) {
		return true;
	}
	return false;
}
bool DCList::isFull() {
	Node *nodePtr = new Node;
	if (nodePtr == nullptr) {
		return true;
	}
	else {
		delete[] nodePtr;
		return false;
	}
}
#endif // !DCLIST_H 