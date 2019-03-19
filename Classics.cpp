// ------------------------------------- classics.cpp -------------------------- 
// Chyanne Haugen (crhaugen@uw.edu) CSS 343 A
// Creation Date: 3/5/19 
// Date of Last Modification: 
// ----------------------------------------------------------------------------
// Purpose - classics class creates movies of type classics, inheritance from movie 
//				class
//       
//			 Feature:
//				- Overloaded operations: <,>, =, ==
//				- 
//
// ----------------------------------------------------------------------------
// Notes:
//	-To use <,>,== on classics type when I was passing in a movies type I used
//		'dynamic_cast' to downcast movie to classics so correct operation could
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

#include "classics.h"


//------------------------ Default constructor -------------------------------
// Preconditions:   None
// Postconditions: - classics object created
Classics::Classics()
{
	month = 0;
	firstName = " ";
	lastName = " ";
}

int Classics::getMonth() const
{
	return month;
}

string Classics::getFirstName() const
{
	return firstName;
}

string Classics::getLastName() const
{
	return lastName;
}

//------------------------ setData() ------------------------------------------
// Preconditions: stream from a file
// Postconditions: - classics object has information from file
// Assumptions: data will be correctly formatted.
bool Classics::setData(istream& infile)
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
	infile >> firstName;
	infile >> lastName;

	infile >> month;
	infile >> year;

	return true;
}

//------------------------ setSortingAttributes() ------------------------------------------
// Preconditions: stream from a file
// Postconditions: - classics object has information from file
// Assumptions: data will be correctly formatted.
bool Classics::setSortingAttributes(istream& infile)
{
	infile.get();

	infile >> month;
	infile >> year;

	infile >> firstName;
	infile >> lastName;

	return true;
}


//------------------------ display() ------------------------------------------
// Preconditions: classics object
// Postconditions: - prints out information from classics object
void Classics::display() const
{
	cout << getTitle() << " " << getDirector() << " " << getYear() << endl;
}

//------------------------ operator= ------------------------------------------
// Preconditions: classics object and movie object
// Postconditions: - classics object has been set with information in otherData
// Assumptions: to compare a moive object with a classics object I'm downcasting 
//	the movie object to classics
//	-from my understanding this downcast should always work in this case.
bool Classics::operator=(const Movie &otherData)
{
	//downcasting movie to classics 
	const Classics *classicsPtr = dynamic_cast<const Classics*>(&otherData);

	//checking if the downcast was good (should always be good)
	if (classicsPtr == nullptr)
	{
		cout << "Error" << endl;
		return false;
	}

	//setting information
	this->firstName = classicsPtr->getFirstName();
	this->lastName = classicsPtr->getLastName();
	this->month = classicsPtr->getMonth();
	this->director = classicsPtr->getDirector();
	this->title = classicsPtr->getTitle();
	this->year = classicsPtr->getYear();
}

//------------------------ operator== ------------------------------------------
// Preconditions: classics object and movie object
// Postconditions: - true or false depending on if objects are equal
// Assumptions: to compare a moive object with a classics object I'm downcasting 
//	the movie object to classics
//	-from my understanding this downcast should always work in this case.
bool Classics::operator==(const Movie &otherData) const
{
	//downcasting movie to classics 
	const Classics *classicsPtr = dynamic_cast<const Classics*>(&otherData);

	//checking if the downcast was good (should always be good)
	if (classicsPtr == nullptr)
	{
		cout << "Error" << endl;
		return false;
	}

	return (this->year == classicsPtr->getYear())
		&& (this->month == classicsPtr->getMonth()) 
		&& (this->firstName == classicsPtr->getFirstName())
		&& (this->lastName == classicsPtr->getLastName())
		&& (this->director == classicsPtr->getDirector())
		&& (this->title == classicsPtr->getTitle());
}


//------------------------ operator> ------------------------------------------
// Preconditions: classics object and movie object
// Postconditions: - true or false depending on if this object is smaller 
// Assumptions: to compare a moive object with a classics object I'm downcasting 
//	the movie object to classics
//	-from my understanding this downcast should always work in this case.
bool Classics::operator>(const Movie &otherData) const
{
	//downcasting movie to classics 
	const Classics *classicsPtr = dynamic_cast<const Classics*>(&otherData);

	//checking if the downcast was good (should always be good)
	if (classicsPtr == nullptr)
	{
		cout << "Error" << endl;
		return false;
	}
	
	//sorting classics by release date (year then month) then major actor
	if (this->year != classicsPtr->getYear())
	{
		return this->year > classicsPtr->getYear();
	}
	else if (this->month != classicsPtr->getMonth())
	{
		return this->month > classicsPtr->getMonth();
	}
	else
	{
		if (this->firstName != classicsPtr->getFirstName())
		{
			return this->firstName > classicsPtr->getFirstName();
		}
		else
		{
			return this->lastName > classicsPtr->getLastName();
		}
	}
}

//------------------------------Destructor-----------------------------------
// Preconditions: classics object
// Postconditions:  - classics object is gone
Classics::~Classics()
{

}