// ------------------------------------- Drama.cpp -------------------------- 
// Chyanne Haugen (crhaugen@uw.edu) CSS 343 A
// Creation Date: 3/5/19 
// Date of Last Modification: 
// ----------------------------------------------------------------------------
// Purpose - Drama class creates movies of type drama, inheritance from movie 
//				class
//       
//			 Feature:
//				- Overloaded operations: <,>, =, ==
//				- 
//
// ----------------------------------------------------------------------------
// Notes:
//	-To use <,>,== on drama type when I was passing in a movies type I used
//		'dynamic_cast' to downcast movie to drama so correct operation could
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




#include "stdafx.h"

#include "Drama.h"


Drama::Drama()
{

}

bool Drama::setData(istream& infile) 
{
	infile.get();
	infile >> currentStock;
	maxStock = currentStock;

	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');

	infile.get();
	infile >> year;

	return true;
}


void Drama::display() const
{
	cout << getTitle() << " " << getDirector() << " " << getYear() << endl;
}

bool Drama::operator=(const Movie &otherData)
{
	 const Drama *dramaPtr = dynamic_cast<const Drama*>(&otherData);

	 if (dramaPtr == nullptr)
	 {
		 cout << "Error" << endl;
		 return false;
	 }

	this->director = dramaPtr->getDirector();
	this->title = dramaPtr->getTitle();
	this->year = dramaPtr->getYear();
}

bool Drama::operator==(const Movie &otherData) const
{
	const Drama *dramaPtr = dynamic_cast<const Drama*>(&otherData);

	if (dramaPtr == nullptr)
	{
		cout << "Error" << endl;
		return false;
	}

	return (getDirector() == dramaPtr->getDirector())
		&& (getTitle() == dramaPtr->getTitle());
}

bool Drama::operator<(const Movie &otherData) const
{
	const Drama *dramaPtr = dynamic_cast<const Drama*>(&otherData);

	if (dramaPtr == nullptr)
	{
		cout << "Error" << endl;
		return false;
	}

	return (*this > *dramaPtr) ? false : true;
}

bool Drama::operator>(const Movie &otherData) const
{
	const Drama *dramaPtr = dynamic_cast<const Drama*>(&otherData);

	if (dramaPtr == nullptr)
	{
		cout << "Error" << endl;
		return false;
	}

	if (getDirector() != dramaPtr->getDirector())
	{
		return getDirector() > dramaPtr->getDirector();
	}
	else
	{
		return getTitle() > dramaPtr->getTitle();
	}
}

Drama::~Drama()
{

}
