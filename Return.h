// ------------------------------------- Return.h -------------------------- 
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

class Return : public Transaction
{

public:
	//------------------------ Default constructor -------------------------------
	// Preconditions:   None
	// Postconditions: - Return object created
	Return();

	virtual void doTransaction();

	//------------------------------setData-----------------------------------
	// Preconditions: Return object
	// Postconditions:  - information about the transaction has been set
	virtual void setData();

	//------------------------------Destructor-----------------------------------
	// Preconditions: movie object
	// Postconditions:  - Return object is gone
	void display() const;

	~Return();
};