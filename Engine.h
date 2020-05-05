#pragma once
#include <iostream>
using namespace std;

class Engine
{
	double engineVolume;
	double power;

public:
	Engine();
	Engine(double volume, double power);

	void setEngineVolume(double volume);
	double getEngineVolume();
	void setEnginePower(double power);
	double getEnginePower();

	friend istream& operator >> (istream& input, Engine& obj);
	friend ostream& operator << (ostream& output, Engine& obj);
};

