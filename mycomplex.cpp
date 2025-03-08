#include <iostream>
#include <cmath>
#include "mycomplex.h"
using namespace std;

/**
 * @brief Конструктор класса Complex
 *
 * Инициализирует комплексное число с заданными действительной и мнимой частями.
 * Если параметры не переданы, присваивает значения 0.
 *
 * @param aRe Действительная часть комплексного числа
 * @param aIm Мнимая часть комплексного числа
 */
Complex::Complex(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief Конструктор копирования класса Complex
 *
 * Создает новый объект на основе переданного объекта другого комплексного числа.
 *
 * @param aRval Другой объект типа Complex для копирования
 */
Complex::Complex(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
}

/**
 * @brief Деструктор класса Complex
 *
 * Обнуляет действительную и мнимую части комплексного числа.
 */
Complex::~Complex() {
    Re = 0.0;
    Im = 0.0;
}

/**
 * @brief Устанавливает значения действительной и мнимой частей комплексного числа.
 *
 * @param aRe Действительная часть
 * @param aIm Мнимая часть
 */
void Complex::Set(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief Преобразует комплексное число в его абсолютное значение (модуль).
 *
 * @return Абсолютное значение комплексного числа
 */
Complex::operator double() {
    return abs();
}

/**
 * @brief Вычисляет модуль комплексного числа.
 *
 * @return Модуль комплексного числа
 */
double Complex::abs() {
    return sqrt(Re * Re + Im * Im);
}

/**
 * @brief Оператор сложения для комплексных чисел.
 *
 * @param aRval Второе комплексное число
 * @return Результат сложения двух комплексных чисел
 */
Complex Complex::operator+(const Complex& aRval) {
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}

/**
 * @brief Оператор вычитания для комплексных чисел.
 *
 * @param aRval Второе комплексное число
 * @return Результат вычитания второго комплексного числа из первого
 */
Complex Complex::operator-(const Complex& aRval) {
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/**
 * @brief Оператор сложения комплексного числа и действительного числа.
 *
 * @param aRval Действительное число
 * @return Результат сложения комплексного числа и действительного числа
 */
Complex Complex::operator+(const double& aRval) {
    Complex result;
    result.Re = Re + aRval;
    result.Im = Im;
    return result;
}

/**
 * @brief Оператор вычитания комплексного числа и действительного числа.
 *
 * @param aRval Действительное число
 * @return Результат вычитания действительного числа из комплексного числа
 */
Complex Complex::operator-(const double& aRval) {
    Complex Result(*this);
    Result.Re = Re - aRval;
    return Result;
}

/**
 * @brief Оператор умножения для комплексных чисел.
 *
 * @param aRval Второе комплексное число
 * @return Результат умножения двух комплексных чисел
 */
Complex Complex::operator*(const Complex& aRval) {
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

/**
 * @brief Оператор умножения комплексного числа на действительное число.
 *
 * @param aRval Действительное число
 * @return Результат умножения комплексного числа на действительное число
 */
Complex Complex::operator*(const double& aRval) {
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;
}

/**
 * @brief Оператор деления комплексного числа на действительное число.
 *
 * @param aRval Действительное число
 * @return Результат деления комплексного числа на действительное число
 */
Complex Complex::operator/(const double& aRval) {
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}

/**
 * @brief Оператор добавления для комплексных чисел (с присваиванием).
 *
 * @param aRval Второе комплексное число
 * @return Ссылка на текущий объект с результатом сложения
 */
Complex& Complex::operator+=(const Complex& aRval) {
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

/**
 * @brief Оператор вычитания для комплексных чисел (с присваиванием).
 *
 * @param aRval Второе комплексное число
 * @return Ссылка на текущий объект с результатом вычитания
 */
Complex& Complex::operator-=(const Complex& aRval) {
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

/**
 * @brief Оператор умножения для комплексных чисел (с присваиванием).
 *
 * @param aRval Второе комплексное число
 * @return Ссылка на текущий объект с результатом умножения
 */
Complex& Complex::operator*=(const Complex& aRval) {
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

/**
 * @brief Оператор добавления для комплексного числа и действительного числа (с присваиванием).
 *
 * @param aRval Действительное число
 * @return Ссылка на текущий объект с результатом сложения
 */
Complex& Complex::operator+=(const double& aRval) {
    Re += aRval;
    return *this;
}

/**
 * @brief Оператор вычитания для комплексного числа и действительного числа (с присваиванием).
 *
 * @param aRval Действительное число
 * @return Ссылка на текущий объект с результатом вычитания
 */
Complex& Complex::operator-=(const double& aRval) {
    Re -= aRval;
    return *this;
}

/**
 * @brief Оператор умножения для комплексного числа и действительного числа (с присваиванием).
 *
 * @param aRval Действительное число
 * @return Ссылка на текущий объект с результатом умножения
 */
Complex& Complex::operator*=(const double& aRval) {
    Re *= aRval;
    Im *= aRval;
    return *this;
}

/**
 * @brief Оператор деления для комплексного числа и действительного числа (с присваиванием).
 *
 * @param aRval Действительное число
 * @return Ссылка на текущий объект с результатом деления
 */
Complex& Complex::operator/=(const double& aRval) {
    Re /= aRval;
    Im /= aRval;
    return *this;
}

/**
 * @brief Оператор присваивания для копирования значений из другого комплексного числа.
 *
 * @param aRval Второй объект комплексного числа
 * @return Ссылка на текущий объект с результатом присваивания
 */
Complex& Complex::operator=(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

/**
 * @brief Оператор присваивания для присваивания значения действительного числа.
 *
 * @param aRval Действительное число
 * @return Ссылка на текущий объект с результатом присваивания
 */
Complex& Complex::operator=(const double& aRval) {
    Re = aRval;
    Im = 0.0;
    return *this;
}

/**
 * @brief Оператор ввода для комплексного числа.
 *
 * Ожидает ввод действительной и мнимой частей числа через поток.
 *
 * @param stream Поток ввода
 * @param a Комплексное число для ввода
 * @return Ссылка на поток ввода
 */
istream& operator>>(istream& stream, Complex& a) {
    char tmp[256];
    stream >> a.Re >> a.Im >> tmp;
    return stream;
}

/**
 * @brief Оператор вывода для комплексного числа.
 *
 * Выводит комплексное число в формате "Re + Im*i".
 *
 * @param stream Поток вывода
 * @param a Комплексное число для вывода
 * @return Ссылка на поток вывода
 */
ostream& operator<<(ostream& stream, Complex& a) {
    stream << a.Re;
    if (!(a.Im < 0)) stream << '+';
    stream << a.Im << 'i';
    return stream;
}

/**
 * @brief Оператор сложения для комплексного числа и действительного числа.
 *
 * @param aLval Действительное число
 * @param aRval Комплексное число
 * @return Результат сложения
 */
Complex operator+(const double& aLval, const Complex& aRval) {
    Complex Result;
    Result.Re = aLval + aRval.Re;
    Result.Im = aRval.Im;
    return Result;
}

/**
 * @brief Оператор вычитания для комплексного числа и действительного числа.
 *
 * @param aLval Действительное число
 * @param aRval Комплексное число
 * @return Результат вычитания
 */
Complex operator-(const double& aLval, const Complex& aRval) {
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im = -aRval.Im;
    return Result;
}

/**
 * @brief Оператор умножения для комплексного числа и действительного числа.
 *
 * @param aLval Действительное число
 * @param aRval Комплексное число
 * @return Результат умножения
 */
Complex operator*(const double& aLval, const Complex& aRval) {
    Complex r;
    r.Re = aLval * aRval.Re;
    r.Im = aLval * aRval.Im;
    return r;
}
