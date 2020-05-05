#include <fstream>
#include <string>
#include "Plane.h"

Plane::Plane(Engine eng, string model, string country, double weight)
{
	this->engine = eng;
	this->model = model;
	this->country = country;
	this->weight = weight;
	try {
		wing = new Wing();
		if (!wing)throw int(1);
	}
	catch (int a) {
		cout << "Ошибка выделения памяти!" << endl;
		throw;
	}
	cabin = new Cabin();
}

Plane::Plane() : engine(), wing(new Wing()), cabin(new Cabin()), model(), country(), weight() {};


Plane::~Plane() {

	delete wing;
	delete cabin;
}


void Plane::setModel(string model) {

	this->model = model;
}


string Plane::getModel() {

	return this->model;
}


void Plane::setCountry(string country) {

	this->country = country;
}


string Plane::getCountry() {

	return this->country;
}


void Plane::setWeight(double weight) {

	this->weight = weight;
}


double Plane::getWeight() {

	return this->weight;
}


void Plane::setEngineVolume(double volume) {

	this->engine.setEngineVolume(volume);
}


double Plane::getEngineVolume() {

	return this->engine.getEngineVolume();
}


void Plane::setEnginePower(double power) {

	this->engine.setEnginePower(power);
}


double Plane::getEnginePower() {

	return this->engine.getEnginePower();
}


void Plane::setWingType(string type) {

	this->wing->setWingType(type);
}


string Plane::getWingType() {

	return this->wing->getWingType();
}


void Plane::setWingLength(double length) {

	this->wing->setWingLength(length);
}


double Plane::getWingLength() {

	return this->wing->getWingLength();
}


void Plane::setWingMaterial(string material) {

	this->wing->setWingMaterial(material);
}

string Plane::getWingMaterial() {

	return this->wing->getWingMaterial();
}


void Plane::setAmountOfPlaces(int places) {

	this->cabin->setAmountOfPlaces(places);
}

int Plane::getAmountOfPlaces() {

	return this->cabin->getAmountOfPlaces();
}

istream& operator >> (istream& input, Plane& obj) {
	double engineVolume, enginePower, wingLength;
	int amountOfPlace;
	string wingType, wingMaterial;
	getline(input, obj.country);
	getline(input, obj.model);
	input >> obj.weight >> engineVolume >> enginePower >> amountOfPlace;
	input.get();
	getline(input, wingType);
	input >> wingLength;
	input.get();
	getline(input, wingMaterial);
	obj.setEngineVolume(engineVolume);
	obj.setEnginePower(enginePower);
	obj.setAmountOfPlaces(amountOfPlace);
	obj.setWingType(wingType);
	obj.setWingLength(wingLength);
	obj.setWingMaterial(wingMaterial);
	return input;
}

ostream& operator << (ostream& output, Plane& obj) {
	output << obj.country << "\n" << obj.model << "\n"
		<< obj.weight << "\n" << obj.getEngineVolume() << "\n" << obj.getEnginePower() << "\n" << obj.getAmountOfPlaces() << "\n" << obj.getWingType()
		<< "\n" << obj.getWingLength() << "\n" << obj.getWingMaterial() << "\n";
	return output;
}