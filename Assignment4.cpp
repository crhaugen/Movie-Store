// Assignment4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Store.h"

#include <fstream>
#include <iostream>

using namespace std;


int main()
{
	ifstream infile("data4movies.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	ifstream infile2("data4customers.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	ifstream infile3("data4commands.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	Store s;
	s.buildMovies(infile);
	s.addCustomers(infile2);
	s.readTransaction(infile3);



	system("pause");
    return 0;
}

