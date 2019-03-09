#pragma once

#include "stdafx.h"

#include "Drama.h"
#include "BinTree.h"
#include <iostream>

using namespace std;

class Store
{
private:
	BinTree dramaTree;

public:

	Store();

	void buildMovies(istream& infile);



};