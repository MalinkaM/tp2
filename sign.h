#ifndef SIGN_H
#define SIGN_H

#include <iostream>
#include <string>

class SIGN {
private:
    std::string surname;
    std::string name;
    std::string zodiacSign;
    int birthday[3]; // [day, month, year]

public:
    // ������������
    SIGN();
    SIGN(const std::string& surname, const std::string& name, const std::string& zodiacSign, int day, int month, int year);
    SIGN(const SIGN& other);

    // ����������
    ~SIGN();

    // ������ �������
    void setSurname(const std::string& surname);
    void setName(const std::string& name);
    void setZodiacSign(const std::string& zodiacSign);
    void setBirthday(int day, int month, int year);

    std::string getSurname() const;
    std::string getName() const;
    std::string getZodiacSign() const;
    void getBirthday(int& day, int& month, int& year) const;

    // ���������� ����������
    friend std::ostream& operator<<(std::ostream& os, const SIGN& sign);
    friend std::istream& operator>>(std::istream& is, SIGN& sign);

    // ��������� �� ����� ������� (��� ����������)
    bool operator<(const SIGN& other) const;
};

#endif // SIGN_H
