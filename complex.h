#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

class Complex
{
private:
    double real;    //действительная часть комплексного числа
    double imaginary;   //мнимая часть комплексного числа

public:
    Complex();
    Complex(double real, double imaginary);
    Complex(const Complex &other);  //конструктор копирования
    const Complex &operator=(const Complex &other); //оператор присваивания

    double getReal() const {
        return real;
    }
    double getImaginary() const {
        return imaginary;
    }
    Complex conj();
    void Display();
};

//ostream &operator<<(ostream &out, const Complex &c);

Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c1, double d);
Complex operator+(double d, const Complex &c1);

Complex operator-(const Complex &c1, const Complex &c2);
Complex operator-(const Complex &c1, double d);
Complex operator-(double d, const Complex &c1);

Complex operator*(const Complex &c1, const Complex &c2);
Complex operator/(const Complex &c1, const Complex &c2);

bool operator==(const Complex &c1, const Complex &c2);
bool operator!=(const Complex &c1, const Complex &c2);
bool operator<(const Complex &c1, const Complex &c2);
bool operator<=(const Complex &c1, const Complex &c2);
bool operator>(const Complex &c1, const Complex &c2);
bool operator>=(const Complex &c1, const Complex &c2);

#endif /* COMPLEX_H_ */