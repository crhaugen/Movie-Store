#pragma once

#include "stdafx.h"

#include "Movie.h"
#include "Drama.h"
#include "Comedy.h"
#include "Classics.h"

class MovieFactory {
public:

	//------------------------------makeMovieType-----------------------------------
	// Preconditions: type of Movie to be made
	// Postconditions:  - Movie of said type is made and returned
	static Movie* makeMovieType(char type);
};