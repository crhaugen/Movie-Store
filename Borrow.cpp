// ------------------------------------- Borrow.cpp -------------------------- 
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
#include "stdafx.h"
#include "Borrow.h"
#include "Customer.h"

//------------------------ Default constructor -------------------------------
// Preconditions:   None
// Postconditions: - Borrow object created
Borrow::Borrow()
{
	transactionType = "Borrow";
}



//------------------------------setData-----------------------------------
// Preconditions: Borrow object
// Postconditions:  - information about the transaction has been set
bool Borrow::setData(Customer *customer, char media, Movie *item)
{
	if (customer->isTransactionValid(this->transactionType, item))
	{
		this->mediaType = media;
		this->movieType = item;

		return item->borrow();
	}

	return false;
}

void Borrow::display() const
{
	cout << mediaType << ": ";
	movieType->display();
	cout << transactionType << endl;
}

//------------------------------Destructor-----------------------------------
// Preconditions: movie object
// Postconditions:  - Borrow object is gone
Borrow::~Borrow()
{

}