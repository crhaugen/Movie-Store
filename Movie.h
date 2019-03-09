#pragma once
#include "stdafx.h"
#include <iostream>

#include <string>
using namespace std;

class Movie
{
protected: 
	string title;
	string director;
	int year;
	int stock;

public:
	Movie();

	string getTitle() const;
	string getDirector() const;
	int getYear() const;

	virtual bool setData(istream&) = 0;
	virtual void display() const = 0 ;

	virtual bool operator=(const Movie &) = 0;
	virtual bool operator==(const Movie &) const = 0;
	virtual bool operator<(const Movie &) const = 0;
	virtual bool operator>(const Movie &) const = 0;

	virtual ~Movie();
};