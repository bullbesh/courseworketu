#include "functions.h"


void DataEntry(Data* (&d), int& n) {
    cout << "Введите количество данных на ввод:\n\n> ";
    cin >> n;

    d = new Data[n];
    int x = 0;

    for (int i = 0; i < n; i++) {
        x = i;
        d[i].code = (x + 1);

        cout << "Введите марку автомобиля: ";
        cin >> d[i].mark;

        cout << "Введите модель автомобиля: ";
        cin >> d[i].model;

        cout << "Введите количество лошадиных сил: ";
        cin >> d[i].horsepower;

        cout << "Введите страну, в которой производится автомобиль: ";
        cin >> d[i].country;
    }
}

void ReadingData(Data* (&d), int& n, string fileName) {
    ifstream reading(fileName);

    if (reading) {
        reading >> n;

        d = new Data[n];

        for (int i = 0; i < n; i++) {
            reading >> d[i].code;
            reading >> d[i].mark;
            reading >> d[i].model;
            reading >> d[i].horsepower;
            reading >> d[i].country;
        }

        cout << "Данные успешно считаны.\n\n";
    }

    else {
        cout << "Ошибка открытия файла.\n\n";
    }

    reading.close();
}