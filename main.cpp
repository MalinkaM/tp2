#include "sign.h"
#include <vector>
#include <fstream>
#include <algorithm>

void addSign(std::vector<SIGN>& signs) {
    SIGN newSign;
    std::cin >> newSign;
    signs.push_back(newSign);
    std::sort(signs.begin(), signs.end());
}

void printByMonth(const std::vector<SIGN>& signs) {
    int month;
    std::cout << "������� ����� ��� ������ (1-12): ";
    std::cin >> month;

    bool found = false;
    for (const auto& sign : signs) {
        int day, m, year;
        sign.getBirthday(day, m, year);
        if (m == month) {
            std::cout << sign << "\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "��� �����, ���������� � ���� ������.\n";
    }
}

void editSign(std::vector<SIGN>& signs) {
    int index;
    std::cout << "������� ����� ������ ��� �������������� (1-" << signs.size() << "): ";
    std::cin >> index;

    if (index < 1 || index > signs.size()) {
        std::cout << "������������ �����.\n";
        return;
    }

    std::cin >> signs[index - 1];
    std::sort(signs.begin(), signs.end());
}

void deleteSign(std::vector<SIGN>& signs) {
    int index;
    std::cout << "������� ����� ������ ��� �������� (1-" << signs.size() << "): ";
    std::cin >> index;

    if (index < 1 || index > signs.size()) {
        std::cout << "������������ �����.\n";
        return;
    }

    signs.erase(signs.begin() + index - 1);
}

void menu() {
    std::cout << "1. �������� ������\n";
    std::cout << "2. ������� ������\n";
    std::cout << "3. ������������� ������\n";
    std::cout << "4. ������� ������ �� ������\n";
    std::cout << "5. �����\n";
}

int main() {
    std::vector<SIGN> signs;
    int choice;

    do {
        menu();
        std::cin >> choice;

        switch (choice) {
        case 1: addSign(signs); break;
        case 2: deleteSign(signs); break;
        case 3: editSign(signs); break;
        case 4: printByMonth(signs); break;
        case 5: std::cout << "�����.\n"; break;
        default: std::cout << "������������ �����.\n";
        }
    } while (choice != 5);

    return 0;
}
