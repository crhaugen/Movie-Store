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
//		-
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

		switch (movieType)
		{
			case 'D':
				movie = new Drama;
				movie->setData(infile);

				if (!dramaTree.insert(movie))
				{
					delete movie;
				}

				break;
	
			default:
				cout << "error" << endl;
				break;
		}

	}
}