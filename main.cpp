#include <iostream>
#include <random>


#include "mathelium.h"

int main() {


    {// les Vector dans mathelium
        std::cout << "\n\nVector :\n" << std::endl;
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
        std::cout << "\n\nMatrix :\n" << std::endl;
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
        std::cout << "\n\nVec3D :\n" << std::endl;
        mathelium::Vec3D<int> a(1, 2, 3);
        std::cout << a << std::endl;
    }

    {// les Complex dans mathelium
        std::cout << "\n\nComplex :\n" << std::endl;
        mathelium::Complex a(0,1);
        mathelium::Complex b(1,2);
        a -= b;
        mathelium::Complex r = a + b;

        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "r = " << r << std::endl;

        std::cout << "Module de A " << a.mod() << std::endl;
        std::cout << "Argument de A " << a.arg() << std::endl;
    }

    {//les fonction algorithme  dans mathelium
        std::cout << "\n\nlinearRegression :\n" << std::endl;
        // LinearRegression f(x)= 1.13 + 2.5x - 3.33x
        mathelium::Matrix<double> in(10, 2);
        mathelium::Vector<double> out(10);
        double a = 1.13;
        double b = 2.5;
        double c = -3.33;
        std::minstd_rand0 random;
        std::uniform_real_distribution<double> distribution (-2,2);
        for(int i(0); i < 10; i++)
        {
            in(i, 0) = distribution(random);
            in(i, 1) = distribution(random);
            out(i) = a + b * in(i, 0) + c * in(i, 1);
        }

        mathelium::Vector<double> coef = mathelium::multiLinearRegression(in, out, 0.01);
        std::cout << "Resulta :" << std::endl;
        std::cout << "a = " << coef(0) << "\n" <<
                  "b = " << coef(1) << "\n" <<
                  "c = " << coef(2) << "\n" << std::endl;


        std::cout << "Erreur :" << std::endl;
        std::cout << "deltaA = " << a - coef(0) << "\n" <<
                  "deltaB = " << b - coef(1) << "\n" <<
                  "deltaC = " << c - coef(2) << "\n" << std::endl;
    }


    return 0;
}