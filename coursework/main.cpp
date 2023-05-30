/*
Table view:

Code | Mark | Model | Horsepower | Country | Price
*/

#include "functions.h"


int _stateMenu;
void Menu() {
    cout << "Выберите действие:\n";
    cout << "0 - Выход из программы\n";
    cout << "1 - Ввод данных\n";
    cout << "2 - Вывод данных\n";
    cout << "3 - Изменение данных\n";
    cout << "4 - Удаление данных\n";
    cout << "5 - Добавление данных\n";
    cout << "6 - Сортировка данных\n";
    cout << "7 - Сохранение данных\n\n> ";
    cin >> _stateMenu;
};

int main() {
    system("chcp 65001");
    Menu();

    int _actions, amountOfData = 0;
    char fileName[256];

    Data* d = new Data[amountOfData];

    while (_stateMenu != 0) {
        switch (_stateMenu) {

            case 1:
            // запись, чтение данных
                system("cls");
                cout << "Выберите, как записывать данные? (1 - вручную, 0 - из файла)\n\n> ";
                cin >> _actions;
                system("cls");

                if (_actions == 1) {
                    DataEntry(d, amountOfData);
                }

                else {
                    cout << "Введите название файла:\n\n> ";
                    cin >> fileName;
                    ReadingData(d, amountOfData, fileName);
                }

                system("pause");
                system("cls");
                Menu();
                break;

            case 2:
            // вывод данных
                system("cls");
                if (amountOfData != 0) {
                    Print(d, amountOfData);
                }
                else {
                    cout << "Данные пусты.\n\n";
                }

                system("pause");
                system("cls");
                Menu();
                break;
            
            case 3:
            // замена данных
                system("cls");

                if (amountOfData != 0) {
                    DataChange(d, amountOfData);
                }
                else {
                    cout << "Данные пусты.\n\n";
                }
            
                system("pause");
                system("cls");
                Menu();
                break;
            
            case 4:
            // удаление данных
                system("cls");

                if (amountOfData != 0) {
                    DeleteData(d, amountOfData);
                }
                else {
                    cout << "Данные пусты.\n\n";
                }

                system("pause");
                system("cls");
                Menu();
                break;
            
            case 5:
            // добавление данных
                system("cls");

                if (amountOfData != 0) {
                    AddDate(d, amountOfData);
                    amountOfData++;
                }
                else {
                    cout << "Данные пусты.\n\n";
                }

                system("pause");
                system("cls");
                Menu();
                break;

            case 6:
            // сортировка данных
                system("cls");

                if (amountOfData != 0) {
                    // DataSorting(d, amountOfData);
                    cout << "Сортировка\n\n";
                }
                else {
                    cout << "Данные пусты.\n\n";
                }

                system("pause");
                system("cls");
                Menu();
                break;
            
            case 7:
            // сохранение данных в новый файл
                system("cls");

                cout << "Введите название файла: ";
                cin >> fileName;

                if (amountOfData != 0) {
                    DataSaving(d, amountOfData, fileName);
                }
                else {
                    cout << "Данные пусты.\n\n";
                }

                system("pause");
                system("cls");
                Menu();
                break;
            
            default:
                cout << "Введён неверный номер действия.";
                break;

        }
    }
}