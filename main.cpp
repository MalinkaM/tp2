#include "Container.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Container cont;

    system("cls");
    int inp;
    do {
        cout << "1. Показать содержимое контейнера\n";
        cout << "2. Очистить контейнер\n";
        cout << "3. Работа с элементом контейнера по индексу\n";
        cout << "4. Добавить новый элемент\n";
        cout << "5. Поиск по месяцу рождения\n";
        cout << "6. Выход\n";

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
            int inpda;
            SIGN* element;
            cin >> inpd;
            try {
                element = cont[inpd];
            }
            catch (const out_of_range exc) {
                cout << "Неверный индекс!\n";
                break;
            }

            do {
                element->operator<<(cout);
                cout << "1. Изменить имя\n";
                cout << "2. Изменить фамилию\n";
                cout << "3. Изменить знак зодиака\n";
                cout << "4. Изменить дату рождения\n";
                cout << "5. Удалить\n";
                cout << "6. Назад\n";

                string buf;
                int arr[3];
                cin >> inpda;
                system("cls");

                switch (inpda) {
                case 1:
                    cout << "Введите новую информацию: ";
                    cin >> buf;
                    element->setName(buf);
                    break;
                case 2:
                    cout << "Введите новую информацию: ";
                    cin >> buf;
                    element->setSurname(buf);
                    break;
                case 3:
                    cout << "Введите новую информацию: ";
                    cin >> buf;
                    element->setZodiac(buf);
                    break;
                case 4:
                    cout << "Введите новую информацию в формате День Месяц Год без разделителей: \n";
                    cin >> arr[0] >> arr[1] >> arr[2];
                    element->setBirthday(arr);
                    break;
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
                };
            } while (inpda != 6);
            break;
        }
        case 4: {
            SIGN* newElement = new SIGN();
            string buf1, buf2, buf3;
            int arr[3];
            cout << "Введите имя: ";
            cin >> buf1;
            cout << "Введите фамилию: ";
            cin >> buf2;
            cout << "Введите знак зодиака: ";
            cin >> buf3;
            cout << "Введите дату рождения в формате День Месяц Год без разделителей: ";
            cin >> arr[0] >> arr[1] >> arr[2];
            newElement->setName(buf1);
            newElement->setSurname(buf2);
            newElement->setZodiac(buf3);
            newElement->setBirthday(arr);
            cont.add(newElement);
            cout << "Элемент добавлен.\n";
            break;
        }
        case 5: {
            cout << "Введите номер месяца рождения: ";
            int month;
            cin >> month;
            int counter = 0;
            for (int i = 0; i < cont.length(); i++) {
                if (cont[i]->getBirthday()[1] == month) {
                    counter++;
                    cont[i]->operator<<(cout);
                }
            }
            if (counter == 0) cout << "Нет людей, родившихся в этом месяце!\n";
            break;
        }
        case 6:
            break;
        default:
            cout << "Введите существующую команду!\n";
            break;
        }
    } while (inp != 6);

    return 0;
}
