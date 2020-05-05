#include "Engine.h"

Engine::Engine() : engineVolume(), power() {}

Engine::Engine(double volume, double power) {

	this->engineVolume = volume;
	this->power = power;
}

void Engine::setEngineVolume(double volume) {
	this->engineVolume = volume;
}


double Engine::getEngineVolume() {

	return this->engineVolume;
}


void Engine::setEnginePower(double power) {

	this->power = power;
}


double Engine::getEnginePower() {

	return this->power;
}


istream& operator >> (istream& input, Engine& obj) {

	input >> obj.engineVolume >> obj.power;
	return input;
}

ostream& operator << (ostream& output, Engine& obj) {

	output << obj.engineVolume << "\n" << obj.power << "\n";
	return output;
}

