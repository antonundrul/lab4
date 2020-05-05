#include <fstream>
#include "Person.h"
#include <string>

Person::Person() {
	this->name = '\0';
	this->surname = '\0';
	this->age = 0;
	this->rank = '\0';
	this->experience = 0;
}

Person::Person(string name, string surname, int age, string rank, int experience) {
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->rank = rank;
	this->experience = experience;
}

Person::~Person() {

}

void Person::setName(string name) {
	this->name = name;
}

string Person::getName() {
	return this->name;
}

void Person::setSurname(string surname) {
	this->surname = surname;
}

string Person::getSurname() {
	return this->surname;
}

void Person::setAge(int age) {
	this->age = age;
}

int Person::getAge() {
	return this->age;
}

void Person::setRank(string rank) {
	this->rank = rank;
}

string Person::getRank() {
	return this->rank;
}

void Person::setExperience(int experience) {
	this->experience = experience;
}

int Person::getExperience() {
	return this->experience;
}

void Person::showRank() {
	cout << "1.Майор" << endl;
	cout << "2.Подполковник" << endl;
	cout << "3.Полковник" << endl;
}

istream& operator >> (istream& input, Person& obj) {
	int age, experience;
	getline(input, obj.name);
	getline(input, obj.surname);
	input >> age;
	input.get();
	getline(input, obj.rank);
	input >> experience;
	input.get();
	obj.setAge(age);
	obj.setExperience(experience);
	return input;
}

ostream& operator << (ostream& output, Person& obj) {
	output << obj.name << "\n" << obj.surname << "\n"
		<< obj.age << "\n" << obj.rank << "\n" << obj.experience << "\n";
	return output;
}