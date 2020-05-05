#include "CheckNumbersException.h"

double CheckNumbers() {
	double num;
	bool flag = false;
	do {
		try {
			cin >> num;
			if (cin.fail())
				throw CheckNumbersException();
			flag = false;
		}
		catch (CheckNumbersException)
		{
			cin.clear();
			cout << "Повторите ввод: ";
			cin.ignore(1000, '\n');
			flag = true;
		}
	} while (flag == true);
	cin.get();
	return num;
}