
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