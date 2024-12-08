#include "sign.h"

// ������������
SIGN::SIGN() {
    std::cout << "������ ����������� ��� ����������.\n";
    surname = name = zodiacSign = "";
    birthday[0] = birthday[1] = birthday[2] = 0;
}

SIGN::SIGN(const std::string& surname, const std::string& name, const std::string& zodiacSign, int day, int month, int year) {
    std::cout << "������ ����������� � �����������.\n";
    this->surname = surname;
    this->name = name;
    this->zodiacSign = zodiacSign;
    this->birthday[0] = day;
    this->birthday[1] = month;
    this->birthday[2] = year;
}

SIGN::SIGN(const SIGN& other) {
    std::cout << "������ ����������� �����������.\n";
    surname = other.surname;
    name = other.name;
    zodiacSign = other.zodiacSign;
    birthday[0] = other.birthday[0];
    birthday[1] = other.birthday[1];
    birthday[2] = other.birthday[2];
}

// ����������
SIGN::~SIGN() {
    std::cout << "������ ����������.\n";
}

// ������ �������
void SIGN::setSurname(const std::string& surname) { this->surname = surname; }
void SIGN::setName(const std::string& name) { this->name = name; }
void SIGN::setZodiacSign(const std::string& zodiacSign) { this->zodiacSign = zodiacSign; }
void SIGN::setBirthday(int day, int month, int year) {
    if (day <= 0 || day > 31 || month <= 0 || month > 12 || year < 0)
        throw std::invalid_argument("������������ ����!");
    birthday[0] = day; birthday[1] = month; birthday[2] = year;
}

std::string SIGN::getSurname() const { return surname; }
std::string SIGN::getName() const { return name; }
std::string SIGN::getZodiacSign() const { return zodiacSign; }
void SIGN::getBirthday(int& day, int& month, int& year) const {
    day = birthday[0]; month = birthday[1]; year = birthday[2];
}

// ���������� ����������
std::ostream& operator<<(std::ostream& os, const SIGN& sign) {
    os << "���: " << sign.surname << " " << sign.name << ", ���� �������: " << sign.zodiacSign
        << ", ���� ��������: " << sign.birthday[0] << "." << sign.birthday[1] << "." << sign.birthday[2];
    return os;
}

std::istream& operator>>(std::istream& is, SIGN& sign) {
    std::cout << "������� �������: ";
    is >> sign.surname;
    std::cout << "������� ���: ";
    is >> sign.name;
    std::cout << "������� ���� �������: ";
    is >> sign.zodiacSign;
    std::cout << "������� ���� �������� (����, �����, ���): ";
    is >> sign.birthday[0] >> sign.birthday[1] >> sign.birthday[2];
    return is;
}

// ��������� �� ����� �������
bool SIGN::operator<(const SIGN& other) const {
    return zodiacSign < other.zodiacSign;
}
