#include "functions.h"


void entryData(Data* (&d), int& n) {
    cout << "Введите количество данных на ввод:\n\n> ";
    cin >> n;

    d = new Data[n];

    for (int i = 0; i < n; i++) {

		cin.ignore();

        cout << "\nBвeдитe марку автомобиля: ";
        cin.getline(d[i].mark, 256);

        cout << "Введите модель автомобиля: ";
        cin.getline(d[i].model, 256);

        cout << "Введите количество лошадиных сил: ";
        cin >> d[i].horsepower;
		cin.ignore();

        cout << "Введите страну, в которой производится автомобиль: ";
		cin.getline(d[i].country, 256);

        cout << "Введите цену автомобиля: ";
        cin >> d[i].price;
        cin.ignore();
    }
}

void readData(Data* (&d), int& n, char filename[256]) {
    ifstream reading(filename);

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

        cout << "\nДанные успешно считаны.\n\n";
    }

    else {
        cout << "Ошибка открытия файла.\n\n";
    }

    reading.close();
}

void printTable(Data* d, int n) {
	cout << left << setw(20) << "#"
		<< left << setw(26) << "Марка"
		<< left << setw(25) << "Модель"
		<< left << setw(20) << "HP"
		<< left << setw(35) << "Страна"
		<< left << setw(3) << "Цена P";
	cout << "\n______________________________________________________________________________________________________________________\n";
	for (int i = 0; i < n; i++) {
		cout << left << setw(20) << i+1
			<< left << setw(20) <<  d[i].mark
			<< left << setw(20) <<  d[i].model
			<< left << setw(20) <<  d[i].horsepower
			<< left << setw(29) <<  d[i].country
			<< left << setw(5) <<  d[i].price;
		cout << "\n______________________________________________________________________________________________________________________\n";
	}
}

void changeData(Data* (&d), int n) {
    int _n;
    int selectOption;
    
    cout << left << setw(20) << "#"
        << left << setw(26) << "Марка"
        << left << setw(25) << "Модель"
        << left << setw(20) << "HP"
        << left << setw(35) << "Страна"
        << left << setw(3) << "Цена P";
	cout << "\n______________________________________________________________________________________________________________________\n";

    for (int i = 0; i < n; i++) {
		cout << left << setw(20) << (i + 1)
			<< left <<  setw(20) <<  d[i].mark
			<< left <<  setw(20) <<  d[i].model
			<< left <<  setw(20) <<  d[i].horsepower
			<< left <<  setw(29) <<  d[i].country
			<< left <<  setw(5) <<  d[i].price;
		cout << "\n______________________________________________________________________________________________________________________\n";
	}
    
    cout << "Введите номер элемента (от 1 до " << n << "): ";
    cin >> _n;
    _n--;

    system("cls");
    
    cout << "1 - Изменить марку автомобиля\n";
    cout << "2 - Изменить модель автомобиля\n";
    cout << "3 - Изменить количество лошадиных сил\n";
    cout << "4 - Изменить страну, в которой производится автомобиль\n";
    cout << "5 - Изменить цену автомобиля\n";
    cout << "Введите то, что хотите изменить: ";
    cin >> selectOption;

    if (_n >= 0 && _n < n) {
        switch (selectOption) {
            case 1:
                cout << "Bвeдитe марку автомобиля: ";
                cin.getline(d[_n].mark, 128);
                break;
            case 2:
                cout << "Введите модель автомобиля: ";
                cin.getline(d[_n].model, 128);
                break;
            case 3:
                cout << "Введите количество лошадиных сил: ";
                cin >> d[_n].horsepower;
                break;
            case 4:
                cout << "Введите страну, в которой производится автомобиль: ";
                cin.getline(d[_n].country, 128);
                break;
            case 5:
                cout << "Введите цену автомобиля: ";
                cin >> d[_n].price;
                break;
            default:
                cout << "Неверный выбор.";
                break;
        }
        system("cls");
        cout << "Данные успешно изменены.\n";
    }
    else {
        cout << "Номер введён неверно.\n";
    }
}

void deleteData(Data* (&d), int& n) {
	int _n;

    cout << left << setw(20) << "#"
        << left << setw(26) << "Марка"
        << left << setw(25) << "Модель"
        << left << setw(20) << "HP"
        << left << setw(35) << "Страна"
        << left << setw(3) << "Цена P";
    cout << "\n______________________________________________________________________________________________________________________\n";
    for (int i = 0; i < n; i++) {
		cout << left << setw(20) << (i + 1)
			<< left <<  setw(20) <<  d[i].mark
			<< left <<  setw(20) <<  d[i].model
			<< left <<  setw(20) <<  d[i].horsepower
			<< left <<  setw(29) <<  d[i].country
			<< left <<  setw(5) <<  d[i].price;
		cout << "\n______________________________________________________________________________________________________________________\n";
	}

	cout << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;
	if (_n >= 0 && _n < n) {
		Data* buf = new Data[n - 1];

        int x = 0;
        for (int i = 0; i < n; i++) {
            if (i != _n) {
                buf[x] = d[i];
                x++;
            }
        }

        delete[] buf;
        d = buf;
        n--;
        system("cls");
        cout << "Выбранные данные успешно удалены.\n";
    }
    else {
        cout << "Номер введён неверно.\n";
    }
}

void copyElement(Data* (&dNew), Data* (&dOld), int n) {
	for (int i = 0; i < n; i++) {
		dNew[i] = dOld[i];
	}
}

void addData(Data* (&d), int &n) {
    Data* buf;
    buf = new Data[n];
    copyElement(buf, d, n);
    n++;
    d = new Data[n];
    copyElement(d, buf, --n);
    cin.ignore();

	cout << "~ Ввод новых данных (введённая информация добавляется в конец таблицы)\n\n";

    cout << "Bвeдитe марку автомобиля: ";
    cin.getline(d[n].mark, 256);
	cout << "\n";

    cout << "Введите модель автомобиля: ";
    cin.getline(d[n].model, 256);
	cout << "\n";

    cout << "Введите количество лошадиных сил: ";
    cin >> d[n].horsepower;
	cout << "\n";
	cin.ignore();

    cout << "Введите страну, в которой производится автомобиль: ";
	cin.getline(d[n].country, 256);
	cout << "\n";

    cout << "Введите цену автомобиля: ";
    cin >> d[n].price;
	cout << "\n";

    system("cls");
    cout << "Данные успешно добавлены.\n\n";
    delete[]buf;
}

void saveData(Data* d, int n, char filename[256]) {
    ofstream record(filename, ios::out);

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
        cout << "\nФайл с данными успешно создан.\n\n";
    }
    else {
        cout << "Ошибка открытия файла.\n\n";
    }

    record.close();

}

void searchData(const Data rest[], int n) {
	if (n == 0) {
		cout << "Нет доступных записей.\n";
		return;
	}

	cout << "Введите название марки для поиска: ";
	cin.ignore();
	char searchName[256];
	cin.getline(searchName, 256);
	system("cls");
	bool found = false;
	for (int i = 0; i < n; i++) {
		if (strcmp(rest[i].mark, searchName) == 0) {
			cout << left << setw(20) << "#"
				<< left << setw(26) << "Марка"
				<< left << setw(25) << "Модель"
				<< left << setw(20) << "HP"
				<< left << setw(35) << "Страна"
				<< left << setw(3) << "Цена Р";
			cout << "\n______________________________________________________________________________________________________________________\n";
			for (int j = 0; j < n; j++) {
				if (strcmp(rest[j].mark, searchName) == 0) {
					cout << left << setw(20) << j + 1
						<< left << setw(20) << rest[j].mark
						<< left << setw(20) << rest[j].model
						<< left << setw(20) << rest[j].horsepower
						<< left << setw(29) << rest[j].country
						<< left << setw(5) << rest[j].price;
					cout << "\n______________________________________________________________________________________________________________________\n";
				}
			}
			found = true;
		}
	}
	system("pause");

	if (!found) {
		cout << "Запись с указанным названием не найдена.\n";
	}
}

void sortData(Data* d, int n) {
	if (n == 0) {
		cout << "Нет доступных записей.\n";
		return;
	}

	cout << "~ Сортировка данных\n\n\n";
	cout << "Выберите тип сортировки:\n\n";
	cout << "1 - Сортировка по лошадиным силам\n";
	cout << "2 - Сортировка по цене автомобиля\n\n> ";

	int f;
	cin >> f;
	system("cls");

	if (f == 2) {
		cout << "Выберите тип сортировки:\n\n";
	    cout << "1 - По возрастанию цены\n";
		cout << "2 - По убыванию цены\n\n> ";
		int c;
		cin >> c;
		system("cls");

		switch (c) {
		case 1: {
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					if (d[j].price > d[j + 1].price) {
						Data temp = d[j];
						d[j] = d[j + 1];
						d[j + 1] = temp;
					}
				}
			}
			cout << "Записи успешно отсортированы по цене в возрастающем порядке.\n\n";
			break;
		}
		case 2: {
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					if (d[j].price < d[j + 1].price) {
						Data temp = d[j];
						d[j] = d[j + 1];
						d[j + 1] = temp;
					}
				}
			}
			cout << "Записи успешно отсортированы по цене в убывающем порядке.\n\n";
			break;
		}
		default:
			cout << "Некорректный выбор. Сортировка не выполнена.\n";
			break;
		}
	}
	else if (f == 1) {
		cout << "Выберите тип сортировки:\n\n"
			<< "1. По возрастанию лошадиных сил\n"
			<< "2. По убыванию лошадиных сил\n\n> ";
		int c;
		cin >> c;
		system("cls");

		switch (c) {
		case 1: {
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					if (d[j].horsepower > d[j + 1].horsepower) {
						Data temp = d[j];
						d[j] = d[j + 1];
						d[j + 1] = temp;
					}
				}
			}
			cout << "Записи успешно отсортированы по лошадиным силам в возрастающем порядке.\n\n";
			break;
		}
		case 2: {
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					if (d[j].horsepower < d[j + 1].horsepower) {
						Data temp = d[j];
						d[j] = d[j + 1];
						d[j + 1] = temp;
					}
				}
			}
			cout << "Записи успешно отсортированы по лошадиным силам в убывающем порядке.\n\n";
			break;
		}
		default:
			cout << "Некорректный выбор. Сортировка не выполнена.\n\n";
			break;
		}
	}
	else {
		cout << "Неверно введен номер действия. Возврат в главное меню.\n\n";
	}
}