#pragma once

#include <iostream>
#include <fstream>
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

void DataEntry(Data* (&d), int &n);
void ReadingData(Data* (&d), int& n, char fileName[256]);
void Print(Data *d, int n);
void DataChange(Data* (&d), int n);
void DeleteData(Data* (&d), int& n);
void Copy(Data* (&dNew), Data* (&dOld), int n); // копия всех выбранных данных
void Copy(Data& dNew, Data& dOld); // копия данных элемента
void AddDate(Data* (&d), int &n);
void DataSorting(Data* d, int n);
void DataSaving(Data* d, int n, char fileName[256]);
