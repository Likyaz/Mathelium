#include <iostream>

#include "mathelium.h"

int main() {

    {// les vector dans mathelium
        mathelium::Vector<double> vecA;
        vecA.resize(3);
        vecA.setValue(0,1.0);
        vecA.setValue(1,2.0);
        vecA.setValue(2,3.0);
        std::cout << "vecA = \n" << vecA << std::endl;

        mathelium::Vector<double> vecB(3);
        vecB(0) = 4.0;
        vecB(1) = 5.0;
        vecB(2) = 6.0;
        std::cout << "vecB = \n" << vecB << std::endl;

        mathelium::Vector<double> vecC = vecB;
        vecC += 3;
        std::cout << "vecC = \n" << vecC << std::endl;

        vecA = vecC + 3.0;
        std::cout << "vecA = \n" << vecA << std::endl;
    }



    {// les Matrix dans mathelium
        mathelium::Matrix<double> a(5,2);
        int it = 0;
        for(int i(0); i < 5; i++)
            for(int j(0); j < 2; j++)
                a(i,j) = it++;


        std::cout << "a = \n" << a << std::endl;

        mathelium::Matrix<double> b(2, 3);
        for(int i(0); i < 2; i++)
            for(int j(0); j < 3; j++)
                b(i,j) = j;
        b += 1;
        std::cout << "b = \n" << b << std::endl;

        mathelium::Matrix<double> r = a * b ;
        std::cout << "r = \n" << r << std::endl;
    }

    {// les Vec3D dans mathelium
        mathelium::Vec3D<int> a(1, 2, 3);
        std::cout << a << std::endl;
    }

    {
        mathelium::Complex a(0,1);
        a = 3 - a ;
        std::cout << a << std::endl;
    }
    return 0;
}