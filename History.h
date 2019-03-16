#pragma once

#include "stdafx.h" 

#include "Transaction.h"

class History : public Transaction
{
	History();
	virtual void doTransaction();
	virtual void setData();

	~History();
};