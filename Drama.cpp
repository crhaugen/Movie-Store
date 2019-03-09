#include "stdafx.h"

#include "Drama.h"


Drama::Drama()
{

}

bool Drama::setData(istream& infile) 
{
	infile.get();
	infile >> stock;

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
