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

 Movie::~Movie()
 {

 }