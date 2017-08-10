#ifndef TREE_H
#define TREE_H

#include <string>
#include <iostream>
using namespace std;

class Tree {
private:
	struct Node {
		string name;
		string phone;
		Node *left;
		Node *right;
	};
	Node *root;
	void Tree::insert(Node *&r, Node *&n);
	string find(Node *&r, string n);
	void clear(Node *&r);
	int remove(Node *&r, string n);
	void print(Node *r);

public:
	Tree();
	~Tree();
	bool isFull();
	bool isEmpty();
	int insert(string n, string p);
	string find(string n);
	void clear();
	int remove(string n);
	void print();
};
Tree::Tree() {
	root = nullptr;
};

Tree::~Tree() {
	clear();
};

bool Tree::isFull() {
	return false;
};
bool Tree::isEmpty() {
	if (root == nullptr) {
		return true;
	}
	return false;
};

int Tree::insert(string n, string p) {
	Node *newNode = new Node;
	newNode->name = n;
	newNode->phone = p;
	newNode->left = nullptr;
	newNode->right = nullptr;

	// Insert the node
	insert(root, newNode);
	return 0;
};

string Tree::find(string name) {
	return find(root, name);
};

void Tree::clear() {
	clear(root);
};

int Tree::remove(string name) {
	return remove(root, name);
};

void Tree::print() {
	print(root);
};

//private functions
void Tree::insert(Node *&nodePtr, Node *&newNode) {
	if (nodePtr == nullptr) {
		nodePtr = newNode;				//insert the node
		return;
	}
	else if (newNode->name < nodePtr->name) {
		insert(nodePtr->left, newNode);  //search the left branch
	}
	else {
		insert(nodePtr->right, newNode); //search the right branch
	}
};

string Tree::find(Node *&r, string name) {
	Node *nodePtr = r;
	if (isEmpty()) {
		return "LIST IS EMPTY";
	}
	else {
		while (nodePtr != nullptr) {
			if (nodePtr->name == name) {
				return nodePtr->phone;
			}
			else if (name < nodePtr->name) {
				nodePtr = nodePtr->left;
			}
			else {
				nodePtr = nodePtr->right;
			}
		}
	}
	return "NOT FOUND";
};

void Tree::clear(Node *&nodePtr) {
	if (!isEmpty()) {
		if (nodePtr->left) {
			clear(nodePtr->left);
		}
		if (nodePtr->right) {
			clear(nodePtr->right);
		}
		delete nodePtr;
	}
};

int Tree::remove(Node* &r, string n) {
	Node *tempNodePtr = r, *nodePtr = nullptr;

	while (tempNodePtr != nullptr) {
		if (tempNodePtr->name == n) {
			break;
		}
		nodePtr = tempNodePtr;
		if (n < tempNodePtr->name) {
			tempNodePtr = tempNodePtr->left;
		} else {
			tempNodePtr = tempNodePtr->right;
		}
	}
	if (tempNodePtr == nullptr) {
		return -1;
	}
	if (tempNodePtr->left == nullptr && tempNodePtr->right == nullptr) {
		if (nodePtr == nullptr) {
			r = nullptr;
		} else {
			if (nodePtr->left == tempNodePtr) {
				nodePtr->left = nullptr;
			} else {
				nodePtr->right = nullptr;
			}
		}
		delete tempNodePtr;
	} else if (tempNodePtr->left != nullptr && tempNodePtr->right == nullptr) {
		if (nodePtr == nullptr) {
			r = tempNodePtr->left;
		}
		else {
			if (nodePtr->left == tempNodePtr) {
				nodePtr->left = tempNodePtr->left;
			} else {
				nodePtr->right = tempNodePtr->left;
			}
		}
		delete tempNodePtr;
	} else if (tempNodePtr->left == nullptr && tempNodePtr->right != nullptr) {
		if (nodePtr == nullptr) {
			r = tempNodePtr->right;
		}
		else {
			if (nodePtr->left == tempNodePtr) {
				nodePtr->left = tempNodePtr->right;
			} else {
				nodePtr->right = tempNodePtr->right;
			}
				
		}
		delete tempNodePtr;
	} else {
		Node* prevNode = tempNodePtr->right;
		while (prevNode->left != nullptr) {
			prevNode = prevNode->left;
		}
		string name = prevNode->name, phone = prevNode->phone;
		remove(r, prevNode->name);
		tempNodePtr->name = name;
		tempNodePtr->phone = phone;
	}
	return 0;
}

void Tree::print(Node *nodePtr) {
	if (isEmpty()) {
		cout << "The list is empty" << endl;
	} else {
		if (nodePtr->left) {
			print(nodePtr->left);
		}
		cout << nodePtr->name << " " << nodePtr->phone << "\t" << endl;
		if (nodePtr->right) {
			print(nodePtr->right);
		}
	}
};

#endif // ! TREE_H