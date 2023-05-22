#include "functions.h"


int userChoice;
void generalMenu() {
    cout << "Загружена база данных по умолчанию\n\n";
    cout << "Выберите действие:\n";
    cout << "1 - Открыть файл\n";
    cout << "2 - Просмотр данных\n";
    cout << "3 - Записать файл\n";
    cout << "4 - Записать в новый файл\n";
    cout << "5 - Выход из программы\n\n> ";
    cin >> userChoice;
};

int main() {
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);
    // system ("chcp 1251");

    generalMenu();

    int action, dataAmount = 0;
    char filename;

    Table* Data = new Table[dataAmount];

    while (userChoice != 0) {
        switch (userChoice) {
            case 1:
                
        }
    }
}
