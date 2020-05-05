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
		cout << "Не удалось создать/открыть файл Plane.txt" << endl;
	}
	fPlane.close();
}

void createPersonFile() {
	ofstream fPerson("Person.txt", ofstream::app);
	if (!fPerson.is_open())
	{
		cout << "Не удалось создать/открыть файл Person.txt" << endl;

	}
	fPerson.close();
}


int readPlaneFile(string file) {
	ifstream fin(file);
	Plane* plane = NULL;
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла." << endl;
	}
	else {
		cout << "Файл Plane.txt открыт." << endl;
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
		cout << "Ошибка открытия файла." << endl;
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
	cout << "   ~~~~~Меню~~~~~" << endl;
	cout << "1.Добавление" << endl;
	cout << "2.Удаление" << endl;
	cout << "3.Вывод на экран" << endl;
	cout << "4.Редактирование" << endl;
	cout << "5.Поиск" << endl;
	cout << "6.Сортировка" << endl;
	cout << "7.Cписок стран производителей " << endl;
	cout << "8.Сделать отчет в Excel" << endl;
	cout << "0.Выход" << endl;
	cout << "Ваш выбор : ";
}


void textAddMenu() {

	system("cls");
	cout << "   ~~~~~Добавление~~~~~" << endl;
	cout << "1.Добавить запись о самолете" << endl;
	cout << "2.Добавить запись о пилоте" << endl;
	cout << "0.Выход" << endl;
	cout << "Ваш выбор : ";

}


void textDelRecMenu() {

	system("cls");
	cout << "   ~~~~~Удаление~~~~~" << endl;
	cout << "1.Удалить запись о самолете" << endl;
	cout << "2.Удалить запись о пилоте" << endl;
	cout << "3.Удалить все записи" << endl;
	cout << "0.Выход" << endl;
	cout << "Ваш выбор : ";

}


void textViewMenu() {

	system("cls");
	cout << "   ~~~~~Вывод~~~~~" << endl;
	cout << "1.Вывести записи о самолетах" << endl;
	cout << "2.Вывести записи о пилотax" << endl;
	cout << "3.Вывод сведений о количестве пилотов" << endl;
	cout << "0.Выход" << endl;
	cout << "Ваш выбор : ";

}


void textEditMenu() {

	system("cls");
	cout << "   ~~~~~Редактирование~~~~~" << endl;
	cout << "1.Редактировать запись о самолете" << endl;
	cout << "2.Редактировать запись о пилоте" << endl;
	cout << "0.Выход" << endl;
	cout << "Ваш выбор : ";

}

void textEditPlaneMenu() {
	system("cls");

	cout << "   ~~~~~Редактирование информации о самолётах~~~~~" << endl;
	cout << "1.Редактирование страны производителя" << endl;;
	cout << "2.Редактирование названия модели" << endl;
	cout << "3.Редактирование веса" << endl;
	cout << "4.Редактирование объёма двигателя" << endl;
	cout << "5.Редактирование мощности двигателя" << endl;
	cout << "6.Редактирование количества мест" << endl;
	cout << "7.Редактирование формы крыла" << endl;
	cout << "8.Редактирование длины крыла" << endl;
	cout << "9.Редактирование материала крыла" << endl;
	cout << "0.Назад" << endl;
}

void textEditPersonMenu() {
	system("cls");

	cout << "   ~~~~~Редактирование информации о пилотах~~~~~" << endl;
	cout << "1.Редактирование имени" << endl;;
	cout << "2.Редактирование фамилии" << endl;
	cout << "3.Редактирование возраста" << endl;
	cout << "4.Редактирование звания" << endl;
	cout << "5.Редактирование стажа" << endl;
	cout << "0.Назад" << endl;
}


void textSearchMenu() {

	system("cls");
	cout << "   ~~~~~Поиск~~~~~" << endl;
	cout << "1.Поиск записи о самолете" << endl;
	cout << "2.Поиск записи о пилоте" << endl;
	cout << "0.Выход" << endl;
	cout << "Ваш выбор : ";

}

void textSearchPlaneMenu() {
	system("cls");

	cout << "   ~~~~~Поиск информации о самолётах~~~~~" << endl;
	cout << "1.Поиск по стране производителя" << endl;;
	cout << "2.Поиск по названию модели" << endl;
	cout << "0.Назад" << endl;
}

void textSearchPersonMenu() {
	system("cls");

	cout << "   ~~~~~Поиск информации о пилотах~~~~~" << endl;
	cout << "1.Поиск по имени" << endl;;
	cout << "2.Поиск по фамилии" << endl;
	cout << "0.Назад" << endl;
}


void textSortMenu() {

	system("cls");
	cout << "   ~~~~~Сортировка~~~~~" << endl;
	cout << "1.Сортировка записей о самолете" << endl;
	cout << "2.Сортировка записей о пилоте" << endl;
	cout << "0.Выход" << endl;
	cout << "Ваш выбор : ";

}

void textSortPlaneMenu() {
	system("cls");

	cout << "   ~~~~~Сортировка информации о самолётах~~~~~" << endl;
	cout << "1.Сортировка по стране производителя" << endl;
	cout << "2.Сортировка по названию модели" << endl;
	cout << "3.Сортировка по количеству посадочных мест" << endl;
	cout << "4.Сортировка по мощности двигателя" << endl;
	cout << "0.Назад" << endl;
}

void textSortPersonMenu() {
	system("cls");

	cout << "   ~~~~~Сортировка информации о пилотах~~~~~" << endl;
	cout << "1.Сортировка по имени" << endl;;
	cout << "2.Сортировка по фамилии" << endl;
	cout << "3.Сортировка по возрасту" << endl;
	cout << "4.Сортировка по званию" << endl;
	cout << "5.Сортировка по стажу" << endl;
	cout << "0.Назад" << endl;
}



void addPlaneRecord() {
	int choiсe = -1, places, num, power, i;
	string country, model, type, material;
	double volume, weight, length;
	Plane* plane;

	string nameModel;
	plane = new Plane();

	country = "";
	cout << "Введите производителя самолёта" << endl;
	cin >> country;// = stringCheck();
	plane->setCountry(country);

	model = "";
	cout << "Введите название модели самолёта" << endl;
	cin >> model;
	plane->setModel(model);

	weight = 0;
	cout << "Введите вес самолёта" << endl;
	weight = CheckNumbers();
	plane->setWeight(weight);

	volume = 0;
	cout << "Введите объём двигателя самолёта" << endl;
	volume = CheckNumbers();
	plane->setEngineVolume(volume);

	power = 0;
	cout << "Введите мощность двигателя самолёта" << endl;
	power = CheckNumbers();
	plane->setEnginePower(power);

	places = 0;
	cout << "Введите количество мест в самолёте" << endl;
	places = CheckNumbers();
	plane->setAmountOfPlaces(places);

	type = "";
	cout << "Введите тип крыла самолёта" << endl;
	cin >> type;// = stringCheck();
	plane->setWingType(type);

	length = 0.0;
	cout << "Введите длину крыла самолёта" << endl;
	length = CheckNumbers();
	plane->setWingLength(length);

	material = "";
	cout << "Введите материал крыла самолёта" << endl;
	cin >> material;// = stringCheck();
	plane->setWingMaterial(material);

	planeVect.push_back(plane);
	countries.insert(make_pair(plane->getCountry(), plane->getModel()));
	savePlaneFile("Plane.txt");
	cout << "Запись успешно добавлена" << endl;
	system("pause");

}

void addPersonRecord() {
	Person* person;
	string name, surname, rank;
	int age, experience, majCount, podCount, polCount;
	person = new Person();

	name = "";
	cout << "Введите имя пилота" << endl;
	getline(cin, name, '\n');
	person->setName(name);

	surname = "";
	cout << "Введите фамилию пилота" << endl;
	getline(cin, surname, '\n');
	person->setSurname(surname);

	age = 0;
	cout << "Введите возраст пилота" << endl;
	age = CheckNumbers();
	person->setAge(age);


	cout << "Выберите звание пилота: " << endl;
	person->showRank();
	int ch = -1;
	while (ch < 1 || ch > 3)
	{
		cout << "Сделайте выбор: ";
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
	cout << "Введите стаж пилота" << endl;
	experience = CheckNumbers();
	person->setExperience(experience);

	personVect.push_back(person);
	savePersonFile("Person.txt");
	cout << "Запись успешно добавлена" << endl;
	system("pause");
}


void delPlaneRecord() {
	int i, num;
	system("cls");
	cout << "Список самолётов:" << endl;
	i = 0;
	for (vector <Plane*>::iterator it = planeVect.begin(); it != planeVect.end(); ++it, ++i)
	{
		cout << i << endl << "Производитель: " << (*it)->getCountry() << endl
			<< "Модель: " << (*it)->getModel() << endl << endl;
	}
	cout << "Введите номер производителя самолета, который вы хотите удалить: " << endl;
	num = CheckNumbers();
	
			countries.erase(planeVect.at(num)->getModel());
	planeVect.erase(planeVect.begin() + num);
	cout << "Самолёт удалён" << endl;
	savePlaneFile("Plane.txt");

	system("pause");
}

void delPersonRecord() {
	int i, num;
	system("cls");
	cout << "Список пилотов:" << endl;
	i = 0;
	for (vector <Person*>::iterator it = personVect.begin(); it != personVect.end(); ++it, ++i)
	{
		cout << i << endl << "Имя: " << (*it)->getName() << endl
			<< "Фамилия: " << (*it)->getSurname() << endl << "Звание: " << (*it)->getRank() << endl;
	}
	cout << "Введите номер пилота, запись о котором вы хотите удалить: " << endl;
	num = CheckNumbers();
	personVect.erase(personVect.begin() + num);
	cout << "Запись о пилоте удалена" << endl;
	savePersonFile("Person.txt");

	system("pause");
}

void delAllRecords() {
	system("cls");
	planeVect.clear();
	countries.clear();
	personVect.clear();
	newMap.clear();
	cout << "Данные удалены!" << endl;
	savePlaneFile("Plane.txt");
	savePersonFile("Person.txt");
	system("pause");

}


void viewPlaneRecord() {

	cout << "Список самолётов:" << endl;
	cout << " ____________________________________________________________________________________________________________________________________________________" << endl;
	cout << "| Страна производитель: " << setw(10) << "| Модель самолёта: " << setw(7) << "| Вес: " << setw(5) << "| Объём двигателя: " << setw(5) <<
		"|Мощность двигателя: " << setw(5) << "| Количство мест: " << setw(5) << "| Тип крыла: " << setw(5) << " | Длина крыла: " << setw(5) << "| Материал:|" << endl;
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

	cout << "Список пилотов:" << endl;
	cout << " ______________________________________________________________" << endl;
	cout << "|   Имя:   " << setw(15) << "|    Фамилия:   " << setw(10) << "| Возраст: " << setw(15) << "|    Звание:    " << setw(7) <<
		"| Стаж: |" << endl;
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
	cout << "Введите название самолёта, данные о котором вы хотите изменить: ";
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
		cout << "Самолёта с таким названием нет. " << endl;
		system("pause");
	}
	else
	{

		int k = 0;

		int choiсe = -1, places, num, power, i;
		string country, model, type, material;
		double volume, weight, length;
		Plane* plane;

		do {
			textEditPlaneMenu();
			cout << "Ваш выбор: ";
			int choice = CheckNumbers();
			switch (choice) {
			case 1:
				system("cls");
				cout << "Изменение страны производителя" << endl;
				cout << "Новая страна производитель: ";
				cin >> country;// = stringCheck();
				planeVect[idPlane]->setCountry(country);

				break;

			case 2:
				system("cls");
				cout << "Изменение названия модели самолёта " << endl;
				cout << "Новая модель : ";

				cin >> model;
				planeVect[idPlane]->setModel(model);
				break;

			case 3:
				system("cls");
				cout << "Изменение веса самолёта " << endl;
				cout << "Новый вес самолёта(в тоннах): ";
				weight = CheckNumbers();
				planeVect[idPlane]->setWeight(weight);
				break;

			case 4:
				system("cls");
				cout << "Изменение объёма двигателя " << endl;
				cout << "Новый объём двигателя: ";
				volume = CheckNumbers();
				planeVect[idPlane]->setEngineVolume(volume);
				break;

			case 5:
				system("cls");
				cout << "Изменение мощности двигателя " << endl;
				cout << "Новая мощность двигателя: ";
				power = CheckNumbers();
				planeVect[idPlane]->setEnginePower(power);
				break;

			case 6:
				system("cls");
				cout << "Изменение количества посадочных мест " << endl;
				cout << "Новое количество посадочных мест: ";
				places = CheckNumbers();
				planeVect[idPlane]->setAmountOfPlaces(places);
				break;

			case 7:
				system("cls");
				cout << "Изменение типа крыла самолёта " << endl;
				cout << "Новый тип крыла: ";
				cin >> type;// = stringCheck();
				planeVect[idPlane]->setWingType(type);
				break;

			case 8:
				system("cls");
				cout << "Изменение длины крыла самолёта " << endl;
				cout << "Новая длина  крыла: ";
				length = CheckNumbers();
				planeVect[idPlane]->setWingLength(length);
				break;

			case 9:
				system("cls");
				cout << "Изменение материала крыла самолёта " << endl;
				cout << "Новый материал крыла: ";
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
	cout << "Введите фамилию пилота, данные о котором вы хотите изменить: ";
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
		cout << "Пилота с такой фамилией нет. " << endl;
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
			cout << "Ваш выбор: ";
			int choice = CheckNumbers();
			switch (choice) {
			case 1:
				system("cls");
				cout << "Изменение имени" << endl;
				cout << "Новое имя: ";
				name = stringCheck();
				personVect[idPerson]->setName(name);

				break;

			case 2:
				system("cls");
				cout << "Изменение фамилии " << endl;
				cout << "Новая фамилия : ";

				cin >> surname;
				personVect[idPerson]->setSurname(surname);
				break;

			case 3:
				system("cls");
				cout << "Изменение возраста" << endl;
				cout << "Новый возраст: ";
				age = CheckNumbers();
				personVect[idPerson]->setAge(age);
				break;

			case 4:
				system("cls");
				cout << "Изменение звания " << endl;
				cout << "Выберите новое звание пилота: " << endl;
				personVect[idPerson]->showRank();
				ch = -1;
				while (ch < 1 || ch > 3)
				{
					cout << "Сделайте выбор: ";
					ch = CheckNumbers();
				}
				if (ch == 1) rank = "Майор";
				else if (ch == 2) rank = "Подполковник";
				else if (ch == 3) rank = "Полковник";
				personVect[idPerson]->setRank(rank);
				break;

			case 5:
				system("cls");
				cout << "Изменение стажа " << endl;
				cout << "Новый стаж: ";
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
		cout << "Ваш выбор: ";
		int choice = CheckNumbers();
		switch (choice) {
		case 1:
			cout << "  Введите страну производителя самолёта, которую вы хотите найти: ";
			cin >> srchCountry;// = stringCheck();

			system("cls");
			cout << " ____________________________________________________________________________________________________________________________________________________" << endl;
			cout << "| Страна производитель: " << setw(10) << "| Модель самолёта: " << setw(7) << "| Вес: " << setw(5) << "| Объём двигателя: " << setw(5) <<
				"|Мощность двигателя: " << setw(5) << "| Количство мест: " << setw(5) << "| Тип крыла: " << setw(5) << " | Длина крыла: " << setw(5) << "| Материал:|" << endl;
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
				cout << "По вашему запросу ничего не найдено." << endl;
			}

			system("pause");
			break;


		case 2:
			cout << "  Введите модель самолёта, которую вы хотите найти: ";
			cin >> nameModel;// = stringCheck();

			system("cls");
			cout << " ____________________________________________________________________________________________________________________________________________________" << endl;
			cout << "| Страна производитель: " << setw(10) << "| Модель самолёта: " << setw(7) << "| Вес: " << setw(5) << "| Объём двигателя: " << setw(5) <<
				"|Мощность двигателя: " << setw(5) << "| Количство мест: " << setw(5) << "| Тип крыла: " << setw(5) << " | Длина крыла: " << setw(5) << "| Материал:|" << endl;
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
				cout << "По вашему запросу ничего не найдено." << endl;
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
		cout << "Ваш выбор: ";
		int choice = CheckNumbers();
		switch (choice) {
		case 1:
			cout << "  Введите имя пилота, которого вы хотите найти: ";
			cin >> srchName;// = stringCheck();

			system("cls");
			cout << "Список пилотов:" << endl;
			cout << " ______________________________________________________________" << endl;
			cout << "|   Имя:   " << setw(15) << "|    Фамилия:   " << setw(10) << "| Возраст: " << setw(15) << "|    Звание:    " << setw(7) <<
				"| Стаж: |" << endl;
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
				cout << "По вашему запросу ничего не найдено." << endl;
			}

			system("pause");
			break;


		case 2:
			cout << "  Введите фамилию пилота, которого вы хотите найти: ";
			cin >> srchSurname;// = stringCheck();

			system("cls");
			cout << "Список пилотов:" << endl;
			cout << " ______________________________________________________________" << endl;
			cout << "|   Имя:   " << setw(15) << "|    Фамилия:   " << setw(10) << "| Возраст: " << setw(15) << "|    Звание:    " << setw(7) <<
				"| Стаж: |" << endl;
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
				cout << "По вашему запросу ничего не найдено." << endl;
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
		cout << "Ваш выбор: ";
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
		cout << "Ваш выбор: ";
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
	cout << "|   Страна:   " << setw(14) << "|    Модель:   |" << endl;
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
	Sheet* sheet1 = book->addSheet(L"Самолёты");
	Sheet* sheet2 = book->addSheet(L"Пилоты");
	Sheet* sheet3 = book->addSheet(L"Состав");
	Sheet* sheet4 = book->addSheet(L"Страны");

	sheet1->writeStr(1, 0, L"Производитель");
	sheet1->writeStr(1, 1, L"Модель");
	sheet1->writeStr(1, 2, L"Вес");
	sheet1->writeStr(1, 3, L"Объём двигателя");
	sheet1->writeStr(1, 4, L"Мощность двигателя");
	sheet1->writeStr(1, 5, L"Кол-во мест");
	sheet1->writeStr(1, 6, L"Тип крыла");
	sheet1->writeStr(1, 7, L"Длина крыла");
	sheet1->writeStr(1, 8, L"Материал");

	sheet2->writeStr(1, 0, L"Имя");
	sheet2->writeStr(1, 1, L"Фамилия");
	sheet2->writeStr(1, 2, L"Возраст");
	sheet2->writeStr(1, 3, L"Звание");
	sheet2->writeStr(1, 4, L"Стаж");

	sheet3->writeStr(1, 0, L"Звание");
	sheet3->writeStr(1, 1, L"Количество");

	sheet4->writeStr(1, 0, L"Страна");
	sheet4->writeStr(1, 1, L"Модель самолета");

	

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

