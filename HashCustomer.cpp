#include "stdafx.h"

#include "HashCustomer.h"

HashCustomer::HashCustomer()
{
	customers.resize(MAX_CUSTOMER);
}

int HashCustomer::hash(int customerID)
{
	return customerID % MAX_CUSTOMER;
}

bool HashCustomer::addCustomer(Customer *customer)
{
	int hashNum = hash(customer->getID());

	if (customers.at(hashNum) == NULL)
	{
		customers.at(hashNum) = new vector<Customer*>();
	}
	else
	{
		for (int i = 0; i < customers.at(hashNum)->size(); i++)
		{
			if (customers.at(hashNum) != NULL)
			{
				if (customers.at(hashNum)->at(i)->getID() == customer->getID())
				{
					return false;
				}
			}
		}
	}

	customers.at(hashNum)->push_back(customer);
	return true;
}

bool HashCustomer::isCustomer(int customerID)
{
	int hashNum = hash(customerID);

	if (customers.at(hashNum) != nullptr)
	{
		for (int i = 0; i < customers.at(hashNum)->size(); i++)
		{
			if (customers.at(hashNum)->at(i)->getID() == customerID)
			{
				return true;
			}
		}
	}
	
	return false;
}

Customer* HashCustomer::getCustomer(int customerID)
{
	int hashNum = hash(customerID);

	if (customers.at(hashNum) != nullptr)
	{
		for (int i = 0; i < customers.at(hashNum)->size(); i++)
		{
			if (customers.at(hashNum)->at(i)->getID() == customerID)
			{
				return customers.at(hashNum)->at(i);
			}
		}
	}

	return NULL;
}

HashCustomer::~HashCustomer()
{

}