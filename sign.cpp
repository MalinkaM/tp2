#include "sign.h"

// Конструкторы
SIGN::SIGN() {
    std::cout << "Вызван конструктор без параметров.\n";
    surname = name = zodiacSign = "";
    birthday[0] = birthday[1] = birthday[2] = 0;
}

SIGN::SIGN(const std::string& surname, const std::string& name, const std::string& zodiacSign, int day, int month, int year) {
    std::cout << "Вызван конструктор с параметрами.\n";
    this->surname = surname;
    this->name = name;
    this->zodiacSign = zodiacSign;
    this->birthday[0] = day;
    this->birthday[1] = month;
    this->birthday[2] = year;
}

SIGN::SIGN(const SIGN& other) {
    std::cout << "Вызван конструктор копирования.\n";
    surname = other.surname;
    name = other.name;
    zodiacSign = other.zodiacSign;
    birthday[0] = other.birthday[0];
    birthday[1] = other.birthday[1];
    birthday[2] = other.birthday[2];
}

// Деструктор
SIGN::~SIGN() {
    std::cout << "Вызван деструктор.\n";
}

// Методы доступа
void SIGN::setSurname(const std::string& surname) { this->surname = surname; }
void SIGN::setName(const std::string& name) { this->name = name; }
void SIGN::setZodiacSign(const std::string& zodiacSign) { this->zodiacSign = zodiacSign; }
void SIGN::setBirthday(int day, int month, int year) {
    if (day <= 0 || day > 31 || month <= 0 || month > 12 || year < 0)
        throw std::invalid_argument("Некорректная дата!");
    birthday[0] = day; birthday[1] = month; birthday[2] = year;
}

std::string SIGN::getSurname() const { return surname; }
std::string SIGN::getName() const { return name; }
std::string SIGN::getZodiacSign() const { return zodiacSign; }
void SIGN::getBirthday(int& day, int& month, int& year) const {
    day = birthday[0]; month = birthday[1]; year = birthday[2];
}

// Перегрузка операторов
std::ostream& operator<<(std::ostream& os, const SIGN& sign) {
    os << "ФИО: " << sign.surname << " " << sign.name << ", Знак зодиака: " << sign.zodiacSign
        << ", День рождения: " << sign.birthday[0] << "." << sign.birthday[1] << "." << sign.birthday[2];
    return os;
}

std::istream& operator>>(std::istream& is, SIGN& sign) {
    std::cout << "Введите фамилию: ";
    is >> sign.surname;
    std::cout << "Введите имя: ";
    is >> sign.name;
    std::cout << "Введите знак зодиака: ";
    is >> sign.zodiacSign;
    std::cout << "Введите дату рождения (день, месяц, год): ";
    is >> sign.birthday[0] >> sign.birthday[1] >> sign.birthday[2];
    return is;
}

// Сравнение по знаку зодиака
bool SIGN::operator<(const SIGN& other) const {
    return zodiacSign < other.zodiacSign;
}
