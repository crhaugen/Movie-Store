// ------------------------------------- Store.cpp -------------------------- 
// Chyanne Haugen (crhaugen@uw.edu) CSS 343 A
// Creation Date: 3/5/19 
// Date of Last Modification: 
// ----------------------------------------------------------------------------
// Purpose - Store class runs all the business logic for the movie store.
//       
//			 Feature:
//				- Reads from files.
//				- Has 3 binary search tree of the different movies types
//					and a hashtable from customers
//
// ----------------------------------------------------------------------------
// Notes:
//		-
//		-
//      
// Assumptions:
//		- Not allowing any dupliate movie type object to be created
//		-
//
// ----------------------------------------------------------------------------


#include "stdafx.h"
#include "Store.h"


Store::Store()
{
	
}

bool Store::validCustomer(int id)
{
	return false;
}

void Store::buildMovies(istream& infile)
{
	char movieType = ' ';
	Movie *movie;

	while (true)
	{
		infile >> movieType;

		if (infile.eof())
		{
			break;
		}

		switch (movieType)
		{
			case 'D':
				movie = new Drama;
				movie->setData(infile);

				//if object is already in the tree delete
				if (!dramaTree.insert(movie))
				{
					delete movie;
				}

				break;
			case 'F':
				movie = new Comedy;
				movie->setData(infile);

				//if object is already in the tree delete
				if (!comedyTree.insert(movie))
				{
					delete movie;
				}

				break;
			case 'C':
				movie = new Classics;
				movie->setData(infile);
			

				//if object is already in the tree delete
				if (classicsTree.find(movie))
				{
					delete movie;
				}
				else
				{
					int oldStock = classicsTree.retrieveByTitle(movie->getTitle(), 
						movie->getMaxStock());

					//adding old stock to new stock if there is any
					if (oldStock != 0)
					{
						movie->increaseStockLevel(oldStock);
					}

					classicsTree.insert(movie);
				}

				break;
			//any other input types will be invalid and discarded
			default:
				cout << "Error invalid input (code) type" << endl;
				//removing line
				string junkData;
				getline(infile, junkData);
				break;
		}

	}

}

void Store::readTransaction(istream& infile)
{
	char transType = ' ';

	while (true)
	{
		infile >> transType;

		if (infile.eof())
		{
			break;
		}

		if (transType == 'S')
		{
			//do print of store
		}
		else
		{
			Transaction *transPtr = 
				Transaction::makeTransactionType(transType);

			if (transPtr == NULL)
			{
				cout << "Transaction type not vaild" << endl;
				//clean line
			}
			else
			{
				int customerID = 0;
				infile >> customerID;

				if (validCustomer(customerID))
				{
					if (transPtr->getTransactionType != "History")
					{
						char media = ' ';
						
						//check if media is valid 
						//create a movie base on input

					}
					else
					{
						//print customer history
					}
				}
				else
				{

				}
			}
			
		}

	}
}