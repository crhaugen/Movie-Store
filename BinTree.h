// ------------------------------------- bintree.cpp -------------------------- 
// Chyanne Haugen (crhaugen@uw.edu) CSS 343 A
// Creation Date: 1/17/19 
// Date of Last Modification: 3/9/19
// ----------------------------------------------------------------------------
// Purpose - bintree class allows a Binary Search tree to be represented 
//              in memory.
//			 Feature:
//				- Memory allocation and deallocation is handed by the class
//
// ----------------------------------------------------------------------------
// Notes:
//		-This Binary Search tree does not have all the method a normal BST 
//		only basic functions are being use.
//      
// Assumptions:
//		-This binary search tree will only be used for data of type Movie
// ---------------------------------------------------------------------------- 

#pragma once

#include "stdafx.h"

#include "Movie.h"
#include <iostream>

using namespace std;

class BinTree
{
private:

	struct Node
	{
		Movie* data;	// pointer to data object
		Node* left; // left subtree pointer
		Node* right; // right subtree pointer
	};

	Node* root;	// root of the tree


	//-----------------------------makeEmptyHelper---------------------------------
	// Private function to clean a tree and free all memory.
	// Preconditions:  - root points to null or node(s).
	// Postconditions:  - root points to null. 
	//  -Assumption: Node and Nodedata have been allocated and need to be freed
	void makeEmptyHelper(Node *&root);

	//------------------------------inorderHelper-------------------------------
	//Private function to print the inorder travsal of the tree
	// Preconditions: root points to null or node(s)
	// Postconditions: prints out inorder nodes in the tree
	void inorderHelper(ostream& output, Node*) const;


	//-----------------------------insertHelper---------------------------------
	// Private function to insert a node into the tree
	// Preconditions: root points to null or node(s).
	// Postconditions:  -Either true or false will be return. Either node has 
	//  been inserted and memory has been allocated or if nodedata already 
	//  in tree, node will not be inserted and no memory will be allocated.
	// - Assumption: Nodedata will be deallocated by user.
	bool insertHelper(Node *&root, Movie* item);

	//-----------------------------insertHelper---------------------------------
	// Private function to find a node into the tree
	// Preconditions: root points to null or node(s).
	// Postconditions:  -Either true or false will be return. Either node has 
	//  been found or not
	bool findHelper(Node *&root, Movie *item);


public:

	//------------------------ Default constructor -------------------------------
	// Preconditions:   None
	// Postconditions: - root points to nullptr
	BinTree();

	//------------------------------Destructor-----------------------------------
	//Calls makeEmptyHelper to preform the deletions
	// Preconditions:  root points to null or node(s)
	// Postconditions:  - tree is deallocated, all memory is freed 
	~BinTree();

	//------------------------------isEmpty----------------------------------------
	// Preconditions:  A bintree object.
	// Postconditions:  - true or false has been return depending on what root
	//  points to (null or node(s)).
	bool isEmpty() const; // true if tree is empty, otherwise false

	//----------------------------------makeEmpty---------------------------------
	//Calls makeEmptyHelper to clean a tree and free all memory.
	// Preconditions: root points to null or node(s).
	// Postconditions:  - root points to null. 
	//  -calls helper function makeEmptyHelper() to preform the deletions
	void makeEmpty();


	//--------------------------------insert---------------------------------
	// -Function calls insertHelper function to preform the insertion.
	// Preconditions: root points to null or node(s).
	// Postconditions:  -Either true or false will be return. Either node has 
	//  been inserted and memory has been allocated or if nodedata already 
	//  in tree, node will not be inserted and no memory will be allocated.
	bool insert(Movie* item);

	//--------------------------------retrieve-------------------------------------
	// Preconditions: root points to null or node(s), searchItem contains data
	//  to be search for.
	// Postconditions:  -Either true or false will be return. If item is found
	//  item will be in foundItem for user's use. 
	bool retrieve(const Movie &searchItem, Movie *&foundItem) const;

	//--------------------------------retrieveByTitle-----------------------------
	// Preconditions: root points to null or node(s), searchItem contains data
	//  to be search for.
	// Postconditions:  -if a movie of same title in already in tree updates
	//	stock of that movie of both movies to be total, but they will be 
	//	kept separate.
	int retrieveByTitle(string title, int stock) const;

	//--------------------------------find---------------------------------
	// -Function calls findHelper function to find object in tree.
	// Preconditions: root points to null or node(s).
	// Postconditions:  -Either true or false will be return. Either node has 
	//  been found or not
	bool find(Movie* item);


	//------------------------------operator<<-----------------------------------
	//Calls inorderHelper to print the inorder travsal of the tree
	// Preconditions: root points to null or node(s)
	// Postconditions: prints out inorder nodes in the tree
	// -Assumption: -This function does "endl" after printing, so user doesn't
	//  have to. 
	friend ostream & operator<<(ostream &, const BinTree &);

	
	

};