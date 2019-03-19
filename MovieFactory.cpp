#include "stdafx.h"
#include "MovieFactory.h"

//------------------------------makeTransactionType-----------------------------------
// Preconditions: type of transaction to be made
// Postconditions:  - transaction of said type is made and returned
Movie* MovieFactory::makeMovieType(char type)
{
	switch (type)
	{
	case 'F':
		return new Comedy;
		break;
	case 'D':
		return new Drama;
		break;
	case 'C':
		return new Classics;
		break;

	default:
		return NULL;
		break;
	}
}