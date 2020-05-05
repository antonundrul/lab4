#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "libxl.h"
#include "functions.h"
#include "Plane.h"
#include "Person.h"
#include "CheckNumbersException.h"
#include "StringException.h"


extern vector<Plane*> planeVect;
extern vector<Person*> personVect;
extern map<string, int> newMap;
extern multimap<string, string> countries;


void createPlaneFile() {
	ofstream fPlane("Plane.txt", ofstream::app);
	if (!fPlane.is_open())
	{
		cout << "�� ������� �������/������� ���� Plane.txt" << endl;
	}
	fPlane.close();
}

void createPersonFile() {
	ofstream fPerson("Person.txt", ofstream::app);
	if (!fPerson.is_open())
	{
		cout << "�� ������� �������/������� ���� Person.txt" << endl;

	}
	fPerson.close();
}


int readPlaneFile(string file) {
	ifstream fin(file);
	Plane* plane = NULL;
	if (!fin.is_open()) {
		cout << "������ �������� �����." << endl;
	}
	else {
		cout << "���� Plane.txt ������." << endl;
		while (true)
		{
			plane = new Plane();
			fin >> *plane;
			if (fin.eof()) { delete plane; break; }
			planeVect.push_back(plane);
			countries.insert(make_pair(plane->getCountry(), plane->getModel()));

		}
	}
	fin.close();
	return 0;
}

int readPersonFile(string file) {
	ifstream fin(file);
	Person* person = NULL;
	if (!fin.is_open()) {
		cout << "������ �������� �����." << endl;
	}
	else {
		while (true)
		{
			person = new Person();
			fin >> *person;
			if (fin.eof()) { delete person; break; }
			personVect.push_back(person);

		}
	}
	fin.close();
	return 0;
}


int savePersonFile(string file) {
	ofstream fout(file, ios::trunc);
	for (int i = 0; i < personVect.size(); i++)
	{
		fout << *personVect[i];
	}
	fout.close();
	return 1;
}

int savePlaneFile(string file) {
	ofstream fout(file, ios::trunc);
	for (int i = 0; i < planeVect.size(); i++)
	{
		fout << *planeVect[i];

	}
	fout.close();
	return 1;
}


void textMainMenu() {

	system("cls");
	cout << "   ~~~~~����~~~~~" << endl;
	cout << "1.����������" << endl;
	cout << "2.��������" << endl;
	cout << "3.����� �� �����" << endl;
	cout << "4.��������������" << endl;
	cout << "5.�����" << endl;
	cout << "6.����������" << endl;
	cout << "7.C����� ����� �������������� " << endl;
	cout << "8.������� ����� � Excel" << endl;
	cout << "0.�����" << endl;
	cout << "��� ����� : ";
}


void textAddMenu() {

	system("cls");
	cout << "   ~~~~~����������~~~~~" << endl;
	cout << "1.�������� ������ � ��������" << endl;
	cout << "2.�������� ������ � ������" << endl;
	cout << "0.�����" << endl;
	cout << "��� ����� : ";

}


void textDelRecMenu() {

	system("cls");
	cout << "   ~~~~~��������~~~~~" << endl;
	cout << "1.������� ������ � ��������" << endl;
	cout << "2.������� ������ � ������" << endl;
	cout << "3.������� ��� ������" << endl;
	cout << "0.�����" << endl;
	cout << "��� ����� : ";

}


void textViewMenu() {

	system("cls");
	cout << "   ~~~~~�����~~~~~" << endl;
	cout << "1.������� ������ � ���������" << endl;
	cout << "2.������� ������ � �����ax" << endl;
	cout << "3.����� �������� � ���������� �������" << endl;
	cout << "0.�����" << endl;
	cout << "��� ����� : ";

}


void textEditMenu() {

	system("cls");
	cout << "   ~~~~~��������������~~~~~" << endl;
	cout << "1.������������� ������ � ��������" << endl;
	cout << "2.������������� ������ � ������" << endl;
	cout << "0.�����" << endl;
	cout << "��� ����� : ";

}

void textEditPlaneMenu() {
	system("cls");

	cout << "   ~~~~~�������������� ���������� � ��������~~~~~" << endl;
	cout << "1.�������������� ������ �������������" << endl;;
	cout << "2.�������������� �������� ������" << endl;
	cout << "3.�������������� ����" << endl;
	cout << "4.�������������� ������ ���������" << endl;
	cout << "5.�������������� �������� ���������" << endl;
	cout << "6.�������������� ���������� ����" << endl;
	cout << "7.�������������� ����� �����" << endl;
	cout << "8.�������������� ����� �����" << endl;
	cout << "9.�������������� ��������� �����" << endl;
	cout << "0.�����" << endl;
}

void textEditPersonMenu() {
	system("cls");

	cout << "   ~~~~~�������������� ���������� � �������~~~~~" << endl;
	cout << "1.�������������� �����" << endl;;
	cout << "2.�������������� �������" << endl;
	cout << "3.�������������� ��������" << endl;
	cout << "4.�������������� ������" << endl;
	cout << "5.�������������� �����" << endl;
	cout << "0.�����" << endl;
}


void textSearchMenu() {

	system("cls");
	cout << "   ~~~~~�����~~~~~" << endl;
	cout << "1.����� ������ � ��������" << endl;
	cout << "2.����� ������ � ������" << endl;
	cout << "0.�����" << endl;
	cout << "��� ����� : ";

}

void textSearchPlaneMenu() {
	system("cls");

	cout << "   ~~~~~����� ���������� � ��������~~~~~" << endl;
	cout << "1.����� �� ������ �������������" << endl;;
	cout << "2.����� �� �������� ������" << endl;
	cout << "0.�����" << endl;
}

void textSearchPersonMenu() {
	system("cls");

	cout << "   ~~~~~����� ���������� � �������~~~~~" << endl;
	cout << "1.����� �� �����" << endl;;
	cout << "2.����� �� �������" << endl;
	cout << "0.�����" << endl;
}


void textSortMenu() {

	system("cls");
	cout << "   ~~~~~����������~~~~~" << endl;
	cout << "1.���������� ������� � ��������" << endl;
	cout << "2.���������� ������� � ������" << endl;
	cout << "0.�����" << endl;
	cout << "��� ����� : ";

}

void textSortPlaneMenu() {
	system("cls");

	cout << "   ~~~~~���������� ���������� � ��������~~~~~" << endl;
	cout << "1.���������� �� ������ �������������" << endl;
	cout << "2.���������� �� �������� ������" << endl;
	cout << "3.���������� �� ���������� ���������� ����" << endl;
	cout << "4.���������� �� �������� ���������" << endl;
	cout << "0.�����" << endl;
}

void textSortPersonMenu() {
	system("cls");

	cout << "   ~~~~~���������� ���������� � �������~~~~~" << endl;
	cout << "1.���������� �� �����" << endl;;
	cout << "2.���������� �� �������" << endl;
	cout << "3.���������� �� ��������" << endl;
	cout << "4.���������� �� ������" << endl;
	cout << "5.���������� �� �����" << endl;
	cout << "0.�����" << endl;
}



void addPlaneRecord() {
	int choi�e = -1, places, num, power, i;
	string country, model, type, material;
	double volume, weight, length;
	Plane* plane;

	string nameModel;
	plane = new Plane();

	country = "";
	cout << "������� ������������� �������" << endl;
	cin >> country;// = stringCheck();
	plane->setCountry(country);

	model = "";
	cout << "������� �������� ������ �������" << endl;
	cin >> model;
	plane->setModel(model);

	weight = 0;
	cout << "������� ��� �������" << endl;
	weight = CheckNumbers();
	plane->setWeight(weight);

	volume = 0;
	cout << "������� ����� ��������� �������" << endl;
	volume = CheckNumbers();
	plane->setEngineVolume(volume);

	power = 0;
	cout << "������� �������� ��������� �������" << endl;
	power = CheckNumbers();
	plane->setEnginePower(power);

	places = 0;
	cout << "������� ���������� ���� � �������" << endl;
	places = CheckNumbers();
	plane->setAmountOfPlaces(places);

	type = "";
	cout << "������� ��� ����� �������" << endl;
	cin >> type;// = stringCheck();
	plane->setWingType(type);

	length = 0.0;
	cout << "������� ����� ����� �������" << endl;
	length = CheckNumbers();
	plane->setWingLength(length);

	material = "";
	cout << "������� �������� ����� �������" << endl;
	cin >> material;// = stringCheck();
	plane->setWingMaterial(material);

	planeVect.push_back(plane);
	countries.insert(make_pair(plane->getCountry(), plane->getModel()));
	savePlaneFile("Plane.txt");
	cout << "������ ������� ���������" << endl;
	system("pause");

}

void addPersonRecord() {
	Person* person;
	string name, surname, rank;
	int age, experience, majCount, podCount, polCount;
	person = new Person();

	name = "";
	cout << "������� ��� ������" << endl;
	getline(cin, name, '\n');
	person->setName(name);

	surname = "";
	cout << "������� ������� ������" << endl;
	getline(cin, surname, '\n');
	person->setSurname(surname);

	age = 0;
	cout << "������� ������� ������" << endl;
	age = CheckNumbers();
	person->setAge(age);


	cout << "�������� ������ ������: " << endl;
	person->showRank();
	int ch = -1;
	while (ch < 1 || ch > 3)
	{
		cout << "�������� �����: ";
		ch = CheckNumbers();
	}
	if (ch == 1) {
		rank = "Major";
		newMap["Major"]++;
	}
	else if (ch == 2) {
		rank = "Podpolkovnik";
		newMap["Podpolkovnik"]++;
	}
	else if (ch == 3) {
		rank = "Polkovnik";
		newMap["Polkovnik"]++;
	}
	person->setRank(rank);


	experience = 0;
	cout << "������� ���� ������" << endl;
	experience = CheckNumbers();
	person->setExperience(experience);

	personVect.push_back(person);
	savePersonFile("Person.txt");
	cout << "������ ������� ���������" << endl;
	system("pause");
}


void delPlaneRecord() {
	int i, num;
	system("cls");
	cout << "������ ��������:" << endl;
	i = 0;
	for (vector <Plane*>::iterator it = planeVect.begin(); it != planeVect.end(); ++it, ++i)
	{
		cout << i << endl << "�������������: " << (*it)->getCountry() << endl
			<< "������: " << (*it)->getModel() << endl << endl;
	}
	cout << "������� ����� ������������� ��������, ������� �� ������ �������: " << endl;
	num = CheckNumbers();
	
			countries.erase(planeVect.at(num)->getModel());
	planeVect.erase(planeVect.begin() + num);
	cout << "������ �����" << endl;
	savePlaneFile("Plane.txt");

	system("pause");
}

void delPersonRecord() {
	int i, num;
	system("cls");
	cout << "������ �������:" << endl;
	i = 0;
	for (vector <Person*>::iterator it = personVect.begin(); it != personVect.end(); ++it, ++i)
	{
		cout << i << endl << "���: " << (*it)->getName() << endl
			<< "�������: " << (*it)->getSurname() << endl << "������: " << (*it)->getRank() << endl;
	}
	cout << "������� ����� ������, ������ � ������� �� ������ �������: " << endl;
	num = CheckNumbers();
	personVect.erase(personVect.begin() + num);
	cout << "������ � ������ �������" << endl;
	savePersonFile("Person.txt");

	system("pause");
}

void delAllRecords() {
	system("cls");
	planeVect.clear();
	countries.clear();
	personVect.clear();
	newMap.clear();
	cout << "������ �������!" << endl;
	savePlaneFile("Plane.txt");
	savePersonFile("Person.txt");
	system("pause");

}


void viewPlaneRecord() {

	cout << "������ ��������:" << endl;
	cout << " ____________________________________________________________________________________________________________________________________________________" << endl;
	cout << "| ������ �������������: " << setw(10) << "| ������ �������: " << setw(7) << "| ���: " << setw(5) << "| ����� ���������: " << setw(5) <<
		"|�������� ���������: " << setw(5) << "| ��������� ����: " << setw(5) << "| ��� �����: " << setw(5) << " | ����� �����: " << setw(5) << "| ��������:|" << endl;
	cout << " ____________________________________________________________________________________________________________________________________________________" << endl;

	for (auto i : planeVect)
	{

		cout << left << "|" << setw(23) << i->getCountry() << "|" << setw(18) << i->getModel() << "|" << setw(6) << i->getWeight()
			<< "|" << setw(18) << i->getEngineVolume() << "|" << setw(20) << i->getEnginePower() << "|" << setw(17) << i->getAmountOfPlaces()
			<< "|" << setw(13) << i->getWingType() << "|" << setw(14) << i->getWingLength() << "|" << setw(9) << i->getWingMaterial() << " |" << endl;
		cout << " ____________________________________________________________________________________________________________________________________________________" << endl;

	}
}

void viewPersonRecord() {

	cout << "������ �������:" << endl;
	cout << " ______________________________________________________________" << endl;
	cout << "|   ���:   " << setw(15) << "|    �������:   " << setw(10) << "| �������: " << setw(15) << "|    ������:    " << setw(7) <<
		"| ����: |" << endl;
	cout << " ______________________________________________________________" << endl;

	for (auto i : personVect)
	{

		cout << left << "|" << setw(10) << i->getName() << "|" << setw(15) << i->getSurname() << "|" << setw(10) << i->getAge()
			<< "|" << setw(15) << i->getRank() << "|" << setw(7) << i->getExperience() << "|" << endl;
		cout << " ______________________________________________________________" << endl;

	}
}


void editPlaneRecord() {

	bool isFlag = false;
	string namePlaneTemp;
	int idPlane = -1;
	viewPlaneRecord();
	cout << "������� �������� �������, ������ � ������� �� ������ ��������: ";
	cin >> namePlaneTemp;
	for (int i = 0; i < planeVect.size(); i++)
	{
		if (namePlaneTemp == planeVect[i]->getModel())
		{
			idPlane = i;

		}
	}

	if (idPlane == -1)
	{
		cout << "������� � ����� ��������� ���. " << endl;
		system("pause");
	}
	else
	{

		int k = 0;

		int choi�e = -1, places, num, power, i;
		string country, model, type, material;
		double volume, weight, length;
		Plane* plane;

		do {
			textEditPlaneMenu();
			cout << "��� �����: ";
			int choice = CheckNumbers();
			switch (choice) {
			case 1:
				system("cls");
				cout << "��������� ������ �������������" << endl;
				cout << "����� ������ �������������: ";
				cin >> country;// = stringCheck();
				planeVect[idPlane]->setCountry(country);

				break;

			case 2:
				system("cls");
				cout << "��������� �������� ������ ������� " << endl;
				cout << "����� ������ : ";

				cin >> model;
				planeVect[idPlane]->setModel(model);
				break;

			case 3:
				system("cls");
				cout << "��������� ���� ������� " << endl;
				cout << "����� ��� �������(� ������): ";
				weight = CheckNumbers();
				planeVect[idPlane]->setWeight(weight);
				break;

			case 4:
				system("cls");
				cout << "��������� ������ ��������� " << endl;
				cout << "����� ����� ���������: ";
				volume = CheckNumbers();
				planeVect[idPlane]->setEngineVolume(volume);
				break;

			case 5:
				system("cls");
				cout << "��������� �������� ��������� " << endl;
				cout << "����� �������� ���������: ";
				power = CheckNumbers();
				planeVect[idPlane]->setEnginePower(power);
				break;

			case 6:
				system("cls");
				cout << "��������� ���������� ���������� ���� " << endl;
				cout << "����� ���������� ���������� ����: ";
				places = CheckNumbers();
				planeVect[idPlane]->setAmountOfPlaces(places);
				break;

			case 7:
				system("cls");
				cout << "��������� ���� ����� ������� " << endl;
				cout << "����� ��� �����: ";
				cin >> type;// = stringCheck();
				planeVect[idPlane]->setWingType(type);
				break;

			case 8:
				system("cls");
				cout << "��������� ����� ����� ������� " << endl;
				cout << "����� �����  �����: ";
				length = CheckNumbers();
				planeVect[idPlane]->setWingLength(length);
				break;

			case 9:
				system("cls");
				cout << "��������� ��������� ����� ������� " << endl;
				cout << "����� �������� �����: ";
				cin >> material;// = stringCheck();
				planeVect[idPlane]->setWingMaterial(material);
				break;

			case 0:
				k = -1;
				break;
			}
		} while (k == 0);
	}

	savePlaneFile("Plane.txt");
	system("pause");

}

void editPersonRecord() {

	bool isFlag = false;
	string namePersonTemp;
	int idPerson = -1;
	viewPersonRecord();
	cout << "������� ������� ������, ������ � ������� �� ������ ��������: ";
	cin >> namePersonTemp;
	for (int i = 0; i < personVect.size(); i++)
	{
		if (namePersonTemp == personVect[i]->getSurname())
		{
			idPerson = i;

		}
	}

	if (idPerson == -1)
	{
		cout << "������ � ����� �������� ���. " << endl;
		system("pause");
	}
	else
	{

		int k = 0;

		Person* person;
		string name, surname, rank;
		int age, experience;
		int ch = -1;
		do {
			textEditPersonMenu();
			cout << "��� �����: ";
			int choice = CheckNumbers();
			switch (choice) {
			case 1:
				system("cls");
				cout << "��������� �����" << endl;
				cout << "����� ���: ";
				name = stringCheck();
				personVect[idPerson]->setName(name);

				break;

			case 2:
				system("cls");
				cout << "��������� ������� " << endl;
				cout << "����� ������� : ";

				cin >> surname;
				personVect[idPerson]->setSurname(surname);
				break;

			case 3:
				system("cls");
				cout << "��������� ��������" << endl;
				cout << "����� �������: ";
				age = CheckNumbers();
				personVect[idPerson]->setAge(age);
				break;

			case 4:
				system("cls");
				cout << "��������� ������ " << endl;
				cout << "�������� ����� ������ ������: " << endl;
				personVect[idPerson]->showRank();
				ch = -1;
				while (ch < 1 || ch > 3)
				{
					cout << "�������� �����: ";
					ch = CheckNumbers();
				}
				if (ch == 1) rank = "�����";
				else if (ch == 2) rank = "������������";
				else if (ch == 3) rank = "���������";
				personVect[idPerson]->setRank(rank);
				break;

			case 5:
				system("cls");
				cout << "��������� ����� " << endl;
				cout << "����� ����: ";
				experience = CheckNumbers();
				personVect[idPerson]->setExperience(experience);
				break;



			case 0:
				k = -1;
				break;
			}
		} while (k == 0);
	}

	savePersonFile("Person.txt");
	system("pause");

}


void searchPlaneRecord() {

	int k = 0;
	bool isFlag = true;
	string nameModel, srchCountry;
	do {
		textSearchPlaneMenu();
		cout << "��� �����: ";
		int choice = CheckNumbers();
		switch (choice) {
		case 1:
			cout << "  ������� ������ ������������� �������, ������� �� ������ �����: ";
			cin >> srchCountry;// = stringCheck();

			system("cls");
			cout << " ____________________________________________________________________________________________________________________________________________________" << endl;
			cout << "| ������ �������������: " << setw(10) << "| ������ �������: " << setw(7) << "| ���: " << setw(5) << "| ����� ���������: " << setw(5) <<
				"|�������� ���������: " << setw(5) << "| ��������� ����: " << setw(5) << "| ��� �����: " << setw(5) << " | ����� �����: " << setw(5) << "| ��������:|" << endl;
			cout << " ____________________________________________________________________________________________________________________________________________________" << endl;
			isFlag = true;
			for (auto i : planeVect)
			{
				if (srchCountry == i->getCountry())
				{

					cout << left << "|" << setw(23) << i->getCountry() << "|" << setw(18) << i->getModel() << "|" << setw(6) << i->getWeight()
						<< "|" << setw(18) << i->getEngineVolume() << "|" << setw(20) << i->getEnginePower() << "|" << setw(17) << i->getAmountOfPlaces()
						<< "|" << setw(13) << i->getWingType() << "|" << setw(14) << i->getWingLength() << "|" << setw(9) << i->getWingMaterial() << " |" << endl;
					cout << " ____________________________________________________________________________________________________________________________________________________" << endl;

					isFlag = false;

				}

			}
			if (isFlag == true)
			{
				cout << "�� ������ ������� ������ �� �������." << endl;
			}

			system("pause");
			break;


		case 2:
			cout << "  ������� ������ �������, ������� �� ������ �����: ";
			cin >> nameModel;// = stringCheck();

			system("cls");
			cout << " ____________________________________________________________________________________________________________________________________________________" << endl;
			cout << "| ������ �������������: " << setw(10) << "| ������ �������: " << setw(7) << "| ���: " << setw(5) << "| ����� ���������: " << setw(5) <<
				"|�������� ���������: " << setw(5) << "| ��������� ����: " << setw(5) << "| ��� �����: " << setw(5) << " | ����� �����: " << setw(5) << "| ��������:|" << endl;
			cout << " ____________________________________________________________________________________________________________________________________________________" << endl;
			isFlag = true;
			for (auto i : planeVect)
			{
				if (nameModel == i->getModel())
				{

					cout << left << "|" << setw(23) << i->getCountry() << "|" << setw(18) << i->getModel() << "|" << setw(6) << i->getWeight()
						<< "|" << setw(18) << i->getEngineVolume() << "|" << setw(20) << i->getEnginePower() << "|" << setw(17) << i->getAmountOfPlaces()
						<< "|" << setw(13) << i->getWingType() << "|" << setw(14) << i->getWingLength() << "|" << setw(9) << i->getWingMaterial() << " |" << endl;
					cout << " ____________________________________________________________________________________________________________________________________________________" << endl;

					isFlag = false;

				}

			}
			if (isFlag == true)
			{
				cout << "�� ������ ������� ������ �� �������." << endl;
			}

			system("pause");
			break;
		case 0:
			k = -1;
			break;
		}
	} while (k == 0);
}

void searchPersonRecord() {

	int k = 0;
	bool isFlag = true;
	string srchName, srchSurname;
	do {
		textSearchPersonMenu();
		cout << "��� �����: ";
		int choice = CheckNumbers();
		switch (choice) {
		case 1:
			cout << "  ������� ��� ������, �������� �� ������ �����: ";
			cin >> srchName;// = stringCheck();

			system("cls");
			cout << "������ �������:" << endl;
			cout << " ______________________________________________________________" << endl;
			cout << "|   ���:   " << setw(15) << "|    �������:   " << setw(10) << "| �������: " << setw(15) << "|    ������:    " << setw(7) <<
				"| ����: |" << endl;
			cout << " ______________________________________________________________" << endl;
			isFlag = true;
			for (auto i : personVect)
			{
				if (srchName == i->getName())
				{

					cout << left << "|" << setw(10) << i->getName() << "|" << setw(15) << i->getSurname() << "|" << setw(10) << i->getAge()
						<< "|" << setw(15) << i->getRank() << "|" << setw(7) << i->getExperience() << "|" << endl;
					cout << " ______________________________________________________________" << endl;

					isFlag = false;

				}

			}
			if (isFlag == true)
			{
				cout << "�� ������ ������� ������ �� �������." << endl;
			}

			system("pause");
			break;


		case 2:
			cout << "  ������� ������� ������, �������� �� ������ �����: ";
			cin >> srchSurname;// = stringCheck();

			system("cls");
			cout << "������ �������:" << endl;
			cout << " ______________________________________________________________" << endl;
			cout << "|   ���:   " << setw(15) << "|    �������:   " << setw(10) << "| �������: " << setw(15) << "|    ������:    " << setw(7) <<
				"| ����: |" << endl;
			cout << " ______________________________________________________________" << endl;
			isFlag = true;
			for (auto i : personVect)
			{
				if (srchSurname == i->getSurname())
				{

					cout << left << "|" << setw(10) << i->getName() << "|" << setw(15) << i->getSurname() << "|" << setw(10) << i->getAge()
						<< "|" << setw(15) << i->getRank() << "|" << setw(7) << i->getExperience() << "|" << endl;
					cout << " ______________________________________________________________" << endl;

					isFlag = false;

				}

			}
			if (isFlag == true)
			{
				cout << "�� ������ ������� ������ �� �������." << endl;
			}

			system("pause");
			break;




		case 0:
			k = -1;
			break;
		}
	} while (k == 0);
}


void sortPlaneRecord() {

	int k = 0;
	bool isFlag = true;
	do {
		textSortPlaneMenu();
		cout << "��� �����: ";
		int choice = CheckNumbers();
		switch (choice) {
		case 1:
			for (int k = 0; k < planeVect.size(); k++) {
				for (int i = 0; i < planeVect.size() - k - 1; i++)
				{
					if (planeVect[i]->getCountry() > planeVect[i + 1]->getCountry())
					{
						swap(planeVect[i], planeVect[i + 1]);
					}
				}
			}

			viewPlaneRecord();
			system("pause");
			break;

		case 2:
			for (int k = 0; k < planeVect.size(); k++) {
				for (int i = 0; i < planeVect.size() - k - 1; i++)
				{
					if (planeVect[i]->getModel() > planeVect[i + 1]->getModel())
					{
						swap(planeVect[i], planeVect[i + 1]);
					}
				}
			}

			viewPlaneRecord();
			system("pause");
			break;

		case 3:
			for (int k = 0; k < planeVect.size(); k++) {
				for (int i = 0; i < planeVect.size() - k - 1; i++)
				{
					if (planeVect[i]->getAmountOfPlaces() > planeVect[i + 1]->getAmountOfPlaces())
					{
						swap(planeVect[i], planeVect[i + 1]);
					}
				}
			}

			viewPlaneRecord();
			system("pause");
			break;

		case 4:
			for (int k = 0; k < planeVect.size(); k++) {
				for (int i = 0; i < planeVect.size() - k - 1; i++)
				{
					if (planeVect[i]->getEnginePower() > planeVect[i + 1]->getEnginePower())
					{
						swap(planeVect[i], planeVect[i + 1]);
					}
				}
			}

			viewPlaneRecord();
			system("pause");
			break;
		case 0:
			k = -1;
			break;
		}
	} while (k == 0);
}

void sortPersonRecord() {

	int k = 0;
	bool isFlag = true;
	do {
		textSortPersonMenu();
		cout << "��� �����: ";
		int choice = CheckNumbers();
		switch (choice) {
		case 1:
			for (int k = 0; k < personVect.size(); k++) {
				for (int i = 0; i < personVect.size() - k - 1; i++)
				{
					if (personVect[i]->getName() > personVect[i + 1]->getName())
					{
						swap(personVect[i], personVect[i + 1]);
					}
				}
			}

			viewPersonRecord();
			system("pause");
			break;

		case 2:
			for (int k = 0; k < personVect.size(); k++) {
				for (int i = 0; i < personVect.size() - k - 1; i++)
				{
					if (personVect[i]->getSurname() > personVect[i + 1]->getSurname())
					{
						swap(personVect[i], personVect[i + 1]);
					}
				}
			}

			viewPersonRecord();
			system("pause");
			break;

		case 3:
			for (int k = 0; k < personVect.size(); k++) {
				for (int i = 0; i < personVect.size() - k - 1; i++)
				{
					if (personVect[i]->getAge() > personVect[i + 1]->getAge())
					{
						swap(personVect[i], personVect[i + 1]);
					}
				}
			}

			viewPersonRecord();
			system("pause");
			break;

		case 4:
			for (int k = 0; k < personVect.size(); k++) {
				for (int i = 0; i < personVect.size() - k - 1; i++)
				{
					if (personVect[i]->getRank() > personVect[i + 1]->getRank())
					{
						swap(personVect[i], personVect[i + 1]);
					}
				}
			}

			viewPersonRecord();
			system("pause");
			break;

		case 5:
			for (int k = 0; k < personVect.size(); k++) {
				for (int i = 0; i < personVect.size() - k - 1; i++)
				{
					if (personVect[i]->getExperience() > personVect[i + 1]->getExperience())
					{
						swap(personVect[i], personVect[i + 1]);
					}
				}
			}

			viewPersonRecord();
			system("pause");
			break;
		case 0:
			k = -1;
			break;
		}
	} while (k == 0);
}


void viewCountries() {
	
	cout << " _____________________________" << endl;
	cout << "|   ������:   " << setw(14) << "|    ������:   |" << endl;
	cout << " _____________________________" << endl;

	for (auto i : countries)
	{

		cout << left << "|" << setw(13) << i.first << "|" << setw(14) << i.second << "|" << endl;
		cout << " _____________________________" << endl;

	}
	system("pause");

}

wstring to_wstring(string const& str)
{
	size_t len = mbstowcs(nullptr, &str[0], 0);
	if (len == -1); // invalid source str, throw
	wstring wstr(len, 0);
	mbstowcs(&wstr[0], &str[0], wstr.size());
	return wstr;
}

void createXLSXReport()
{
	Book* book = xlCreateXMLBook();
	Sheet* sheet1 = book->addSheet(L"�������");
	Sheet* sheet2 = book->addSheet(L"������");
	Sheet* sheet3 = book->addSheet(L"������");
	Sheet* sheet4 = book->addSheet(L"������");

	sheet1->writeStr(1, 0, L"�������������");
	sheet1->writeStr(1, 1, L"������");
	sheet1->writeStr(1, 2, L"���");
	sheet1->writeStr(1, 3, L"����� ���������");
	sheet1->writeStr(1, 4, L"�������� ���������");
	sheet1->writeStr(1, 5, L"���-�� ����");
	sheet1->writeStr(1, 6, L"��� �����");
	sheet1->writeStr(1, 7, L"����� �����");
	sheet1->writeStr(1, 8, L"��������");

	sheet2->writeStr(1, 0, L"���");
	sheet2->writeStr(1, 1, L"�������");
	sheet2->writeStr(1, 2, L"�������");
	sheet2->writeStr(1, 3, L"������");
	sheet2->writeStr(1, 4, L"����");

	sheet3->writeStr(1, 0, L"������");
	sheet3->writeStr(1, 1, L"����������");

	sheet4->writeStr(1, 0, L"������");
	sheet4->writeStr(1, 1, L"������ ��������");

	

	int row = 2;
	for (auto i : planeVect){
		sheet1->writeStr(row, 0, to_wstring(i->getCountry()).c_str());
		sheet1->writeStr(row, 1, to_wstring(i->getModel()).c_str());
		sheet1->writeNum(row, 2, i->getWeight());
		sheet1->writeNum(row, 3, i->getEngineVolume());
		sheet1->writeNum(row, 4, i->getEnginePower());
		sheet1->writeNum(row, 5, i->getAmountOfPlaces());
		sheet1->writeStr(row, 6, to_wstring(i->getWingType()).c_str());
		sheet1->writeNum(row, 7, i->getWingLength());
		sheet1->writeStr(row, 8, to_wstring(i->getWingMaterial()).c_str());
		++row;
	}
	sheet1->setAutoFitArea();

	row = 2;
	for (auto i : personVect) {
	
		sheet2->writeStr(row, 0, to_wstring(i->getName()).c_str());
		sheet2->writeStr(row, 1, to_wstring(i->getSurname()).c_str());
		sheet2->writeNum(row, 2, i->getAge());
		sheet2->writeStr(row, 3, to_wstring(i->getRank()).c_str());
		sheet2->writeNum(row, 4, i->getExperience());
		++row;
	}
	sheet2->setAutoFitArea();

	row = 2;
	for (auto i : newMap){

		sheet3->writeStr(row, 0, to_wstring(i.first).c_str());
		sheet3->writeNum(row, 1, i.second);
		++row;
	}
	sheet3->setAutoFitArea();
	

	row = 2;
	for (auto i : countries)
	{
		sheet4->writeStr(row, 0, to_wstring(i.first).c_str());
		sheet4->writeStr(row, 1, to_wstring(i.second).c_str());
		++row;
	}
	sheet4->setAutoFitArea();
	
	wstring ws = to_wstring("Report") + L".xlsx";
	book->save(ws.c_str());
	book->release();
	system("\"Report.xlsx\"");
}

