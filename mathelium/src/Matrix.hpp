//#include "Matrix.h"

namespace mathelium
{
    template<typename TYPE>
    Matrix<TYPE>::Matrix() {
        _data = new TYPE[9] {0};
        _sizeColumn = 3;
        _sizeRow = 3;
        _size = 9;
    }

    template<typename TYPE>
    Matrix<TYPE>::Matrix(unsigned int sizeColumn, unsigned int sizeRow) {
        _data = new TYPE[sizeRow * sizeColumn] {0};
        _sizeColumn = sizeColumn;
        _sizeRow = sizeRow;
        _size = _sizeRow * _sizeColumn;
    }

    template<typename TYPE>
    Matrix<TYPE>::Matrix(Matrix const& matrix) {
        copy(matrix);
    }

    template<typename TYPE>
    Matrix<TYPE>::~Matrix() {
        delete[] _data;
    }

    template<typename TYPE>
    void Matrix<TYPE>::resize(unsigned int sizeColumn, unsigned int sizeRow) {
        delete[] _data;
        _data = new TYPE[sizeColumn * sizeRow] {0};
        _sizeColumn = sizeColumn;
        _sizeRow = sizeRow;
        _size = _sizeRow * _sizeColumn;
    }

    template<typename TYPE>
    void Matrix<TYPE>::set(unsigned int itColumn, unsigned int itRow, TYPE value) {
        _data[itRow + (itColumn * _sizeRow)] = value;
    }

    template<typename TYPE>
    TYPE Matrix<TYPE>::get(unsigned int itColumn, unsigned int itRow) {
        return _data[itRow + (itColumn * _sizeRow)];
    }

    template<typename TYPE>
    unsigned int Matrix<TYPE>::getSizeColumn() {
        return _sizeColumn;
    }

    template<typename TYPE>
    unsigned int Matrix<TYPE>::getSizeRow() {
        return _sizeRow;
    }

    template<typename TYPE>
    unsigned int Matrix<TYPE>::getSize() {
        return _size;
    }

    template<typename TYPE>
    TYPE& Matrix<TYPE>::operator() (unsigned int itColumn, unsigned int itRow) {
        return _data[itRow + (itColumn * _sizeRow)];
    }



    template<typename TYPE>
    void Matrix<TYPE>::copy(Matrix const& matrix) {
        if(_data != NULL) delete[] _data;
        _data = new TYPE[matrix._sizeColumn * matrix._sizeRow] {0};
        for(int i(0); i < matrix._size; i++)
            _data[i] = matrix._data[i];
        _sizeColumn = matrix._sizeColumn;
        _sizeRow = matrix._sizeRow;
        _size = _sizeRow * _sizeColumn;
    }

    template<typename TYPE>
    void Matrix<TYPE>::operator+=(const TYPE &value) {
        for(unsigned int i(0); i < _size; i++) {
            _data[i] += value;
        }
    }

    template<typename TYPE>
    void Matrix<TYPE>::operator-=(const TYPE &value) {
        for(unsigned int i(0); i < _size; i++) {
            _data[i] -= value;
        }
    }

    template<typename TYPE>
    void Matrix<TYPE>::operator*=(const TYPE &value) {
        for(unsigned int i(0); i < _size; i++) {
            _data[i] *= value;
        }
    }

    template<typename TYPE>
    void Matrix<TYPE>::operator/=(const TYPE &value) {
        for(unsigned int i(0); i < _size; i++) {
            _data[i] /= value;
        }
    }

    template<typename TYPE>
    void Matrix<TYPE>::operator+=(const Matrix<TYPE> &value) {
        if(value._sizeColumn == _sizeColumn && value._sizeRow == _sizeRow) {
            for(unsigned int i(0); i < _size; i++) {
                _data[i] += value._data[i];
            }
        }
        else {
            std::cout << "Error Dimensional!" << std::endl;
        }
    }

    template<typename TYPE>
    void Matrix<TYPE>::operator-=(const Matrix<TYPE> &value) {
        if(value._sizeColumn == _sizeColumn && value._sizeRow == _sizeRow) {
            for(unsigned int i(0); i < _size; i++) {
                _data[i] -= value._data[i];
            }
        }
        else {
            std::cout << "Error Dimensional!" << std::endl;
        }
    }

    template<typename TYPE>
    Matrix<TYPE>& Matrix<TYPE>::operator=(TYPE const& value) {
        for(int i(0); i < _size; i++)
            _data[i] = value;
    }

    template<typename TYPE>
    Matrix<TYPE>& Matrix<TYPE>::operator=(Matrix<TYPE> const& matrix) {
        copy(matrix);
    }


    template<typename T>
    std::ostream& operator<<(std::ostream& os, Matrix<T> const& matrix) {
        for(unsigned int c(0); c < matrix._sizeColumn; c++) {
            for (unsigned int r(0); r < matrix._sizeRow; r++)
                os << matrix._data[r + (c * matrix._sizeRow)] << ' ';
            os << '\n';
        }
        return os;
    }

    template<typename T>
    Matrix <T> operator+(const Matrix <T> &a, const Matrix <T> &b) {
        Matrix<T> r = a;
        r += b;
        return r;
    }

    template<typename T>
    Matrix <T> operator-(const Matrix <T> &a, const Matrix <T> &b) {
        Matrix<T> r;
        r -= b;
        return r;
    }

    template<typename T>
    Matrix <T> operator*(const Matrix <T> &a, const Matrix <T> &b) {
        if(a._sizeRow == b._sizeColumn) {
            Matrix<T> result(a._sizeColumn, b._sizeRow);
            for (int c = 0; c < result._sizeColumn; ++c) {
                for (int r = 0; r < result._sizeRow; ++r) {
                    for (int it = 0; it < a._sizeRow; ++it) {
                        result(c, r) += a._data[it + (c * a._sizeRow)] * b._data[r + (it * b._sizeRow)];
                    }
                }
            }
            return result;
        }
        else {
            std::cout << "Error dimensional si not just!" << std::endl;
            return Matrix<T>(1,1);
        }
    }

    template<typename T>
    Matrix <T> operator+(const Matrix <T> &a, const T &b) {
        Matrix<T> r;
        r += b;
        return r;
    }

    template<typename T>
    Matrix <T> operator-(const Matrix <T> &a, const T &b) {
        Matrix<T> r;
        r -= b;
        return r;
    }

    template<typename T>
    Matrix <T> operator*(const Matrix <T> &a, const T &b) {
        Matrix<T> r;
        r -= b;
        return r;
    }

    template<typename T>
    Matrix <T> operator/(const Matrix <T> &a, const T &b) {
        Matrix<T> r;
        r -= b;
        return r;
    }
}