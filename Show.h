#pragma once

#include "stdafx.h" 

#include "Transaction.h"

class Show : public Transaction
{
	Show();
	virtual void doTransaction();
	virtual void setData();
	~Show();
};