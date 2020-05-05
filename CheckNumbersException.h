#pragma once
#include <iostream>
using namespace std;

class CheckNumbersException : exception
{
public:
	CheckNumbersException() { cout << "ќшибка!!! ¬вод строки вместо числа!!!\n"; }
	friend double CheckNumbers();
};

double CheckNumbers();