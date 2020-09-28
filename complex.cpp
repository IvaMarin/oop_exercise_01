#include "complex.h"
#include <cmath>

/*
ostream &operator<<(ostream &out, const Complex &c) {
        out << "(" << c.getReal() << ", " << c.getImaginary() << ")" << endl;
        return out;
    }
*/
Complex operator+(const Complex &c1, const Complex &c2) {   //оператор сложения комплексных чисел
    return Complex(c1.getReal()+c2.getReal(), c1.getImaginary()+c2.getImaginary());
}

Complex operator+(const Complex &c1, double d) {   //оператор сложения комплексного числа и действительного
    return Complex(c1.getReal()+d, c1.getImaginary());
}

Complex operator+( double d, const Complex &c1) {   //оператор сложения действительного числа и комплексного
    return Complex(c1.getReal()+d, c1.getImaginary());
}


Complex operator-(const Complex &c1, const Complex &c2) {   //оператор вычитания комплексных чисел
    return Complex(c1.getReal()-c2.getReal(), c1.getImaginary()-c2.getImaginary());
}

Complex operator-(const Complex &c1, double d) {   //оператор вычитания комплексного числа и действительного
    return Complex(c1.getReal()-d, c1.getImaginary());
}

Complex operator-( double d, const Complex &c1) {   //оператор вычитания действительного числа и комплексного
    return Complex(d-c1.getReal(), c1.getImaginary());
}

Complex operator*(const Complex &c1, const Complex &c2) {
    return Complex(c1.getReal()*c2.getReal()-c1.getImaginary()*c2.getImaginary(), c1.getReal()*c2.getImaginary()+c1.getImaginary()*c2.getReal());
}

Complex operator/(const Complex &c1, const Complex &c2) {
    double r = c2.getReal() * c2.getReal() + c2.getImaginary() * c2.getImaginary();
    return Complex((c1.getReal()*c2.getReal()+c1.getImaginary()*c2.getImaginary()) / r, (c1.getImaginary()*c2.getReal()-c1.getReal()*c2.getImaginary()) / r);
    }

bool operator==(const Complex &c1, const Complex &c2) {
    return (c1.getReal() == c2.getReal() && c1.getImaginary() == c2.getImaginary());
}

bool operator!=(const Complex &c1, const Complex &c2) {
    return !(c1 == c2);
}

bool operator<(const Complex &c1, const Complex &c2) {
    return (sqrt(c1.getReal()*c1.getReal() + c1.getImaginary()*c1.getImaginary()) < sqrt(c2.getReal()*c2.getReal() + c2.getImaginary()*c2.getImaginary()));
}

bool operator<=(const Complex &c1, const Complex &c2) {
    return (c1 < c2) || (c1 == c2);
}

bool operator>(const Complex &c1, const Complex &c2) {
    return c2 < c1;
}

bool operator>=(const Complex &c1, const Complex &c2) {
    return c2 <= c1;
}

Complex Complex::conj() {
    return Complex(real, -(imaginary));
}

void Complex::Display() {
    cout << "(" << real << ", " << imaginary << ")" << endl;
}

Complex::Complex(): real(0), imaginary(0) {}    //Конструктор по умолчанию

Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) {}

Complex::Complex(const Complex &other) {
    real = other.real;
    imaginary = other.imaginary;
}   //конструктор копирования

const Complex &Complex::operator=(const Complex &other) {
    real = other.real;
    imaginary = other.imaginary;

    return *this;
}