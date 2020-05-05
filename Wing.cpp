#include "Wing.h"

Wing::Wing() : wingType(), wingLength(), wingMaterial() {};

void Wing::setWingType(string type) {
	this->wingType = type;
}

string Wing::getWingType() {
	return this->wingType;
}

void Wing::setWingLength(double length) {
	this->wingLength = length;
}

double Wing::getWingLength() {
	return this->wingLength;
}

void Wing::setWingMaterial(string material) {
	this->wingMaterial = material;
}

string Wing::getWingMaterial() {
	return this->wingMaterial;
}

istream& operator >> (istream& input, Wing& obj) {
	input >> obj.wingType >> obj.wingLength >> obj.wingMaterial;
	return input;
}

ostream& operator << (ostream& output, Wing& obj) {
	output << obj.wingType << "\n" << obj.wingLength << "\n"
		<< obj.wingMaterial << "\n";
	return output;
}

