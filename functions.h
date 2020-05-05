#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>
#include "libxl.h"

using namespace std;
using namespace libxl;
using std::wstring; using std::vector;
using std::multimap;
using std::cin;
using std::istream;
using std::wstring;
using listOfStrings = std::list<std::string>;

void createPlaneFile();
int readPlaneFile(string);
int savePlaneFile(string);

void createPersonFile();
int readPersonFile(string);
int savePersonFile(string);

void textMainMenu();
void textAddMenu();
void textDelRecMenu();
void textViewMenu();
void textEditMenu();
void textEditPlaneMenu();
void textEditPersonMenu();
void textSearchMenu();
void textSearchPlaneMenu();
void textSearchPersonMenu();
void textSortMenu();
void textSortPlaneMenu();
void textSortPersonMenu();

void addPlaneRecord();
void addPersonRecord();

void delPlaneRecord();
void delPersonRecord();
void delAllRecords();

void viewPlaneRecord();
void viewPersonRecord();

void editPlaneRecord();
void editPersonRecord();

void searchPlaneRecord();
void searchPersonRecord();

void sortPlaneRecord();
void sortPersonRecord();

void viewCountries();

void createXLSXReport();
wstring to_wstring(string const& str);
