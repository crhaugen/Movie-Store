// Assignment4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Store.h"

#include <fstream>
#include <iostream>

using namespace std;


int main()
{
	ifstream infile("testMovie.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	ifstream infile2("testCustomer.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	Store s;
	s.buildMovies(infile);
	s.addCustomers(infile2);



	system("pause");
    return 0;
}

