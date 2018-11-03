//
// Created by louis on 30/10/2018.
//

#ifndef MATHELIUM_ALGORITHME_H
#define MATHELIUM_ALGORITHME_H

#include <random>
#include <cmath>
#include "Vector.h"
#include "Matrix.h"

namespace mathelium
{
    // equation type f(x) = a + bx + cx + ... + px
    mathelium::Vector<double> multiLinearRegression(mathelium::Matrix<double> in, mathelium::Vector<double> out, double precision = 0.01, int itMax = 100);

}


#endif //MATHELIUM_ALGORITHME_H
