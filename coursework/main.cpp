#include "functions.h"


int _stateMenu;
void Menu() {
    cout << "Выберите действие:\n";
    cout << "1 - Открыть файл\n";
    cout << "2 - Просмотр данных\n";
    cout << "3 - Записать файл\n";
    cout << "4 - Записать в новый файл\n";
    cout << "5 - Выход из программы\n\n> ";
    cin >> _stateMenu;
};

int main() {
    system("chcp 65001");
    Menu();

    int _actions, amountOfData = 0;
    string fileName;

    Data* d = new Data[amountOfData];

    while (_stateMenu != 5) {
        switch (_stateMenu) {
            case 1:
                system("cls");
                cout << "Выберите, как записывать данные? (1 - вручную, 0 - из файла)\n\n> ";
                cin >> _actions;
                system("cls");

                if (_actions == 1) {
                    DataEntry(d, amountOfData);
                }

                else {
                    cout << "Введите название файла:\n\n>";
                    cin >> fileName;
                    ReadingData(d, amountOfData, fileName);
                }

                system("pause");
                system("cls");
                Menu();
                break;

            default:
                cout << "Введены некорректные данные\n";
        }

            system("pause");
            system("cls");
            Menu();
            break;
    }
}
