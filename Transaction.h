// ------------------------------------- Transaction.h -------------------------- 
// Chyanne Haugen (crhaugen@uw.edu) CSS 343 A
// Creation Date: 3/13/19 
// Date of Last Modification: 
// ----------------------------------------------------------------------------
// Purpose - Transaction class is a base class with virtual functions 
//       
//			 Feature:
//				- factor method will allow the creation of different types
//			of transactions
//				- 
//
// ----------------------------------------------------------------------------
// Notes:
//		-
//		-
//
//		-
//      
// Assumptions:
//		-
//		-
//
// ----------------------------------------------------------------------------

#pragma once

#include "stdafx.h"
#include <iostream>
#include "Show.h"
#include "Show.h"
#include "Borrow.h"
#include "Return.h"
#include "History.h"
#include "Movie.h"

using namespace std;

class Transaction
{
protected:
	string transactionType;
	string mediaType;

public:

	//------------------------ Default constructor -------------------------------
	// Preconditions:   None
	// Postconditions: - Transaction object created
	Transaction();
	string getTransactionType();

	virtual void doTransaction() = 0;
	virtual void setData(Customer *customer, string media, Movie *item) = 0;

	//------------------------------makeTransactionType-----------------------------------
	// Preconditions: type of transaction to be made
	// Postconditions:  - transaction of said type is made and returned
	static Transaction* makeTransactionType(char type);

	//------------------------------Destructor-----------------------------------
	// Preconditions: transaction object
	// Postconditions:  - transaction object is gone
	virtual ~Transaction();
};