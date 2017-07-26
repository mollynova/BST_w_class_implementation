#include<iostream>
#include "BST.h"
using namespace std;

int main() {
	BST* bst = new BST();
	// It's generally considered good practice to avoid global variables when using classes so I made a function
	// in BST.cpp called insertNode(int data), to which 'main' can pass the int to be inserted
	// into the tree without needing to know the address of the root. 
	//
	// In "BST.cpp", all insertNode(int data) does is declare a temporary pointer of type Node, which 
	// it sets equal to 'root.' It then passes that temp pointer, and the data to be inserted,
	// to another "BST.cpp" function called insert(Node* temp, int data), which does the actual
	// inserting. 
	//
	// We do this because you need to pass the address of 'root' to the insert function in order to
	// traverse the tree, but you cannot access 'root' from main.cpp without making 'root' a global
	// variable. However, from "BST.cpp" we can directly access 'root' because we have declared 
	// 'Node* root' to be a private data member of our bst in "BST.h," so it is within the scope 
	// of "BST.cpp".
	// 

	bst->print();

	bst->insertNode(10);
	bst->insertNode(15);
	bst->insertNode(12);
	bst->insertNode(8);
	bst->insertNode(2);
	bst->insertNode(1);

	bst->search(2);
	bst->search(3);

	bst->printSize();

	bst->print();
	
	// the "getchar()"s are just there to pause the system so you can see what is being output
	// hit any key twice to continue..
	getchar();
	getchar();
	
	// note: I have not written the destructor for bst yet, which control will pass to when the
	// next line runs, so feel free to write it yourself :) the program will still work w/o it so far
	// although this is technically a memory leak currently!
	delete bst;
	return 0;
}
