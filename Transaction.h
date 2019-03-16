#pragma once

#include "stdafx.h"
#include <iostream>


using namespace std;

class Transaction
{
protected:
	string transactionType;

public:
	Transaction();

	virtual void doTransaction() = 0;
	virtual void setData() = 0;

	static Transaction *makeTransactionType(char type);

	~Transaction();
};