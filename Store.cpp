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

				//if drama object is already in the tree delete
				if (!dramaTree.insert(movie))
				{
					delete movie;
				}

				break;
			case 'F':
				break;
			case 'C':
				break;
			//any other input types will be invalid and discarded
			default:
				cout << "Error invalid input (code) type" << endl;
				//remove line!!!
				break;
		}

	}
}