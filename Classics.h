// ------------------------------------- Classics.h -------------------------- 
// Chyanne Haugen (crhaugen@uw.edu) CSS 343 A
// Creation Date: 3/10/19 
// Date of Last Modification: 
// ----------------------------------------------------------------------------
// Purpose - Classics class creates movies of type Classics, inheritance from movie 
//				class
//       
//			 Feature:
//				- Overloaded operations: <,>, =, ==
//				- 
//
// ----------------------------------------------------------------------------
// Notes:
//	-To use <,>,== on Classics type when I was passing in a movies type I used
//		'dynamic_cast' to downcast movie to Classics so correct operation could
//		 be proformed. For some of the movie types I didn't really need to do 
//		it but I thought it would make more sense just to do it in all 
//		childern class and not just the one that really needed it.
//		From what I researched I believe I'm using downcasting with 
//		'dynamic_cast' correctly and safely. I used the following link to
//		figure out how to do it:
//          <https://www.bogotobogo.com/cplusplus/upcasting_downcasting.php>
//		-
//      
// Assumptions:
//		-
//		-
//
// ----------------------------------------------------------------------------

#pragma once
#include "stdafx.h"
#include "Movie.h"


class Classics : public Movie
{
private:
	int month;
	string firstName;
	string lastName;

public:
	Classics();

	int getMonth() const;
	string getFirstName() const;
	string getLastName() const;

	virtual bool setData(istream &);
	bool setSortingAttributes(istream& infile);
	virtual void display() const;

	virtual bool operator=(const Movie &);
	virtual bool operator==(const Movie &) const;
	virtual bool operator>(const Movie &) const;

	virtual ~Classics();

};
