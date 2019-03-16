#pragma once

#include "stdafx.h" 

#include "Transaction.h"

class Return : public Transaction
{

public:
	Return();

	virtual void doTransaction();
	virtual void setData();
	void display() const;

	~Return();
};