#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
    Номер в списке
    Марка автомобиля
    Модель автомобиля
    Количество лошадиных сил
    Страна производитель
*/

struct Data {
    int code;
    char mark;
    char model;
    int horsepower;
    char country;
};

void DataEntry(Data* (&d), int &n);
void ReadingData(Data* (&d), int& n, string fileName);
