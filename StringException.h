#pragma once
#include <iostream>
#include <string>
using namespace std;

class StringException : exception
{
public:
	StringException() {
		cout << "������!!! � ������ ������������ �����!!!\n";
	}
	friend string stringCheck();
};

string stringCheck();