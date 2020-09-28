/* Мариничев Иван М8О-208Б-19
 *
 * github: IvaMarin
 *
 *Реализовать класс Complex для работы с комплексными числами. Обязательно должны быть присутствовать операции
 *  -сложения add, (a, b) + (c, d) = (a + c, b + d);
 *  -вычитания sub, (a, b) – (c, d) = (a – c, b – d);
 *  -умножения mul, (a, b) ´ (c, d) = (ac – bd, ad + bc);
 *  -деления div, (a, b) / (c, d) = (ac + bd, bc – ad) / (c2 + d2);
 *  -сравнение equ, (a, b) = (c, d), если (a = c) и (b = d);
 *  -сопряженное число conj, conj(a, b) = (a, –b).
 *Реализовать операции сравнения модулей.
 */


#include <iostream>
#include <fstream>
#include "complex.h"

using namespace std;

int main () {
    cout << "Creating 2 complex class objects..." << endl;
    string test_name;
    cout << "Type test file name (e.g. test_01.txt) ";
    cout << "or type 'console' to enter them by yourself: ";
    cin >> test_name;
    double real_a, imaginary_b, real_c, imaginary_d;
    if (test_name != "console") {
        ifstream input;
        input.open(test_name);
        if (!input.is_open()) {
            cout << "File is not exists\n"; // если не открылся
            return -1;
        }
        input >> real_a >> imaginary_b >> real_c >> imaginary_d;
    }else {
        cout << "Enter real and imaginary parts of Complex 1: ";
        cin >> real_a >> imaginary_b;
        cout << "Enter real and imaginary parts of Complex 2: ";
        cin >> real_c >> imaginary_d;
    }
    cout << endl;

    Complex c1(real_a, imaginary_b);
    Complex c2(real_c, imaginary_d);
    cout << "Complex 1: ";
    c1.Display();
    cout << "Complex 2: ";
    c2.Display();
    cout << endl;

    Complex sum = c1 + c2;
    Complex dif = c1 - c2;
    Complex mul = c1 * c2;
    Complex div = c1 / c2 ;
    double r = c2.getReal() * c2.getReal() + c2.getImaginary() * c2.getImaginary();
    cout << "Sum of complex numbers: ";
    sum.Display();
    cout << "Difference of complex numbers: ";
    dif.Display();
    cout << "Product of complex numbers: ";
    mul.Display();
    if (r != 0) {
        cout << "Quotient of complex numbers: ";
        div.Display();
    } else {
        cout << "Can't divide those complex numbers";
    }
    cout << endl;

    Complex c1conj = c1.conj();
    Complex c2conj = c2.conj();
    cout << "Complex 1 conjugate: ";
    c1conj.Display();
    cout << "Complex 2 conjugate: ";
    c2conj.Display();
    cout << endl;

    cout << "Comparing absolute values of 2 complex numbers..." << endl;
    if (c1 != c2) {
        cout << "Absolute value of Complex 1 is not equal to Absolute value of Complex 2" << endl;
        if (c1 > c2) {
            cout << "Absolute value of Complex 1 is greater than Absolute value of Complex 2" << endl;
        }
        else {
            cout << "Absolute value of Complex 1 is lower than Absolute value of Complex 2" << endl;
        }
    }
    else {
        cout << "Absolute value of Complex 1 is equal to Absolute value of Complex 2" << endl;
    }
    cout << endl;

    cout << "As an addition we can add and subtract real numbers" << endl;
    Complex realadd = c1 + 8;
    Complex realsub = c2 - 15;
    cout << "Let's add 8  to Complex 1: " << endl;
    realadd.Display();
    cout << "Let's subtract 15  from Complex 2: " << endl;
    realsub.Display();
}