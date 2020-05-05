#pragma once
#include <iostream>
#include <string>
using namespace std;

class StringException : exception
{
public:
	StringException() {
		cout << "Ошибка!!! В строке присутствует цифра!!!\n";
	}
	friend string stringCheck();
};

string stringCheck();