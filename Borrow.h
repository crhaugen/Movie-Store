#pragma once

#include "stdafx.h" 

#include "Transaction.h"

class Borrow : public Transaction
{
public:
	Borrow();

	virtual void doTransaction();
	virtual void setData();
	void display() const;

	~Borrow();
};