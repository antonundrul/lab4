#define _CRT_SECURE_NO_WARNINGS 
#include <iomanip>
#include<Windows.h>
#include <fstream>
#include <string>
#include <locale.h>
#include <vector>
#include <map>
#include "Plane.h"
#include "Person.h"
#include "CheckNumbersException.h"
#include "functions.h"

vector <Plane*> planeVect;
vector<Person*> personVect;
map <string, int> newMap;
multimap<string, string> countries;




int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choiсe = -1;
	Plane* plane;
	Person* person;

	bool isFlag = true;

	int addChoice = -1, delChoice = -1, viewChoice = -1, editChoice = -1, srchChoice = -1, sortChoice = -1;

	createPlaneFile();
	readPlaneFile("Plane.txt");
	createPersonFile();
	readPersonFile("Person.txt");

	int majCount = 0, podCount = 0, polCount = 0;
	majCount = 0;
	podCount = 0;
	polCount = 0;
	for (auto i : personVect)
	{
		if (i->getRank() == "Major") majCount++;
		if (i->getRank() == "Podpolkovnik") podCount++;
		if (i->getRank() == "Polkovnik") polCount++;
	}
	newMap["Major"] = majCount;
	newMap["Podpolkovnik"] = podCount;
	newMap["Polkovnik"] = polCount;
	do
	{

		textMainMenu();
		choiсe = CheckNumbers();
		switch (choiсe)
		{
		case 1:

			do {
				textAddMenu();
				addChoice = CheckNumbers();
				switch (addChoice) {
				case 1:
					addPlaneRecord();
					break;

				case 2:
					addPersonRecord();
					break;
				}
			} while (addChoice != 0);

			break;

		case 2:
			do {
				textDelRecMenu();
				delChoice = CheckNumbers();
				switch (delChoice) {
				case 1:
					delPlaneRecord();
					break;

				case 2:
					delPersonRecord();
					break;

				case 3:
					delAllRecords();
					break;
				}
			} while (delChoice != 0);

			break;

		case 3: system("cls");

			do {
				textViewMenu();
				viewChoice = CheckNumbers();
				switch (viewChoice) {
				case 1:
					try
					{
						if (planeVect.empty()) throw 1;
						viewPlaneRecord();

					}
					catch (...)
					{
						cout << "Список самолётов пуст!" << endl;
					}
					system("pause");
					break;

				case 2:
					try
					{
						if (personVect.empty()) throw 1;
						viewPersonRecord();

					}
					catch (...)
					{
						cout << "Список капитанов пуст!" << endl;
					}
					system("pause");
					break;

				case 3:
					system("cls");
					majCount = 0;
					podCount = 0;
					polCount = 0;
					for (auto i : personVect)
					{
						if (i->getRank() == "Major") majCount++;
						if (i->getRank() == "Podpolkovnik") podCount++;
						if (i->getRank() == "Polkovnik") polCount++;
					}
					newMap["Major"] = majCount;
					newMap["Podpolkovnik"] = podCount;
					newMap["Polkovnik"] = polCount;
					cout << "Количество пилотов:" << endl;
					cout << " _________________________________" << endl;
					cout << "|   Звание:   " << setw(18) << "|    Количество:   |" << endl;
					cout << " _________________________________" << endl;

					for (auto i : newMap)
					{

						cout << left << "|" << setw(13) << i.first << "|" << setw(18) << i.second << "|" << endl;
						cout << " _________________________________" << endl;

					}
					system("pause");
					break;
				}
			} while (viewChoice != 0);

			break;

		case 4:

			do {
				textEditMenu();
				editChoice = CheckNumbers();
				switch (editChoice) {
				case 1:
					try
					{
						if (planeVect.empty()) throw 1;
						editPlaneRecord();

					}
					catch (...)
					{
						cout << "Список самолётов пуст!" << endl;
					}
					system("pause");
					break;

				case 2:
					try
					{
						if (personVect.empty()) throw 1;
						//	textEditPersonMenu();
						editPersonRecord();

					}
					catch (...)
					{
						cout << "Список капитанов пуст!" << endl;
					}
					system("pause");
					break;
				}
			} while (editChoice != 0);

			break;


		case 5:

			do {
				textSearchMenu();
				srchChoice = CheckNumbers();
				switch (srchChoice) {
				case 1:
					try
					{
						if (planeVect.empty()) throw 1;
						textSearchPlaneMenu();
						searchPlaneRecord();

					}
					catch (...)
					{
						cout << "Список самолётов пуст!" << endl;
					}
					system("pause");
					break;

				case 2:
					try
					{
						if (personVect.empty()) throw 1;
						textSearchPersonMenu();
						searchPersonRecord();

					}
					catch (...)
					{
						cout << "Список капитанов пуст!" << endl;
					}
					system("pause");
					break;
				}
			} while (srchChoice != 0);

			break;



		case 6:
			do {
				textSortMenu();
				sortChoice = CheckNumbers();
				switch (sortChoice) {
				case 1:
					try
					{
						if (planeVect.empty()) throw 1;
						textSortPlaneMenu();
						sortPlaneRecord();

					}
					catch (...)
					{
						cout << "Список самолётов пуст!" << endl;
					}
					system("pause");
					break;

				case 2:
					try
					{
						if (personVect.empty()) throw 1;
						textSortPersonMenu();
						sortPersonRecord();

					}
					catch (...)
					{
						cout << "Список капитанов пуст!" << endl;
					}
					system("pause");
					break;
				}
			} while (sortChoice != 0);

			break;

		case 7:
			viewCountries();
			break;
		case 8: 
			createXLSXReport();
			break;

		}


	} while (choiсe != 0);
	savePersonFile("Person.txt");
	savePlaneFile("Plane.txt");
}




