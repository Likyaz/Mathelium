/*
 * Class Vector
 * Likyaz
 * 06/10/18
 *
*/

#ifndef MATHELIUM_VECTOR_H
#define MATHELIUM_VECTOR_H

#include <vector>
#include <iostream>


namespace mathelium
{
    template<class TYPE>
    class Vector {
    public:
        Vector() = default; // crée un vector vide, de size 0
        explicit Vector(unsigned int size); // crée un vector de la taille demander
        Vector(const Vector &vector);

        virtual ~Vector() = default;

        Vector& operator=(const TYPE &value);       // Affectation scalair, met tout les valeur du vecteur a la valeur demander
        Vector& operator=(const Vector &vector);    // Affectation de copy

        void resize(unsigned int size);
        void setValue(unsigned int it, TYPE value);

        double& operator() (int x);

        virtual void copy(const Vector &vector);

        virtual void operator+=(const TYPE &value);
        virtual void operator-=(const TYPE &value);
        virtual void operator*=(const TYPE &value);
        virtual void operator/=(const TYPE &value);

        virtual void operator+=(const Vector<TYPE> &vector);
        virtual void operator-=(const Vector<TYPE> &vector);


        template<typename T>
        friend std::ostream& operator<<(std::ostream &os, const Vector<T> &vector);

        template<typename T>
        friend Vector<T> operator+(const Vector<T> &a, const T &b);

        template<typename T>
        friend Vector<T> operator-(const Vector<T> &a, const T &b);

        template<typename T>
        friend Vector<T> operator*(const Vector<T> &a, const T &b);

        template<typename T>
        friend Vector<T> operator/(const Vector<T> &a, const T &b);

        template<typename T>
        friend Vector<T> operator+(const Vector<T> &a, const Vector<T> &b);

        template<typename T>
        friend Vector<T> operator-(const Vector<T> &a, const Vector<T> &b);

    protected:
        std::vector<TYPE> _data;
    };

}

#include "../src/Vector.hpp"


#endif //MATHELIUM_VECTOR_H
