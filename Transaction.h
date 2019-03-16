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


using namespace std;

class Transaction
{
protected:
	string transactionType;

public:

	//------------------------ Default constructor -------------------------------
	// Preconditions:   None
	// Postconditions: - Transaction object created
	Transaction();

	virtual void doTransaction() = 0;
	virtual void setData() = 0;

	//------------------------------makeTransactionType-----------------------------------
	// Preconditions: type of transaction to be made
	// Postconditions:  - transaction of said type is made and returned
	static Transaction *makeTransactionType(char type);

	//------------------------------Destructor-----------------------------------
	// Preconditions: transaction object
	// Postconditions:  - transaction object is gone
	~Transaction();
};