#pragma once

#include "Customer.h"
const int MAX_CUSTOMER = 500;

class HashFactory
{
private:
	Customer * customers[MAX_CUSTOMER];

public:
	HashFactory();

	bool addCustomer(Customer *);
	bool isCustomer(Customer *);

	~HashFactory();
};