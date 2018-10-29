//
// Created by louis on 29/10/2018.
//

#ifndef MATHELIUM_VEC3D_H
#define MATHELIUM_VEC3D_H

#include "Vector.h"

namespace mathelium
{
    template<typename TYPE>
    class Vec3D : public Vector<TYPE>
    {
    public:
        Vec3D();
        explicit Vec3D(TYPE x, TYPE y, TYPE z);
        ~Vec3D() = default;

        void operator+=(const Vec3D &vector);
        void operator-=(const Vec3D &vector);

        void operator+=(const TYPE &value);
        void operator-=(const TYPE &value);
        void operator*=(const TYPE &value);
        void operator/=(const TYPE &value);
    };
}


#include "../src/Vec3D.hpp"

#endif //MATHELIUM_VEC3_H
