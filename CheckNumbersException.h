#pragma once
#include <iostream>
using namespace std;

class CheckNumbersException : exception
{
public:
	CheckNumbersException() { cout << "������!!! ���� ������ ������ �����!!!\n"; }
	friend double CheckNumbers();
};

double CheckNumbers();