#include "functions.h"


// Table view:
// Code | Name | Genre | Release | Rating

// struct Product {
//     {1, "What's Eating Gilbert Grape", "Drama", 1993, 8.4},
//     {2, "Se7en", "Triller", 1995, 9.8},
//     {3, "Fight Club", "Triller", 1999, 8.6},
//     {4, "American Psycho", "Triller", 2000, 7.1},
//     {5, "Catch Me If You Can", "Criminal", 2002, 8.9},
// }

void DataEntry(Data* (&d), int& n) {
    cout << "Введите количество данных на ввод:\n\n> ";
    cin >> n;

    d = new Data[n];
    int x = 0;

    for (int i = 0; i < n; i++) {
        x = i;
        d[i].code = (x + 1);

        cout << "Введите название фильма: ";
        cin >> d[i].name;

        cout << "Введите жанр фильма: ";
        cin >> d[i].genre;

        cout << "Введите год выпуска фильма: ";
        cin >> d[i].yearRelease;

        cout << "Введите рейтинг фильма: ";
        cin >> d[i].rating;
    }
}

void ReadingData(Data* (&d), int& n, string fileName) {
    ifstream reading(fileName);

    if (reading) {
        reading >> n;

        d = new Data[n];

        for (int i = 0; i < n; i++) {
            reading >> d[i].code;
            reading >> d[i].name;
            reading >> d[i].genre;
            reading >> d[i].yearRelease;
            reading >> d[i].rating;
        }

        cout << "Данные успешно считаны.\n\n";
    }

    else {
        cout << "Ошибка открытия файла.\n\n";
    }

    reading.close();
}