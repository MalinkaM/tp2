#include "SIGN.h"

const std::string& SIGN::getName() const {
    return name;
}

void SIGN::setName(const std::string& name) {
    SIGN::name = name;
}

const std::string& SIGN::getSurname() const {
    return surname;
}

void SIGN::setSurname(const std::string& surname) {
    SIGN::surname = surname;
}

const std::string& SIGN::getZodiac() const {
    return zodiac;
}

void SIGN::setZodiac(const std::string& zodiac) {
    SIGN::zodiac = zodiac;
}

const int* SIGN::getBirthday() const {
    return birthday;
}

void SIGN::setBirthday(const int* birth) {
    if (birth != nullptr) for (int i = 0; i < 3; i++) birthday[i] = birth[i];
}


SIGN::SIGN(const std::string& n) {
    name = n;
    surname = "";
    zodiac = "";
    int arr[3] = { 1, 1, 1970 };
    setBirthday(arr);

    std::cout << "Создан объект SIGN с использованием упрощенного конструктора:\n";
    this->operator<<(std::cout);
}

SIGN::SIGN() {
    name = "неопределенный пользователь";
    surname = "";
    zodiac = "";
    int arr[3] = { 1, 1, 1970 };
    setBirthday(arr);
}


SIGN::SIGN(const SIGN& another) {
    name = another.getName();
    surname = another.getSurname();
    zodiac = another.getZodiac();
    setBirthday(another.getBirthday());

    std::cout << "Создан объект SIGN с использованием конструктора копирования:\n";
    this->operator<<(std::cout);
}

SIGN::SIGN(const std::string& name, const std::string& surname, const std::string& zodiac, int* birth) {
    SIGN::name = name;
    SIGN::surname = surname;
    SIGN::zodiac = zodiac;
    setBirthday(birth);

    std::cout << "Создан объект SIGN с использованием полного конструктора:\n";
    this->operator<<(std::cout);
}

std::ostream& SIGN::operator<<(std::ostream& os) {
    os << "Имя:        " << name << "\n";
    os << "Фамилия:    " << surname << "\n";
    os << "Знак зодиака: " << zodiac << "\n";
    os << "Дата рождения: " << birthday[0] << "." << birthday[1] << "." << birthday[2] << "\n";
    return os;
}

SIGN::~SIGN() {
    std::cout << "Удален объект SIGN с использованием деструктора:\n";
    this->operator<<(std::cout);
}

