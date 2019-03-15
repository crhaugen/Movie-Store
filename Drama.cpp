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


//------------------------ Default constructor -------------------------------
// Preconditions:   None
// Postconditions: - drama object created
Drama::Drama()
{

}

//------------------------ setData() ------------------------------------------
// Preconditions: stream from a file
// Postconditions: - drama object has information from file
// Assumptions: data will be correctly formatted.
bool Drama::setData(istream& infile) 
{
	//getting stock which will be max stock for that type
	infile.get();
	infile >> currentStock;
	maxStock = currentStock;

	//geting director information
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

//------------------------ display() ------------------------------------------
// Preconditions: drama object
// Postconditions: - prints out information from drama object
void Drama::display() const
{
	cout << getTitle() << " " << getDirector() << " " << getYear() << endl;
}

//------------------------ operator= ------------------------------------------
// Preconditions: drama object and movie object
// Postconditions: - drama object has been set with information in otherData
// Assumptions: to compare a moive object with a drama object I'm downcasting 
//	the movie object to drama
//	-from my understanding this downcast should always work in this case.
bool Drama::operator=(const Movie &otherData)
{
	 //downcasting movie to drama 
	 const Drama *dramaPtr = dynamic_cast<const Drama*>(&otherData);

	 //checking if the downcast was good (should always be good)
	 if (dramaPtr == nullptr)
	 {
		 cout << "Error" << endl;
		 return false;
	 }

	//setting information
	this->director = dramaPtr->getDirector();
	this->title = dramaPtr->getTitle();
	this->year = dramaPtr->getYear();
}

//------------------------ operator== ------------------------------------------
// Preconditions: drama object and movie object
// Postconditions: - true or false depending on if objects are equal
// Assumptions: to compare a moive object with a drama object I'm downcasting 
//	the movie object to drama
//	-from my understanding this downcast should always work in this case.
bool Drama::operator==(const Movie &otherData) const
{
	//downcasting movie to drama 
	const Drama *dramaPtr = dynamic_cast<const Drama*>(&otherData);

	//checking if the downcast was good (should always be good)
	if (dramaPtr == nullptr)
	{
		cout << "Error" << endl;
		return false;
	}

	return (this->year == dramaPtr->getYear())
		&& (this->director == dramaPtr->getDirector())
		&& (this->title == dramaPtr->getTitle());
}


//------------------------ operator> ------------------------------------------
// Preconditions: drama object and movie object
// Postconditions: - true or false depending on if this object is smaller 
// Assumptions: to compare a moive object with a drama object I'm downcasting 
//	the movie object to drama
//	-from my understanding this downcast should always work in this case.
bool Drama::operator>(const Movie &otherData) const
{
	//downcasting movie to drama 
	const Drama *dramaPtr = dynamic_cast<const Drama*>(&otherData);

	//checking if the downcast was good (should always be good)
	if (dramaPtr == nullptr)
	{
		cout << "Error" << endl;
		return false;
	}

	//sorting by director, then title
	if (getDirector() != dramaPtr->getDirector())
	{
		return getDirector() > dramaPtr->getDirector();
	}
	else
	{
		return getTitle() > dramaPtr->getTitle();
	}
}

//------------------------------Destructor-----------------------------------
// Preconditions: drama object
// Postconditions:  - drama object is gone
Drama::~Drama()
{

}