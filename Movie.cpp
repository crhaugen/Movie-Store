// ------------------------------------- Movie.h -------------------------- 
// Chyanne Haugen (crhaugen@uw.edu) CSS 343 A
// Creation Date: 3/5/19 
// Date of Last Modification: 
// ----------------------------------------------------------------------------
// Purpose - Movie class is a base class with virtual functions 
//       
//			 Feature:
//				- Overloaded operations: <,>, =, ==
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
#include "Movie.h"

//------------------------ Default constructor -------------------------------
// Preconditions:   None
// Postconditions: - Moive object created
Movie::Movie()
{
	title = " ";
	director = " ";
	year = 0;
	currentStock = 0;
}

//------------------------ getTitle ------------------------------------
// Preconditions:   None
// Postconditions: - title is returned
string Movie::getTitle() const
{
	return title;
}

//------------------------ getDirector ------------------------------------
// Preconditions:   None
// Postconditions: - director is returned
string Movie::getDirector() const
{
	return director;
}

//------------------------ getDirector ------------------------------------
// Preconditions:   None
// Postconditions: - Year is returned
int Movie::getYear() const
{
	return year;
}

//------------------------ getCurrentStock ------------------------------------
// Preconditions:   None
// Postconditions: - current stock is returned
int Movie::getCurrentStock() const
{
	return currentStock;
}

//------------------------ getMaxStock ------------------------------------
// Preconditions:   None
// Postconditions: - max stock is returned
int Movie::getMaxStock() const
{
	return maxStock;
}

//------------------------ increaseStockLevel ------------------------------------
// Preconditions:   None
// Postconditions: - current stock and max stock is updated
void Movie::increaseStockLevel(int newStock)
{
	maxStock += newStock;
	currentStock += newStock;
}

//------------------------ borrow --------------------------------------
// Preconditions:   object of movie type
// Postconditions: - current stock decreased by 1 
void Movie::borrow()
{
	//can't let user borrow if no stock available
	if (currentStock <= 0)
	{
		cout << "None to borrow" << endl;
		return;
	}

	currentStock--;
}

//------------------------ giveBack --------------------------------------
// Preconditions:   object of movie type
// Postconditions: - current stock increased by 1 
void Movie::giveBack()
{
	//if at max amount of stock user can't give anything back
	if (currentStock == maxStock)
	{
		cout << "Movie stock is at max" << endl;
		return;
	}

	currentStock++;
}

//------------------------------Destructor-----------------------------------
// Preconditions: movie object
// Postconditions:  - movie object is gone
 Movie::~Movie()
 {

 }