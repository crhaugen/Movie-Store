// ------------------------------------- Borrow.h -------------------------- 
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


class Borrow : public Transaction
{
public:
	//------------------------ Default constructor -------------------------------
	// Preconditions:   None
	// Postconditions: - Borrow object created
	Borrow();


	//------------------------------setData-----------------------------------
	// Preconditions: show object
	// Postconditions:  - information about the transaction has been set
	virtual bool setData(Customer *customer, char media, Movie *item);

	void display() const;

	//------------------------------Destructor-----------------------------------
	// Preconditions: movie object
	// Postconditions:  - Borrow object is gone
	~Borrow();
};