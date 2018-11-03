//#include "Vector.h"


namespace mathelium
{
    template<typename TYPE>
    Vector<TYPE>::Vector(unsigned int size) : _data(size, 0) {}

    template<typename TYPE>
    Vector<TYPE>::Vector(const Vector &vector) {
        _data = vector._data;
    }

    template<typename TYPE>
    int Vector<TYPE>::size(){
        return _data.size();
    }

    template<typename TYPE>
    void Vector<TYPE>::resize(unsigned int size) {
        _data.resize(size);
    }

    template<typename TYPE>
    void Vector<TYPE>::setValue(unsigned int it, TYPE value) {
        _data[it] = value;
    }


    template<typename TYPE>
    double& Vector<TYPE>::operator() (int x) {
        return _data[x];
    }

    template<typename TYPE>
    void Vector<TYPE>::copy(const Vector &vector) {
        _data = vector._data;
    }

    template<typename TYPE>
    void Vector<TYPE>::operator+=(const TYPE &value) {
        for (TYPE &i : _data)
            i += value;
    }

    template<typename TYPE>
    void Vector<TYPE>::operator-=(const TYPE &value) {
        for (TYPE &i : _data)
            i -= value;
    }

    template<typename TYPE>
    void Vector<TYPE>::operator*=(const TYPE &value) {
        for (TYPE &i : _data)
            i *= value;
    }

    template<typename TYPE>
    void Vector<TYPE>::operator/=(const TYPE &value) {
        for (TYPE &i : _data)
            i /= value;
    }
    template<typename TYPE>
    void Vector<TYPE>::operator+=(const Vector<TYPE> &vector) {
        if(_data.size() == vector._data.size())
            for (int i(0); i < vector._data.size(); i++)
                _data[i] += vector._data[i];
        else
            std::cout << "Error Dimensional!" << std::endl;

    }
    template<typename TYPE>
    void Vector<TYPE>::operator-=(const Vector<TYPE> &vector) {
        if(_data.size() == vector._data.size())
            for (int i(0); i < vector._data.size(); i++)
                _data[i] -= vector._data[i];
        else
        std::cout << "Error Dimensional!" << std::endl;
    }

    template<typename TYPE>
    Vector<TYPE>& Vector<TYPE>::operator=(const TYPE &value){
        for (double &i : _data)
            i = value;
    }

    template<typename TYPE>
    Vector<TYPE>& Vector<TYPE>::operator=(const Vector<TYPE> &vector){
        _data = vector._data;
    }


    template<typename T>
    std::ostream& operator<<(std::ostream &os, const Vector<T> &vector) {
        for (double i : vector._data)
            os << i << '\n';
        return os;
    }


    template<typename T>
    Vector<T> operator+(const Vector<T> &a, const T &b) {
        Vector<T> r = a;
        r += b;
        return r;
    }

    template<typename T>
    Vector<T> operator-(const Vector<T> &a, const T &b) {
        Vector<T> r = a;
        r -= b;
        return r;
    }

    template<typename T>
    Vector<T> operator*(const Vector<T> &a, const T &b) {
        Vector<T> r = a;
        r *= b;
        return r;
    }

    template<typename T>
    Vector<T> operator/(const Vector<T> &a, const T &b) {
        Vector<T> r = a;
        r /= b;
        return r;
    }

    template<typename T>
    Vector<T> operator+(const Vector<T> &a, const Vector<T> &b) {
        Vector<T> r = a;
        r += b;
        return r;
    }

    template<typename T>
    Vector<T> operator-(const Vector<T> & a, const Vector<T> & b) {
        Vector<T> r = a;
        r -= b;
        return r;
    }
}
