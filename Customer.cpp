#include "stdafx.h"
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

bool Customer::hasItem(Movie *item) const
{
	if (history.size() > 0)
	{
		//going from lastest transactions
		for (int i = history.size() - 1; i >= 0; i++)
		{
			if (history.at(i)->getMovie() == item)
			{
				//I have the item
				if (history.at(i)->getTransactionType() == "Borrow")
				{
					return true;
				}

				//must of returned it, so don't have it
				return false;
			}
		}
	}
}

void Customer::displayHistory() const
{
	cout << "Customer: " << firstName << " " 
		<< lastName << " ID: " << ID << endl;

	if (history.size() > 0)
	{
		for (int i = history.size() - 1; i >= 0; i++)
		{
			history.at(i)->display();
		}
	}
	else
	{
		cout << "Customer has no History" << endl;
	}
}

bool Customer::isTransactionValid(string transType, Movie *item) const
{
	//see if customer has item
	bool hasItem = this->hasItem(item);

	if (transType == "Return" && hasItem)
	{
		return true;
	}
	else if (transType == "Return" && !hasItem)
	{
		cout << "You don't have this item" << endl;
		return false;
	}
	
	if(transType == "Borrow" && hasItem)
	{
		cout << "You already have this item" << endl;
		return false;
	}
	else if (transType == "Borrow" && !hasItem)
	{
		return false;
	}
}

void Customer::setTransaction(Transaction *trans)
{
	history.push_back(trans);
}


Customer::~Customer()
{

}