// ------------------------------------- Store.h -------------------------- 
// Chyanne Haugen (crhaugen@uw.edu) CSS 343 A
// Creation Date: 3/5/19 
// Date of Last Modification: 
// ----------------------------------------------------------------------------
// Purpose - Store class runs all the business logic for the movie store.
//       
//			 Feature:
//				- Reads from files.
//				- Has 3 binary search tree of the different movies types
//					and a hashtable from customers
//
// ----------------------------------------------------------------------------
// Notes:
//		-
//		-
//      
// Assumptions:
//		-
//		-
//
// ----------------------------------------------------------------------------




#pragma once

#include "stdafx.h"

#include "Drama.h"
#include "Comedy.h"
#include "Classics.h"
#include "BinTree.h"
#include "Transaction.h"
#include <iostream>

using namespace std;

class Store
{
private:
	BinTree dramaTree;
	BinTree comedyTree;
	BinTree classicsTree;

	bool validCustomer(int id);

public:

	Store();

	void buildMovies(istream& infile);
	void readTransaction(istream& infile);


};