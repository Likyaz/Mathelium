/*
 * Class Matrix
 * Likyaz aka L.Phi
 * 07/10/18
 *
*/

#ifndef MATHELIUM_MATRIX_H
#define MATHELIUM_MATRIX_H

#include <vector>
#include <iostream>

namespace mathelium
{
    template<typename TYPE>
    class Matrix {
    public:
        Matrix();
        explicit Matrix(unsigned int sizeColumn, unsigned int sizeRow);
        Matrix(Matrix const& matrix);
        virtual ~Matrix();

        void resize(unsigned int sizeColumn, unsigned int sizeRow);
        void set(unsigned int itColumn, unsigned int itRow, TYPE value);

        TYPE& operator() (unsigned int itColumn, unsigned int itRow);
        TYPE get(unsigned int itColumn, unsigned int itRow);
        unsigned int getSizeColumn();
        unsigned int getSizeRow();
        unsigned int getSize();

        void copy(Matrix const& matrix);

        void operator+=(const TYPE &value);
        void operator-=(const TYPE &value);
        void operator*=(const TYPE &value);
        void operator/=(const TYPE &value);

        void operator+=(const Matrix<TYPE> &value);
        void operator-=(const Matrix<TYPE> &value);

        Matrix& operator=(TYPE const& value);
        Matrix& operator=(Matrix const& matrix);

        template<typename T>
        friend std::ostream& operator<<(std::ostream& os, Matrix<T> const& matrix);

        template<typename T>
        friend Matrix<T> operator+(const Matrix<T> &a, const Matrix<T> &b);

        template<typename T>
        friend Matrix<T> operator-(const Matrix<T> &a, const Matrix<T> &b);

        template<typename T>
        friend Matrix<T> operator*(const Matrix<T> &a, const Matrix<T> &b);


        template<typename T>
        friend Matrix<T> operator+(const Matrix<T> &a, const T &b);

        template<typename T>
        friend Matrix<T> operator-(const Matrix<T> &a, const T &b);

        template<typename T>
        friend Matrix<T> operator*(const Matrix<T> &a, const T &b);

        template<typename T>
        friend Matrix<T> operator/(const Matrix<T> &a, const T &b);

    private:
        TYPE* _data;
        unsigned int _sizeColumn, _sizeRow, _size;
    };

}

#include "../src/Matrix.hpp"


#endif //MATHELIUM_MATRIX_H
