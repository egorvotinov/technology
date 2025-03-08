#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_

#include <iostream>

class Complex {
private:
    double Re;
    double Im;

public:
    // Конструктор по умолчанию и копирования
    Complex(double aRe = 0, double aIm = 0);
    Complex(const Complex& other);

    // Деструктор
    ~Complex();

    // Методы
    void Set(double aRe, double aIm = 0);
    double abs() const;

    // Операторы
    operator double() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator+(const double& value) const;
    Complex operator-(const double& value) const;
    Complex operator*(const Complex& other) const;
    Complex operator*(const double& value) const;
    Complex operator/(const double& value) const;

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator+=(const double& value);
    Complex& operator-=(const double& value);
    Complex& operator*=(const double& value);
    Complex& operator/=(const double& value);

    Complex& operator=(const Complex& other);
    Complex& operator=(const double& value);

    // Друзья
    friend std::istream& operator>>(std::istream& in, Complex& complex);
    friend std::ostream& operator<<(std::ostream& out, const Complex& complex);
};

#endif
