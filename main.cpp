#include "Container.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Container cont;

    system("cls");
    int inp;
    do {
        cout << "1. �������� ���������� ����������\n";
        cout << "2. �������� ���������\n";
        cout << "3. ������ � ��������� ���������� �� �������\n";
        cout << "4. �������� ����� �������\n";
        cout << "5. ����� �� ������ ��������\n";
        cout << "6. �����\n";

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
            int inpda;
            SIGN* element;
            cin >> inpd;
            try {
                element = cont[inpd];
            }
            catch (const out_of_range exc) {
                cout << "�������� ������!\n";
                break;
            }

            do {
                element->operator<<(cout);
                cout << "1. �������� ���\n";
                cout << "2. �������� �������\n";
                cout << "3. �������� ���� �������\n";
                cout << "4. �������� ���� ��������\n";
                cout << "5. �������\n";
                cout << "6. �����\n";

                string buf;
                int arr[3];
                cin >> inpda;
                system("cls");

                switch (inpda) {
                case 1:
                    cout << "������� ����� ����������: ";
                    cin >> buf;
                    element->setName(buf);
                    break;
                case 2:
                    cout << "������� ����� ����������: ";
                    cin >> buf;
                    element->setSurname(buf);
                    break;
                case 3:
                    cout << "������� ����� ����������: ";
                    cin >> buf;
                    element->setZodiac(buf);
                    break;
                case 4:
                    cout << "������� ����� ���������� � ������� ���� ����� ��� ��� ������������: \n";
                    cin >> arr[0] >> arr[1] >> arr[2];
                    element->setBirthday(arr);
                    break;
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
                };
            } while (inpda != 6);
            break;
        }
        case 4: {
            SIGN* newElement = new SIGN();
            string buf1, buf2, buf3;
            int arr[3];
            cout << "������� ���: ";
            cin >> buf1;
            cout << "������� �������: ";
            cin >> buf2;
            cout << "������� ���� �������: ";
            cin >> buf3;
            cout << "������� ���� �������� � ������� ���� ����� ��� ��� ������������: ";
            cin >> arr[0] >> arr[1] >> arr[2];
            newElement->setName(buf1);
            newElement->setSurname(buf2);
            newElement->setZodiac(buf3);
            newElement->setBirthday(arr);
            cont.add(newElement);
            cout << "������� ��������.\n";
            break;
        }
        case 5: {
            cout << "������� ����� ������ ��������: ";
            int month;
            cin >> month;
            int counter = 0;
            for (int i = 0; i < cont.length(); i++) {
                if (cont[i]->getBirthday()[1] == month) {
                    counter++;
                    cont[i]->operator<<(cout);
                }
            }
            if (counter == 0) cout << "��� �����, ���������� � ���� ������!\n";
            break;
        }
        case 6:
            break;
        default:
            cout << "������� ������������ �������!\n";
            break;
        }
    } while (inp != 6);

    return 0;
}
