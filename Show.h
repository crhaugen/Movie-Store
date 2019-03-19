// ------------------------------------- Show.h -------------------------- 
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

class Show : public Transaction
{

public:
	//------------------------ Default constructor -------------------------------
	// Preconditions:   None
	// Postconditions: - Show object created
	Show();

	virtual void doTransaction();

	//------------------------------setData-----------------------------------
	// Preconditions: show object
	// Postconditions:  - information about the transaction has been set
	virtual void setData(Customer *customer, string media, Movie *item);



	//------------------------------Destructor-----------------------------------
	// Preconditions: movie object
	// Postconditions:  - history object is gone
	~Show();
};