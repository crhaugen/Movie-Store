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

Movie::Movie()
{
	title = " ";
	director = " ";
	year = 0;
	currentStock = 0;
}

string Movie::getTitle() const
{
	return title;
}

string Movie::getDirector() const
{
	return director;
}

int Movie::getYear() const
{
	return year;
}

int Movie::getCurrentStock() const
{
	return currentStock;
}

void Movie::borrow()
{
	if (currentStock <= 0)
	{
		cout << "None to borrow" << endl;
		return;
	}

	currentStock--;
}

void Movie::giveBack()
{
	if (currentStock == maxStock)
	{
		cout << "Movie stock is at max" << endl;
		return;
	}

	currentStock++;
}

 Movie::~Movie()
 {

 }