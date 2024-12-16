#include "Container.h"
#include "TextAnalyzer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

// Функция для выполнения первого задания
void executeTask1() {
    Container cont;

    int inp;
    do {
        cout << "=== Задание 1 ===\n";
        cout << "1. Показать содержимое контейнера\n";
        cout << "2. Очистить контейнер\n";
        cout << "3. Работа с элементом контейнера по индексу\n";
        cout << "4. Добавить новый элемент\n";
        cout << "5. Поиск по месяцу рождения\n";
        cout << "6. Назад в главное меню\n";

        cin >> inp;
        system("cls");

        switch (inp) {
        case 1:
            cout << "Количество элементов в контейнере:  " << cont.length() << "\n";
            cont.operator<<(cout);
            break;
        case 2:
            cont.clear();
            cout << "Контейнер был очищен.\n";
            break;
        case 3: {
            cout << "Введите индекс элемента: ";
            int inpd;
            cin >> inpd;

            if (inpd < 0 || inpd >= cont.length()) {
                cout << "Неверный индекс!\n";
                break;
            }

            SIGN* element = cont[inpd];
            int inpda;
            do {
                element->operator<<(cout);
                cout << "1. Изменить имя\n";
                cout << "2. Изменить фамилию\n";
                cout << "3. Изменить знак зодиака\n";
                cout << "4. Изменить дату рождения\n";
                cout << "5. Удалить\n";
                cout << "6. Назад\n";

                cin >> inpda;
                system("cls");

                switch (inpda) {
                case 1: {
                    cout << "Введите новое имя: ";
                    string buf;
                    cin >> buf;
                    element->setName(buf);
                    break;
                }
                case 2: {
                    cout << "Введите новую фамилию: ";
                    string buf;
                    cin >> buf;
                    element->setSurname(buf);
                    break;
                }
                case 3: {
                    cout << "Введите новый знак зодиака: ";
                    string buf;
                    cin >> buf;
                    element->setZodiac(buf);
                    break;
                }
                case 4: {
                    cout << "Введите дату рождения (день месяц год): ";
                    int arr[3];
                    cin >> arr[0] >> arr[1] >> arr[2];
                    element->setBirthday(arr);
                    break;
                }
                case 5:
                    cont.remove(inpd);
                    cout << "Элемент удален.\n";
                    inpda = 6; 
                    break;
                case 6:
                    break;
                default:
                    cout << "Введите существующую команду!\n";
                    break;
                }
            } while (inpda != 6);
            break;
        }
        case 4: {
            SIGN* newElement = new SIGN();
            string name, surname, zodiac;
            int birthday[3];

            cout << "Введите имя: ";
            cin >> name;
            cout << "Введите фамилию: ";
            cin >> surname;
            cout << "Введите знак зодиака: ";
            cin >> zodiac;
            cout << "Введите дату рождения (день месяц год): ";
            cin >> birthday[0] >> birthday[1] >> birthday[2];

            newElement->setName(name);
            newElement->setSurname(surname);
            newElement->setZodiac(zodiac);
            newElement->setBirthday(birthday);

            cont.add(newElement);
            cout << "Элемент добавлен.\n";
            break;
        }
        case 5: {
            cout << "Введите номер месяца рождения: ";
            int month;
            cin >> month;

            if (month < 1 || month > 12) {
                cout << "Неверный номер месяца!\n";
                break;
            }

            int counter = 0;
            for (int i = 0; i < cont.length(); i++) {
                if (cont[i]->getBirthday()[1] == month) {
                    counter++;
                    cont[i]->operator<<(cout);
                }
            }
            if (counter == 0) {
                cout << "Нет людей, родившихся в этом месяце!\n";
            }
            break;
        }
        case 6:
            break;
        default:
            cout << "Введите существующую команду!\n";
            break;
        }
    } while (inp != 6);
}

// Функция для выполнения второго задания
void executeTask2() {
    cout << "=== Задание 2 ===\n";

    string fileName = "example.txt";

    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл!\n";
        return;
    }

    cout << "Введите слово для подсчета: ";
    string word;
    cin >> word;

    stringstream buffer;
    buffer << file.rdbuf();
    string fileContent = buffer.str();

    string result = analyseWithWordCount(fileContent, word);

    cout << "Результат анализа:\n";
    cout << result;

    file.close();
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    do {
        cout << "=== Главное меню ===\n";
        cout << "1. Выполнить задание 1 (Работа с контейнером)\n";
        cout << "2. Выполнить задание 2 (Анализ текста)\n";
        cout << "3. Выход\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            executeTask1();
            break;
        case 2:
            executeTask2();
            break;
        case 3:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Введите существующую команду!\n";
            break;
        }
    } while (choice != 3);

    return 0;
}
