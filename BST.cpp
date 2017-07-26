#include<iostream>
#include"BST.h"
using namespace std;

BST::BST() {
	root = NULL;
}

BST::~BST() {

}

void BST::insertNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;

	insert(root, newNode);
	// increments the size of the BST, a private data member in "BST.h"
	// Note: If you decide to write a "delete" function yourself, remember
	// to decrement the size with "size--" each time you remove a node!
	size++;
}

void BST::insert(Node *& root, Node *& newNode) {
	// insert new node in BST by case...

	// if tree is empty
	if (root == NULL) {
		root = newNode;
	}

	// if tree is not empty, we have two cases:
	// 1. if the data to be inserted is less than the value of root,
	// we need to insert it in the left subtree of root 
	// 2. if the data to be inserted is greater than the value of root,
	// we need to insert it in the right subtree of root

	else if (newNode->data <= root->data) {
		insert(root->left, newNode);
	}
	else {
		insert(root->right, newNode);
	}
}

void BST::remove(int data) {

}

void BST::search(int data) {
	Node* temp = root;
	searchNode(temp, data);
}

void BST::searchNode(Node* temp, int data) {
	if (root == NULL) {
		cout << endl << "List is empty. No items to match." << endl << endl;
		return;
	}

	if (temp->left != NULL) {
		searchNode(temp->left, data);
	}

	if (temp->data == data) {
		cout << endl << "Search Operation: Node with value " << data << " found." << endl;
		return;
	}

	if (temp->right != NULL) {
		searchNode(temp->right, data);
	}
}

void BST::print() {
	Node* temp = root;
	cout << endl;
	cout << endl << "Printing data in BST..." << endl;
	DisplayInOrder(temp);
}

void BST::DisplayInOrder(Node* temp) {
	if (root == NULL) {
		cout << endl << "List is empty. Nothing to display." << endl << endl;
		return;
	}

	if (temp->left != NULL) {
		DisplayInOrder(temp->left);
	}
	
	cout << temp->data << endl;
	
	if (temp->right != NULL) {
		DisplayInOrder(temp->right);
	}
}

void BST::printSize() {
	cout << endl << "Size of BST is " << size << " nodes." << endl;
}



