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

class History : public Transaction
{
	//------------------------ Default constructor -------------------------------
	// Preconditions:   None
	// Postconditions: - History object created
	History();

	virtual void doTransaction();


	virtual void setData();

	//------------------------------Destructor-----------------------------------
	// Preconditions: movie object
	// Postconditions:  - history object is gone
	~History();
};