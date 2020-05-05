#include "Cabin.h"

Cabin::Cabin() : amountOfPlaces(0) {};

void Cabin::setAmountOfPlaces(int places) {
	this->amountOfPlaces = places;
}

int Cabin::getAmountOfPlaces() {
	return this->amountOfPlaces;
}

istream& operator >> (istream& input, Cabin& obj) {
	input >> obj.amountOfPlaces;
	return input;
}

ostream& operator << (ostream& output, Cabin& obj) {
	output << obj.amountOfPlaces << "\n";
	return output;
}