#pragma once
#include "stdafx.h"
#include "Customer.h"
#include <vector>
#include <string>

const int MAX_CUSTOMER = 500;

class HashCustomer
{
private:

	vector<vector<Customer*>*> customers;

	int hash(int ID);


public:
	HashCustomer();

	bool addCustomer(Customer *);
	bool isCustomer(int);
	Customer* getCustomer(int customerID);

	~HashCustomer();
};