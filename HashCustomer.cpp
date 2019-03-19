#include "HashCustomer.h"

HashFactory::HashFactory()
{
	customers.resize(MAX_CUSTOMER);
}

int HashFactory::hash(string ID)
{
	int IDNumber = stoi(ID);
	return IDNumber % MAX_CUSTOMER;
}

bool HashFactory::addCustomer(Customer *customer)
{
	int hashNum = hash(customer->getID);

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

bool HashFactory::isCustomer(Customer *customer)
{
	int hashNum = hash(customer->getID);

	if (customers.at(hashNum) != nullptr)
	{
		for (int i = 0; i < customers.at(hashNum)->size(); i++)
		{
			if (customers.at(hashNum)->at(i)->getID() == customer->getID())
			{
				return true;
			}
		}
	}
	
	return false;
}

HashFactory::~HashFactory()
{

}