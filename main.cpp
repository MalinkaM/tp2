#include "Container.h"
#include "TextAnalyzer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

// ������� ��� ���������� ������� �������
void executeTask1() {
    Container cont;

    int inp;
    do {
        cout << "=== ������� 1 ===\n";
        cout << "1. �������� ���������� ����������\n";
        cout << "2. �������� ���������\n";
        cout << "3. ������ � ��������� ���������� �� �������\n";
        cout << "4. �������� ����� �������\n";
        cout << "5. ����� �� ������ ��������\n";
        cout << "6. ����� � ������� ����\n";

        cin >> inp;
        system("cls");

        switch (inp) {
        case 1:
            cout << "���������� ��������� � ����������:  " << cont.length() << "\n";
            cont.operator<<(cout);
            break;
        case 2:
            cont.clear();
            cout << "��������� ��� ������.\n";
            break;
        case 3: {
            cout << "������� ������ ��������: ";
            int inpd;
            cin >> inpd;

            if (inpd < 0 || inpd >= cont.length()) {
                cout << "�������� ������!\n";
                break;
            }

            SIGN* element = cont[inpd];
            int inpda;
            do {
                element->operator<<(cout);
                cout << "1. �������� ���\n";
                cout << "2. �������� �������\n";
                cout << "3. �������� ���� �������\n";
                cout << "4. �������� ���� ��������\n";
                cout << "5. �������\n";
                cout << "6. �����\n";

                cin >> inpda;
                system("cls");

                switch (inpda) {
                case 1: {
                    cout << "������� ����� ���: ";
                    string buf;
                    cin >> buf;
                    element->setName(buf);
                    break;
                }
                case 2: {
                    cout << "������� ����� �������: ";
                    string buf;
                    cin >> buf;
                    element->setSurname(buf);
                    break;
                }
                case 3: {
                    cout << "������� ����� ���� �������: ";
                    string buf;
                    cin >> buf;
                    element->setZodiac(buf);
                    break;
                }
                case 4: {
                    cout << "������� ���� �������� (���� ����� ���): ";
                    int arr[3];
                    cin >> arr[0] >> arr[1] >> arr[2];
                    element->setBirthday(arr);
                    break;
                }
                case 5:
                    cont.remove(inpd);
                    cout << "������� ������.\n";
                    inpda = 6; 
                    break;
                case 6:
                    break;
                default:
                    cout << "������� ������������ �������!\n";
                    break;
                }
            } while (inpda != 6);
            break;
        }
        case 4: {
            SIGN* newElement = new SIGN();
            string name, surname, zodiac;
            int birthday[3];

            cout << "������� ���: ";
            cin >> name;
            cout << "������� �������: ";
            cin >> surname;
            cout << "������� ���� �������: ";
            cin >> zodiac;
            cout << "������� ���� �������� (���� ����� ���): ";
            cin >> birthday[0] >> birthday[1] >> birthday[2];

            newElement->setName(name);
            newElement->setSurname(surname);
            newElement->setZodiac(zodiac);
            newElement->setBirthday(birthday);

            cont.add(newElement);
            cout << "������� ��������.\n";
            break;
        }
        case 5: {
            cout << "������� ����� ������ ��������: ";
            int month;
            cin >> month;

            if (month < 1 || month > 12) {
                cout << "�������� ����� ������!\n";
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
                cout << "��� �����, ���������� � ���� ������!\n";
            }
            break;
        }
        case 6:
            break;
        default:
            cout << "������� ������������ �������!\n";
            break;
        }
    } while (inp != 6);
}

// ������� ��� ���������� ������� �������
void executeTask2() {
    cout << "=== ������� 2 ===\n";

    string fileName = "example.txt";

    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "�� ������� ������� ����!\n";
        return;
    }

    cout << "������� ����� ��� ��������: ";
    string word;
    cin >> word;

    stringstream buffer;
    buffer << file.rdbuf();
    string fileContent = buffer.str();

    string result = analyseWithWordCount(fileContent, word);

    cout << "��������� �������:\n";
    cout << result;

    file.close();
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    do {
        cout << "=== ������� ���� ===\n";
        cout << "1. ��������� ������� 1 (������ � �����������)\n";
        cout << "2. ��������� ������� 2 (������ ������)\n";
        cout << "3. �����\n";
        cout << "������� ��� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            executeTask1();
            break;
        case 2:
            executeTask2();
            break;
        case 3:
            cout << "����� �� ���������.\n";
            break;
        default:
            cout << "������� ������������ �������!\n";
            break;
        }
    } while (choice != 3);

    return 0;
}
