#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BSTNode
{
private:
	struct Node
	{
		char letter; //Letter in the alphabet
		string morse; //Morse code of letter
		Node* right; //pointer to right child node
		Node* left; //pointer to left child node
	};

	Node* root; //Pointer to the root node
	int nodeCounter; //Total number of nodes in the tree

	//Private Member Functions

	void insert(Node*&nodePtr, Node*&newNode);
	void destroySubTree(Node* nodePtr);
	void deleteNode(char, Node*&nodePtr);
	void makeDeletion(Node*&nodePtr);
	void displayInOrder(Node* nodePtr) const;

public:
	BSTNode(); //Constructor

	~BSTNode() //Destructor
	{
		destroySubTree(root);
	}

	//Binary Tree operations
	void insertNode(char c, string str);
	bool searchNode(char c);
	void remove(char c);
	void displayInOrder() const
	{
		displayInOrder(root);
	}
	void findNode(char c);
	void convertString();
};

#endif