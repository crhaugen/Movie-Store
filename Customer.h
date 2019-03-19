#pragma once
#include "stdafx.h"
#include "Transaction.h"
#include <istream>
#include <vector>

using namespace std;

class Customer
{
private:
	string firstName;
	string lastName;
	int ID;
	vector<Transaction*> history;

	bool hasItem(Movie *) const;


public:
	Customer();

	void setData(istream&);

	int getID() const;
	string getFirstName() const;
	string getLastName() const;

	void displayHistory() const;

	void setTransaction(Transaction *trans);

	bool isTransactionValid(string transType, Movie *item) const;

	~Customer();
};