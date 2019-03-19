#pragma once

#include "stdafx.h"

#include "Transaction.h"
#include "Borrow.h"
#include "History.h"
#include "Return.h"

class TransactionFactory {
public:

	//------------------------------makeTransactionType-----------------------------------
	// Preconditions: type of transaction to be made
	// Postconditions:  - transaction of said type is made and returned
	static Transaction* makeTransactionType(char type);
};