#include "Container.h"

Container::Container(unsigned number)
{
    if (number == 0) throw std::invalid_argument("������� 0 ��������!");
    arr = new SIGN * [number];
    size = 0;
    real_size = number;
}

Container::Container()
{
    arr = new SIGN * [10];
    size = 0;
    real_size = 10;
}

Container::Container(const Container& another)
{
    unsigned i;
    for (i = 0; i < size; i++) delete arr[i];

    arr = new SIGN * [another.real_size];
    size = another.size;
    real_size = another.real_size;

    for (i = 0; i < size; i++) arr[i] = another.arr[i];
    sort();
}

Container::~Container()
{
    if (!isEmpty()) for (unsigned i = 0; i < size; i++) delete arr[i];
    if (real_size != 0) delete[] arr;
}

void Container::add(SIGN* a)
{
    if (size < real_size) {
        arr[size] = a;
        size++;
    }
    else {
        SIGN** cpy_arr = new SIGN * [size > 0 ? size : 10];
        for (int i = 0; i < size; i++) cpy_arr[i] = arr[i];
        delete[] arr;
        arr = new SIGN * [real_size > 0 ? real_size * 2 : 10];
        real_size > 0 ? real_size = real_size * 2 : real_size = 10;
        for (int i = 0; i < size; i++) arr[i] = cpy_arr[i];
        delete[] cpy_arr;

        arr[size] = a;
        size++;
    }
    sort();

}

void Container::remove(unsigned index) {
    if (index >= size) throw std::out_of_range("������ �� ��������� ���������!");

    delete arr[index];

    SIGN** cpy_arr = new SIGN * [size];
    for (int i = index + 1; i < size; i++) cpy_arr[i - 1] = arr[i];

    size--;
    for (int i = index; i < size; i++) arr[i] = cpy_arr[i];
    delete[] cpy_arr;
    sort();
}

bool Container::isEmpty() const {
    return size == 0;
}

int Container::length() {
    return size;
}

void Container::clear() {
    if (isEmpty()) return;
    for (int i = 0; i < size; i++) delete arr[i];
    delete[] arr;
    size = 0;
    real_size = 10;
    arr = new SIGN * [10];
}

SIGN* Container::operator[](unsigned index)
{
    if (index >= size) throw std::out_of_range("������ �� ��������� ���������!");
    else return arr[index];
}

std::ostream& Container::operator<<(std::ostream& os)
{
    sort();
    os << size << "\n";
    if (isEmpty()) os << "��������� ����!\n";
    for (int i = 0; i < size; i++) arr[i]->operator<<(os);
    return os;
}

void Container::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            const std::string& zodiac1 = arr[i]->getZodiac();
            const std::string& zodiac2 = arr[j]->getZodiac();
            if (zodiac1 > zodiac2) {
                swap(i, j);
            }
        }
    }
}


void Container::swap(unsigned int a, unsigned int b) {
    SIGN* buf = arr[b];
    arr[b] = arr[a];
    arr[a] = buf;
}
