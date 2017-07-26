#pragma once

class BST {
private:
	struct Node {
		int data;
		Node* left = NULL;
		Node* right = NULL;
	};
	Node* root;
	int size = 0;

public:
	BST();
	~BST();
	Node* getRoot() { return root; }
	void printSize();
	void insertNode(int data);
	void insert(Node *& root, Node *& newBode);
	void remove(int data);
	void search(int data);
	void searchNode(Node* temp, int data);
	void print();
	void DisplayInOrder(Node* root);
};