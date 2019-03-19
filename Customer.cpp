#include "Customer.h"

Customer::Customer()
{
	firstName = " ";
	lastName = " ";
	ID = 0;
}

void Customer::setData(istream& infile)
{
	infile >> ID;
	
	if (infile.eof())
	{
		return;
	}

	infile.get();
	infile >> lastName;

	infile.get();
	infile >> firstName;
}

int Customer::getID() const
{
	return this->ID;
}

string Customer::getFirstName() const
{
	return this->firstName;
}

string Customer::getLastName() const
{
	return this->lastName;
}

void Customer::displayHistory() const
{

}

bool Customer::isTransactionValid(string transType, Movie *item) const
{
	//check is user has movie

	if (transType == "Return")
	{
		return true;
	}
	else if(transType == "Borrow")
	{
		return true;
	}

	return false;
}

void Customer::setTransaction(Transaction *trans)
{

}


Customer::~Customer()
{

}