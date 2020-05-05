#pragma once
#include <iostream>
#include <string>

using namespace std;



class Person
{
private:
	string name;
	string surname;
	int age;
	string rank;
	int experience;
public:
	Person();
	Person(string name, string surname, int age, string rank, int experience);
	~Person();

	void setName(string name);
	string getName();
	void setSurname(string surname);
	string getSurname();
	void setAge(int age);
	int getAge();

	void setRank(string rank);
	string getRank();
	void setExperience(int experience);
	int getExperience();

	void showRank();

	friend istream& operator >> (istream& input, Person& obj);
	friend ostream& operator << (ostream& output, Person& obj);
};

