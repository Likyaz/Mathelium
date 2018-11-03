//
// Created by louis on 29/10/2018.
//

#include "../include/Complex.h"


namespace mathelium
{
    Complex::Complex() {
        _real = 0;
        _imaginary = 0;
    }

    Complex::Complex(double real, double imaginary) {
        _real = real;
        _imaginary = imaginary;
    }

    void Complex::conjugate() {
        _imaginary *= -1;
    }

    double Complex::mod() {
        return sqrt((_real * _real) + (_imaginary * _imaginary));
    }

    double Complex::arg() {
        return 2 * atan(_imaginary / (_real + mod()));
    }


    void Complex::operator+=(const Complex &value) {
        _real += value._real;
        _imaginary += value._imaginary;
    }

    void Complex::operator-=(const Complex &value) {
        _real -= value._real;
        _imaginary -= value._imaginary;
    }

    void Complex::operator*=(const Complex &value) {
        double tempReal = (_real * value._real) - (_imaginary * value._imaginary);
        _imaginary = (_real * value._imaginary) + (_imaginary * value._real);
        _real = tempReal;
    }

    void Complex::operator/=(const Complex &value) {
        double temp = (value._real * value._real) + (value._imaginary * value._imaginary);
        double tempReal = ((_real * value._real) + (_imaginary * value._imaginary)) / temp;
        _imaginary = ((_real * value._imaginary) - (_imaginary * value._real)) / temp;
        _real = tempReal;
    }


    void Complex::operator+=(const double &value) {
        _real += value;
    }

    void Complex::operator-=(const double &value) {
        _real -= value;
    }

    void Complex::operator*=(const double &value) {
        _real = _real * value;
        _imaginary = _imaginary * value;
    }

    void Complex::operator/=(const double &value) {
        _real = _real / value;
        _imaginary = _imaginary / value;
    }

    Complex& Complex::operator=(const Complex &value) {
        _real = value._real;
        _imaginary = value._imaginary;
    }

    Complex& Complex::operator=(const double &value) {
        _real = value;
        _imaginary = 0;
    }


    std::ostream& operator<<(std::ostream& os, Complex const& complex) {
        if(complex._real != 0) os << complex._real << ' ';
        if(complex._imaginary > 0 && complex._real) os << "+ ";
        if(complex._imaginary)os << complex._imaginary << "i";
        return os;
    }

    Complex operator+(const Complex &a, const Complex &b) {
        Complex r = a;
        r += b;
        return r;
    }

    Complex operator-(const Complex &a, const Complex &b) {
        Complex r = a;
        r -= b;
        return r;
    }

    Complex operator*(const Complex &a, const Complex &b) {
        Complex r = a;
        r *= b;
        return r;
    }

    Complex operator/(const Complex &a, const Complex &b) {
        Complex r = a;
        r /= b;
        return r;
    }


    Complex operator+(const Complex &a, const double &b) {
        Complex r = a;
        r += b;
        return r;
    }

    Complex operator-(const Complex &a, const double &b) {
        Complex r = a;
        r -= b;
        return r;
    }

    Complex operator*(const Complex &a, const double &b) {
        Complex r = a;
        r *= b;
        return r;
    }

    Complex operator/(const Complex &a, const double &b) {
        Complex r = a;
        r /= b;
        return r;
    }

    Complex operator+(const double &a, const Complex &b) {
        Complex r = b;
        r += a;
        return r;
    }

    Complex operator-(const double &a, const Complex &b) {
        Complex r;
        r = a;
        r -= b;
        return r;
    }

    Complex operator*(const double &a, const Complex &b) {
        Complex r = b;
        r *= a;
        return r;
    }

    Complex operator/(const double &a, const Complex &b) {
        Complex r;
        r = a;
        r /= b;
        return r;
    }

}