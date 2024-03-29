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
#include "Movie.h"
//#include "Customer.h"

using namespace std;

class Customer; //can't include customer.h

class Transaction
{
protected:
	string transactionType;
	string mediaType;
	Movie *movieType;

public:

	//------------------------ Default constructor -------------------------------
	// Preconditions:   None
	// Postconditions: - Transaction object created
	Transaction();
	string getTransactionType() const;
	Movie* getMovie() const;

	virtual void display() const = 0;
	virtual bool setData(Customer *customer, char media, Movie *item) = 0;


	//------------------------------Destructor-----------------------------------
	// Preconditions: transaction object
	// Postconditions:  - transaction object is gone
	virtual ~Transaction();
};