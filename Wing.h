#pragma once
#include <iostream>
#include<string>
using namespace std;

class Wing
{
	string wingType;
	double wingLength;
	string wingMaterial;

public:
	Wing();

	void setWingType(string type);
	string getWingType();
	void setWingLength(double length);
	double getWingLength();
	void setWingMaterial(string material);
	string getWingMaterial();

	friend istream& operator >> (istream& input, Wing& obj);
	friend ostream& operator << (ostream& output, Wing& obj);
};
