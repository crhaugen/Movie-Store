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
	stock = 0;
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

int Movie::getStock() const
{
	return stock;
}

 Movie::~Movie()
 {

 }