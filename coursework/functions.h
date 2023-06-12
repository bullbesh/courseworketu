#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

/*
    Номер в списке
    Марка автомобиля
    Модель автомобиля
    Количество лошадиных сил
    Страна производитель
    Цена автомобиля
*/

struct Data {
    char mark[256];
    char model[256];
    int horsepower;
    char country[256];
    float price;
};

void entryData(Data* (&d), int &n);
void readData(Data* (&d), int& n, char filename[256]);
void printTable(Data *d, int n);
void changeData(Data* (&d), int n);
void deleteData(Data* (&d), int& n);
void copyElement(Data* (&dNew), Data* (&dOld), int n);
void addData(Data* (&d), int &n);
void saveData(Data* d, int n, char filename[256]);
void searchData(const Data rest[], int n);
void sortData(Data* d, int n);
