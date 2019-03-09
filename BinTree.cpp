// ------------------------------------- bintree.cpp -------------------------- 
// Chyanne Haugen (crhaugen@uw.edu) CSS 343 A
// Creation Date: 1/17/19 
// Date of Last Modification: 2/2/19
// ----------------------------------------------------------------------------
// Purpose - bintree class allows a Binary Search tree to be represented 
//              in memory.
//			 Feature:
//				- Memory allocation and deallocation is handed by the class
//				- The following operation: '=', '==', '!=' 
//				can be preformed on any binary search trees
//
// ----------------------------------------------------------------------------
// Notes:
//		-All function in this class are for a Binary Search Tree. 
//          Except getHeight, getHeightHelper, and findNode which will 
//          work for binary trees.
//      
// Assumptions:
//		-Node and nodedata has memory that has been allocated and need 
//          to be freed 
// ---------------------------------------------------------------------------- 

#include "stdafx.h"

#include "bintree.h" 
#include <iostream>
#include <algorithm> //for using 'max'

//------------------------ Default constructor -------------------------------
// Preconditions:   None
// Postconditions: - root points to nullptr
BinTree::BinTree()
{
	root = nullptr;
}


//----------------------------------makeEmpty---------------------------------
//Calls makeEmptyHelper to clean a tree and free all memory.
// Preconditions: root points to null or node(s).
// Postconditions:  - root points to null. 
//  -calls helper function makeEmptyHelper() to preform the deletions
void BinTree::makeEmpty()
{
	makeEmptyHelper(this->root);
}

//-----------------------------makeEmptyHelper---------------------------------
// Private function to clean a tree and free all memory.
// Preconditions:  - root points to null or node(s).
// Postconditions:  - root points to null. 
//  -Assumption: Node and Nodedata have been allocated and need to be freed
void BinTree::makeEmptyHelper(Node *&root)
{
	if (root != nullptr)
	{
		makeEmptyHelper(root->left);
		makeEmptyHelper(root->right);
		//deallocating data
		delete root->data;
		delete root;
	}

	//pointing root to nullptr
	root = nullptr;
}


//--------------------------------insert---------------------------------
// -Function calls insertHelper function to preform the insertion.
// Preconditions: root points to null or node(s).
// Postconditions:  -Either true or false will be return. Either node has 
//  been inserted and memory has been allocated or if nodedata already 
//  in tree, node will not be inserted and no memory will be allocated.
bool BinTree::insert(Movie* item)
{
	return insertHelper(this->root, item);
}

//-----------------------------insertHelper---------------------------------
// Private function to insert a node into the tree
// Preconditions: root points to null or node(s).
// Postconditions:  -Either true or false will be return. Either node has 
//  been inserted and memory has been allocated or if nodedata already 
//  in tree, node will not be inserted and no memory will be allocated.
// - Assumption: movie will be deallocated by user.
bool BinTree::insertHelper(Node *&root, Movie *item)
{
	if (root == nullptr)
	{
		//setting root to new Node and pointing
		//left and right to nullptr.
		root = new Node;
		root->data = item;
		root->left = nullptr;
		root->right = nullptr;

		return true;
	}
	else if (*root->data == *item)
	{
		return false; //if data already in tree return false.
	}
	else if (*root->data > *item)
	{
		insertHelper(root->left, item);
	}
	else
	{
		insertHelper(root->right, item);
	}
}


//------------------------------isEmpty----------------------------------------
// Preconditions:  A bintree object.
// Postconditions:  - true or false has been return depending on what root
//  points to (null or node(s)).
bool BinTree::isEmpty() const
{
	return this->root == nullptr;
}


//--------------------------------retrieve-------------------------------------
// Preconditions: root points to null or node(s), searchItem contains data
//  to be search for.
// Postconditions:  -Either true or false will be return. If item is found
//  item will be in foundItem for user's use. 
bool BinTree::retrieve(const Movie &searchItem, Movie *&foundItem) const
{
	Node *tempPtr = this->root; //set temp pointer to root for traversal

								//going through tree look for item if tempPtr becomes null
								//item is not in tree
	while (tempPtr != nullptr)
	{
		//Found it! set foundItem to item and return true
		if (*tempPtr->data == searchItem)
		{
			foundItem = tempPtr->data;
			return true;
		}
		else if (*tempPtr->data < searchItem)
		{
			tempPtr = tempPtr->right;
		}
		else
		{
			tempPtr = tempPtr->left;
		}
	}

	return false;
}


//------------------------------operator<<-----------------------------------
//Calls inorderHelper to print the inorder travsal of the tree
// Preconditions: root points to null or node(s)
// Postconditions: prints out inorder nodes in the tree
// -Assumption: -This function does "endl" after printing, so user doesn't
//  have to. 
ostream& operator<<(ostream& output, const BinTree& tree)
{
	tree.inorderHelper(output, tree.root);
	output << endl; //print endl after whole tree has been printed out
	return output;
}

//------------------------------inorderHelper-------------------------------
//Private function to print the inorder travsal of the tree
// Preconditions: root points to null or node(s)
// Postconditions: prints out inorder nodes in the tree
void BinTree::inorderHelper(ostream& output, Node *current) const
{
	if (current != nullptr)
	{
		inorderHelper(output, current->left);
		current->data->display();
		cout << " ";
		inorderHelper(output, current->right);
	}
}

//------------------------------Destructor-----------------------------------
//Calls makeEmptyHelper to preform the deletions
// Preconditions:  root points to null or node(s)
// Postconditions:  - tree is deallocated, all memory is freed 
BinTree::~BinTree()
{
	makeEmptyHelper(this->root);
}