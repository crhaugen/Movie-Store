// ------------------------------------- Comedy.cpp -------------------------- 
// Chyanne Haugen (crhaugen@uw.edu) CSS 343 A
// Creation Date: 3/5/19 
// Date of Last Modification: 
// ----------------------------------------------------------------------------
// Purpose - comedy class creates movies of type comedy, inheritance from movie 
//				class
//       
//			 Feature:
//				- Overloaded operations: <,>, =, ==
//				- 
//
// ----------------------------------------------------------------------------
// Notes:
//	-To use <,>,== on comedy type when I was passing in a movies type I used
//		'dynamic_cast' to downcast movie to comedy so correct operation could
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

#include "Comedy.h"


//------------------------ Default constructor -------------------------------
// Preconditions:   None
// Postconditions: - comedy object created
Comedy::Comedy()
{

}

//------------------------ setData() ------------------------------------------
// Preconditions: stream from a file
// Postconditions: - comedy object has information from file
// Assumptions: data will be correctly formatted.
bool Comedy::setData(istream& infile)
{
	//getting stock which will be max stock for that type
	infile.get();
	infile >> currentStock;
	maxStock = currentStock;

	//geting director information
	infile.get();
	infile.get();
	getline(infile, director, ',');

	//geting title information
	infile.get();
	getline(infile, title, ',');

	//getting year 
	infile.get();
	infile >> year;

	return true;
}

bool Comedy::setSortingAttributes(istream& infile)
{
	//geting title information
	infile.get();
	getline(infile, title, ',');

	//getting year 
	infile.get();
	infile >> year;

	return true;
}

bool Comedy::equalsBySortType(const Movie &otherData) const
{
	//downcasting movie to comedy 
	const Comedy *comedyPtr = dynamic_cast<const Comedy*>(&otherData);

	//checking if the downcast was good (should always be good)
	if (comedyPtr == nullptr)
	{
		cout << "Error" << endl;
		return false;
	}

	return (this->year == comedyPtr->getYear())
		&& (this->title == comedyPtr->getTitle());
}

//------------------------ display() ------------------------------------------
// Preconditions: comedy object
// Postconditions: - prints out information from comedy object
void Comedy::display() const
{
	cout << getTitle() << " " << getDirector() << " " << getYear();
}

//------------------------ operator= ------------------------------------------
// Preconditions: comedy object and movie object
// Postconditions: - comedy object has been set with information in otherData
// Assumptions: to compare a moive object with a comedy object I'm downcasting 
//	the movie object to comedy
//	-from my understanding this downcast should always work in this case.
bool Comedy::operator=(const Movie &otherData)
{
	//downcasting movie to comedy 
	const Comedy *comedyPtr = dynamic_cast<const Comedy*>(&otherData);

	//checking if the downcast was good (should always be good)
	if (comedyPtr == nullptr)
	{
		cout << "Error" << endl;
		return false;
	}

	//setting information
	this->director = comedyPtr->getDirector();
	this->title = comedyPtr->getTitle();
	this->year = comedyPtr->getYear();
}

//------------------------ operator== ------------------------------------------
// Preconditions: comedy object and movie object
// Postconditions: - true or false depending on if objects are equal
// Assumptions: to compare a moive object with a comedy object I'm downcasting 
//	the movie object to comedy
//	-from my understanding this downcast should always work in this case.
bool Comedy::operator==(const Movie &otherData) const
{
	//downcasting movie to comedy 
	const Comedy *comedyPtr = dynamic_cast<const Comedy*>(&otherData);

	//checking if the downcast was good (should always be good)
	if (comedyPtr == nullptr)
	{
		cout << "Error" << endl;
		return false;
	}

	return (this->year == comedyPtr->getYear())
		&& (this->director == comedyPtr->getDirector())
		&& (this->title == comedyPtr->getTitle());
}


//------------------------ operator> ------------------------------------------
// Preconditions: comedy object and movie object
// Postconditions: - true or false depending on if this object is smaller 
// Assumptions: to compare a moive object with a comedy object I'm downcasting 
//	the movie object to comedy
//	-from my understanding this downcast should always work in this case.
bool Comedy::operator>(const Movie &otherData) const
{
	//downcasting movie to comedy 
	const Comedy *comedyPtr = dynamic_cast<const Comedy*>(&otherData);

	//checking if the downcast was good (should always be good)
	if (comedyPtr == nullptr)
	{
		cout << "Error" << endl;
		return false;
	}

	//sorting by title, then year it was released
	if (this->title != comedyPtr->getTitle())
	{
		return this->title > comedyPtr->getTitle();
	}
	else 
	{
		return this->year > comedyPtr->getYear();
	}
}

//------------------------------Destructor-----------------------------------
// Preconditions: comedy object
// Postconditions:  - comedy object is gone
Comedy::~Comedy()
{

}