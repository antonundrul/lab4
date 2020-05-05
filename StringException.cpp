#include "StringException.h"

string stringCheck() {
	string s;
	bool flag = false;
	cin.ignore();
	getline(cin, s, '\n');
	do
	{
		try
		{
			for (int i = 0; i < s.length(); i++)
				if (s[i] > '0' && s[i] < '9') {
					flag = false;
					throw StringException();
				}
			flag = true;
		}
		catch (StringException)
		{
			cin.clear();
			cout << "Повторите ввод: ";
			getline(cin, s, '\n');
			flag = false;
		}
	} while (flag == false);

	return s;
}
