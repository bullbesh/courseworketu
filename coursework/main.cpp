/*
Table view:

Code | Mark | Model | Horsepower | Country | Price
*/

#include "functions.h"


int userChoice;
void generalMenu() {
    cout << "Выберите действие:\n";
    cout << "0 - Выход из программы\n";
    cout << "1 - Ввод данных\n";
    cout << "2 - Вывод данных\n";
    cout << "3 - Изменение данных\n";
    cout << "4 - Удаление данных\n";
    cout << "5 - Добавление данных\n";
    cout << "6 - Сортировка данных\n";
    cout << "7 - Сохранение данных\n";
    cout << "8 - Поиск данных\n\n> ";
    cin >> userChoice;
};

int main() {
    system("chcp 65001");
    generalMenu();

    int _actions, dataAmount = 0;
    char filename[256];

    Data* d = new Data[dataAmount];

    while (userChoice != 0) {
        switch (userChoice) {

            case 1:
            // запись, чтение данных
                system("cls");
                cout << "Выберите, как записывать данные? (1 - вручную, 0 - из файла)\n\n> ";
                cin >> _actions;
                system("cls");

                if (_actions == 1) {
                    entryData(d, dataAmount);
                }

                else {
                    cout << "Введите название файла:\n\n> ";
                    cin >> filename;
                    readData(d, dataAmount, filename);
                }

                system("pause");
                system("cls");
                generalMenu();
                break;

            case 2:
            // вывод данных
                system("cls");
                if (dataAmount != 0) {
                    printTable(d, dataAmount);
                }
                else {
                    cout << "Данные пусты.\n\n";
                }

                system("pause");
                system("cls");
                generalMenu();
                break;
            
            case 3:
            // замена данных
                system("cls");

                if (dataAmount != 0) {
                    changeData(d, dataAmount);
                }
                else {
                    cout << "Данные пусты.\n\n";
                }
            
                system("pause");
                system("cls");
                generalMenu();
                break;
            
            case 4:
            // удаление данных
                system("cls");

                if (dataAmount != 0) {
                    deleteData(d, dataAmount);
                }
                else {
                    cout << "Данные пусты.\n\n";
                }

                system("pause");
                system("cls");
                generalMenu();
                break;
            
            case 5:
            // добавление данных
                system("cls");

                if (dataAmount != 0) {
                    addData(d, dataAmount);
                    dataAmount++;
                }
                else {
                    cout << "Данные пусты.\n\n";
                }

                system("pause");
                system("cls");
                generalMenu();
                break;

            case 6:
            // сортировка данных
                system("cls");

                if (dataAmount != 0) {
                    sortData(d, dataAmount);
                }
                else {
                    cout << "Данные пусты.\n\n";
                }

                system("pause");
                system("cls");
                generalMenu();
                break;
            
            case 7:
            // сохранение данных в новый файл
                system("cls");

                cout << "Введите название файла: ";
                cin >> filename;

                if (dataAmount != 0) {
                    saveData(d, dataAmount, filename);
                }
                else {
                    cout << "Данные пусты.\n\n";
                }

                system("pause");
                system("cls");
                generalMenu();
                break;
            
            case 8:
            // поиск в таблице по марке автомобиля
                system("cls");

                if (dataAmount != 0) {
                    searchData(d, dataAmount);
                }
                else {
                    cout << "Данные пусты.\n\n";
                }
            
                system("pause");
                system("cls");
                generalMenu();
                break;
            
            default:
                cout << "Введён неверный номер действия.";
                break;

        }
    }

    cout << "\nЗавершение работы программы.\n\n";
    system("pause");
}