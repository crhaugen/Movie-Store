#pragma once

#include "Customer.h"
#include <vector>
#include <string>

const int MAX_CUSTOMER = 500;

class HashFactory
{
private:

	vector<vector<Customer*>*> customers;

	int hash(string ID);


public:
	HashFactory();

	bool addCustomer(Customer *);
	bool isCustomer(Customer *);

	~HashFactory();
};