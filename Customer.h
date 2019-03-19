#pragma once

#include <istream>
#include <vector>

#include "Transaction.h"
using namespace std;
class Customer
{
private:
	string firstName;
	string lastName;
	int ID;
	vector<Transaction>history;


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