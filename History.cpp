// ------------------------------------- History.cpp -------------------------- 
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


#include "History.h"


//------------------------ Default constructor -------------------------------
// Preconditions:   None
// Postconditions: - History object created
History::History()
{
	transactionType = "History";
}


//------------------------------setData-----------------------------------
// Preconditions: history object
// Postconditions:  - information about the transaction has been set
bool History::setData(Customer *customer, char media, Movie *item)
{

}

//------------------------------Destructor-----------------------------------
// Preconditions: movie object
// Postconditions:  - history object is gone
History::~History()
{

}