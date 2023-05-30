#include "functions.h"


void DataEntry(Data* (&d), int& n) {
    cout << "Введите количество данных на ввод:\n\n> ";
    cin >> n;

    d = new Data[n];
    cin.ignore();

    for (int i = 0; i < n; i++) {

        cout << "\nBвeдитe марку автомобиля: ";
        cin >> d[i].mark;

        cout << "Введите модель автомобиля: ";
        cin >> d[i].model;

        cout << "Введите количество лошадиных сил: ";
        cin >> d[i].horsepower;

        cout << "Введите страну, в которой производится автомобиль: ";
        cin >> d[i].country;

        cout << "Введите цену автомобиля: ";
        cin >> d[i].price;
    }
}

void ReadingData(Data* (&d), int& n, char fileName[256]) {
    ifstream reading(fileName);

    if (reading) {
        reading >> n;

        d = new Data[n];

        for (int i = 0; i < n; i++) {
            reading >> d[i].mark;
            reading >> d[i].model;
            reading >> d[i].horsepower;
            reading >> d[i].country;
            reading >> d[i].price;
        }

        cout << "Данные успешно считаны.\n\n";
    }

    else {
        cout << "Ошибка открытия файла.\n\n";
    }

    reading.close();
}

void Print(Data *d, int n) {
    for (int i = 0; i < n; i++) {
        cout << "#" << (i + 1) << endl;
        cout << "Марка: " << d[i].mark << endl;
        cout << "Модель: " << d[i].model << endl;
        cout << "HP: " << d[i].horsepower << endl;
        cout << "Страна производитель: " << d[i].country << endl;
        cout << "Цена за автомобиль: " << d[i].price << endl;

        cout << "______________________________________________________________________________________\n\n";
    }
}

void DataChange(Data* (&d), int n) {
    int _n;
    cout << "Введите номер элемента (от 1 до " << n << "): ";
    cin >> _n;
    _n--;

    system("cls");

    if (_n >= 0 && _n < n) {
        cout << "\nBвeдитe марку автомобиля: ";
        cin >> d[_n].mark;

        cout << "Введите модель автомобиля: ";
        cin.getline(d[_n].model, 256);

        cout << "Введите количество лошадиных сил: ";
        cin >> d[_n].horsepower;

        cout << "Введите страну, в которой производится автомобиль: ";
        cin >> d[_n].country;

        cout << "Введите цену автомобиля: ";
        cin >> d[_n].price;

        system("cls");
        cout << "Данные успешно изменены.\n";
    }
    else {
        cout << "Номер введён неверно.\n";
    }
}

void DeleteData(Data* (&d), int& n) {
	int _n;
	cout << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;
	if (_n >= 0 && _n < n) {
		Data* buf = new Data[n - 1];

        int x = 0;
        for (int i = 0; i < n; i++) {
            if (i != _n) {
                d[x] = buf[i];
                x++;
            }
        }

        delete[]buf;
        d = buf;
        n--;
        system("cls");
        cout << "Выбранные данные успешно удалены\n";
    }
    else {
        cout << "Номер введён неверно.\n";
    }

}

void Copy(Data* (&dNew), Data* (&dOld), int n) {
	for (int i = 0; i < n; i++) {
		dNew[i] = dOld[i];
	}
}

// void Copy(Data& dNew, Data& dOld) {
//     dNew.mark = dOld.mark;
//     dNew.model = dOld.model;
//     dNew.horsepower = dOld.horsepower;
//     dNew.country = dOld.country;
//     dNew.price = dOld.price;
// }

void AddDate(Data* (&d), int &n) {
    Data* buf;
    buf = new Data[n];
    Copy(d, buf, n--);
    n++;
    d = new Data[n];
    Copy(d, buf, --n);
    cin.ignore();

    cout << "\nBвeдитe марку автомобиля: ";
    cin >> d[n].mark;

    cout << "Введите модель автомобиля: ";
    cin.getline(d[n].model, 256);

    cout << "Введите количество лошадиных сил: ";
    cin >> d[n].horsepower;

    cout << "Введите страну, в которой производится автомобиль: ";
    cin >> d[n].country;

    cout << "Введите цену автомобиля: ";
    cin >> d[n].price;

    system("cls");
    cout << "Данные добавлены.\n\n";
    delete[]buf;
}

// void DataSorting(Data* d, int n) {
//     Data buf;

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (d[i].price > d[j].price) {
//                 Copy(buf, d[j]);
//                 Copy(d[j], d[i]);
//                 Copy(d[i], buf);
//             }
//         }
//     }

//     cout << "Данные отсортированы.\n\n";
// }

void DataSaving(Data* d, int n, char fileName[256]) {
    ofstream record(fileName, ios::out);

    if (record) {
        record << n << endl;

        for (int i = 0; i < n; i++) {
            record << d[i].mark << endl;
            record << d[i].model << endl;
            record << d[i].horsepower << endl;
            record << d[i].country << endl;

            if (i < (n - 1)) {
                record << d[i].price << endl;
            }
            else {
                record << d[i].price;
            }
        }
    }
    else {
        cout << "Ошибка открытия файла.\n\n";
    }

    record.close();

}