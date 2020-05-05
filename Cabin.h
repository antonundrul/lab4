#pragma once
#include <iostream>
using namespace std;

class Cabin
{
	int amountOfPlaces;

public:
	Cabin();
	void setAmountOfPlaces(int places);
	int getAmountOfPlaces();

	friend istream& operator >> (istream& input, Cabin& obj);
	friend ostream& operator << (ostream& output, Cabin& obj);
};

