// ------------------------------------- Show.cpp -------------------------- 
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

#include "Show.h"

//------------------------ Default constructor -------------------------------
// Preconditions:   None
// Postconditions: - Show object created
Show::Show()
{
	transactionType = "Show";
}

void Show::doTransaction()
{

}

//------------------------------setData-----------------------------------
// Preconditions: show object
// Postconditions:  - information about the transaction has been set
void Show::setData(Customer *customer, string media, Movie *item)
{

}

//------------------------------Destructor-----------------------------------
// Preconditions: movie object
// Postconditions:  - show object is gone
Show::~Show()
{

}