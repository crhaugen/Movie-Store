#pragma once
#include "stdafx.h"
#include "Movie.h"



class Drama : public Movie
{


public:
	Drama();

	virtual bool setData(istream &);
	virtual void display() const;

	virtual bool operator=(const Movie &);
	virtual bool operator==(const Movie &) const;
	virtual bool operator<(const Movie &) const;
	virtual bool operator>(const Movie &) const;

	virtual ~Drama();

};