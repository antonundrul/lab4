#pragma once
#include "Engine.h"
#include "Wing.h"
#include "Cabin.h"

class Plane
{
private:
	Engine engine;
	Wing* wing;
	Cabin* cabin;
	string model;
	string country;
	double weight;

public:
	Plane();
	Plane(Engine eng, string model, string country, double weight);
	~Plane();

	void setModel(string model);
	string getModel();
	void setCountry(string country);
	string getCountry();
	void setWeight(double weight);
	double getWeight();

	void setEngineVolume(double volume);
	double getEngineVolume();
	void setEnginePower(double power);
	double getEnginePower();

	void setWingType(string type);
	string getWingType();
	void setWingLength(double length);
	double getWingLength();
	void setWingMaterial(string material);
	string getWingMaterial();

	void setAmountOfPlaces(int places);
	int getAmountOfPlaces();

	friend istream& operator >> (istream& input, Plane& obj);
	friend ostream& operator << (ostream& output, Plane& obj);
};
