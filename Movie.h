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
#pragma once
#include "stdafx.h"
#include <iostream>

#include <string>
using namespace std;

class Movie
{
protected: 
	string title;
	string director;
	int year;
	int currentStock;
	int maxStock;

public:
	//------------------------ Default constructor -------------------------------
	// Preconditions:   None
	// Postconditions: - Moive object created
	Movie();

	//------------------------ getTitle ------------------------------------
	// Preconditions:   None
	// Postconditions: - title is returned
	string getTitle() const;

	//------------------------ getDirector ------------------------------------
	// Preconditions:   None
	// Postconditions: - director is returned
	string getDirector() const;

	//------------------------ getYear ------------------------------------
	// Preconditions:   None
	// Postconditions: - Year is returned
	int getYear() const;

	//------------------------ getCurrentStock -----------------------------------
	// Preconditions:   None
	// Postconditions: - current stock is returned
	int getCurrentStock() const;

	//------------------------ getMaxStock ------------------------------------
	// Preconditions:   None
	// Postconditions: - max stock is returned
	int getMaxStock() const;

	//------------------------ increaseStockLevel --------------------------------
	// Preconditions:   None
	// Postconditions: - current stock and max stock is updated
	void increaseStockLevel(int newStock);

	//------------------------ borrow --------------------------------------
	// Preconditions:   object of movie type
	// Postconditions: - current stock decreased by 1 
	void borrow();

	//------------------------ giveBack --------------------------------------
	// Preconditions:   object of movie type
	// Postconditions: - current stock increased by 1 
	void giveBack();

	//------------------------ setData --------------------------------------
	// Preconditions:   stream object
	// Postconditions: - data from stream is set
	// Notes: virtual function used in other classes
	virtual bool setData(istream&) = 0;

	//------------------------ display --------------------------------------
	// Preconditions:   movie object
	// Postconditions: - data from movie object is displayed
	// Notes: virtual function used in other classes
	virtual void display() const = 0 ;

	//------------------------ operator= --------------------------------------
	// Preconditions:   2 movie object
	// Postconditions: -this movie object is set to data in from object
	// Notes: virtual function used in other classes
	virtual bool operator=(const Movie &) = 0;

	//------------------------ operator== --------------------------------------
	// Preconditions:   2 movie object
	// Postconditions: -compares two movie objects to see if equal
	// Notes: virtual function used in other classes
	virtual bool operator==(const Movie &) const = 0;

	//------------------------ operator> --------------------------------------
	// Preconditions:   2 movie object
	// Postconditions: -compares two movie objects to see which one is 'bigger'
	// Notes: virtual function used in other classes
	virtual bool operator>(const Movie &) const = 0;

	//------------------------------Destructor-----------------------------------
	// Preconditions: movie object
	// Postconditions:  - movie object is gone
	virtual ~Movie();
};