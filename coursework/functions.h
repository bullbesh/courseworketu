#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
    Номер в списке
    Название фильма
    Жанр фильма
    Год выпуска
    Оценка фильма 
*/

struct Data {
    int code;
    string name;
    string genre;
    int yearRelease;
    float rating;
};

void DataEntry(Data* (&d), int &n);
void ReadingData(Data* (&d), int& n, string fileName);
