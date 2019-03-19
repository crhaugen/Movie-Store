#include "stdafx.h"

#include "TransactionFactory.h"

//------------------------------makeTransactionType-----------------------------------
// Preconditions: type of transaction to be made
// Postconditions:  - transaction of said type is made and returned
Transaction* TransactionFactory::makeTransactionType(char type)
{
	switch (type)
	{
	case 'H':
		return new History;
		break;
	case 'B':
		return new Borrow;
		break;
	case 'R':
		return new Return;
		break;

	default:
		return NULL;
		break;
	}
}