// ------------------------------------- History.h -------------------------- 
// Chyanne Haugen (crhaugen@uw.edu) CSS 343 A
// Creation Date: 3/13/19 
// Date of Last Modification: 
// ----------------------------------------------------------------------------
// Purpose - Transaction class is a base class with virtual functions 
//       
//			 Feature:
//				- 
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

#include "Transaction.h"
class Customer;
class History : public Transaction
{
public:
	//------------------------ Default constructor -------------------------------
	// Preconditions:   None
	// Postconditions: - History object created
	History();


	virtual void display() const;
	virtual bool setData(Customer *customer, char media, Movie *item);

	//------------------------------Destructor-----------------------------------
	// Preconditions: movie object
	// Postconditions:  - history object is gone
	~History();
};