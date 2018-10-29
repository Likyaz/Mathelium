//
// Created by louis on 29/10/2018.
//

#ifndef MATHELIUM_COMPLEX_H
#define MATHELIUM_COMPLEX_H

#include <iostream>
#include <cmath>

namespace mathelium
{
    class Complex {
    public:
        Complex();
        Complex(double real, double imaginary);
        ~Complex() = default;

        void conjugate();
        double mod();
        double arg();


        void operator+=(const Complex &value);
        void operator-=(const Complex &value);
        void operator*=(const Complex &value);
        void operator/=(const Complex &value);

        void operator+=(const double &value);
        void operator-=(const double &value);
        void operator*=(const double &value);
        void operator/=(const double &value);

        Complex& operator=(const Complex &value);
        Complex& operator=(const double &value);

        friend std::ostream& operator<<(std::ostream& os, Complex const& complex);

        friend Complex operator+(const Complex &a, const Complex &b);
        friend Complex operator-(const Complex &a, const Complex &b);
        friend Complex operator*(const Complex &a, const Complex &b);
        friend Complex operator/(const Complex &a, const Complex &b);

        friend Complex operator+(const Complex &a, const double &b);
        friend Complex operator-(const Complex &a, const double &b);
        friend Complex operator*(const Complex &a, const double &b);
        friend Complex operator/(const Complex &a, const double &b);

        friend Complex operator+(const double &a, const Complex &b);
        friend Complex operator-(const double &a, const Complex &b);
        friend Complex operator*(const double &a, const Complex &b);
        friend Complex operator/(const double &a, const Complex &b);
    private:
        double _real;
        double _imaginary;
    };

}


#endif //MATHELIUM_COMPLEX_H
