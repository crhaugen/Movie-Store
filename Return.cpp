// ------------------------------------- Return.cpp -------------------------- 
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

#include "Return.h"

//------------------------ Default constructor -------------------------------
// Preconditions:   None
// Postconditions: - Return object created
Return::Return()
{
	transactionType = "Return";
}


//------------------------------setData-----------------------------------
// Preconditions: Return object
// Postconditions:  - information about the transaction has been set
bool Return::setData(Customer *customer, char media, Movie *item)
{
	if (customer->isTransactionValid(this->transactionType, item))
	{
		this->mediaType = media;
		this->movieType = item;

		return item->giveBack();
	}

	return false;
}

void Return::display() const
{
	cout << mediaType << ": ";
	movieType->display();
	cout << " " << transactionType << endl;
}

//------------------------------Destructor-----------------------------------
// Preconditions: movie object
// Postconditions:  - Return object is gone
Return::~Return()
{

}