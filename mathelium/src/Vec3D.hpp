//
// Created by louis on 29/10/2018.
//


namespace mathelium
{
    template<typename TYPE>
    Vec3D<TYPE>::Vec3D() :
        Vector<TYPE>(3)
    {

    }

    template<typename TYPE>
    Vec3D<TYPE>::Vec3D(TYPE x, TYPE y, TYPE z) :
            Vector<TYPE>(3)
    {
        this->_data[0] = x;
        this->_data[1] = y;
        this->_data[2] = z;
    }

    template<typename TYPE>
    void Vec3D<TYPE>::operator+=(const TYPE &value) {
        this->_data[0] += value;
        this->_data[1] += value;
        this->_data[2] += value;
    }

    template<typename TYPE>
    void Vec3D<TYPE>::operator-=(const TYPE &value) {
        this->_data[0] -= value;
        this->_data[1] -= value;
        this->_data[2] -= value;
    }

    template<typename TYPE>
    void Vec3D<TYPE>::operator*=(const TYPE &value) {
        this->_data[0] *= value;
        this->_data[1] *= value;
        this->_data[2] *= value;
    }

    template<typename TYPE>
    void Vec3D<TYPE>::operator/=(const TYPE &value) {
        this->_data[0] /= value;
        this->_data[1] /= value;
        this->_data[2] /= value;
    }

    template<typename TYPE>
    void Vec3D<TYPE>::operator+=(const Vec3D &vector) {
        this->_data[0] += vector._data[0];
        this->_data[1] += vector._data[1];
        this->_data[2] += vector._data[2];
    }

    template<typename TYPE>
    void Vec3D<TYPE>::operator-=(const Vec3D &vector) {
        this->_data[0] -= vector._data[0];
        this->_data[1] -= vector._data[1];
        this->_data[2] -= vector._data[2];
    }

}