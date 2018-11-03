#include "../include/Algorithme.h"

namespace mathelium
{
    mathelium::Vector<double> multiLinearRegression(mathelium::Matrix<double> in, mathelium::Vector<double> out, double precision, int itMax)
    {
        mathelium::Vector<double> weight(in.getSizeRow() + 1);
        std::minstd_rand0 random;
        std::normal_distribution<double> distribution (0.0,1.0);
        for(int i(0); i < weight.size(); i++)
            weight(i) = distribution(random);
        double epsi = 0;
        double pre = 0;


        for(int it(0); it < itMax; it++) {
            for(int i(0); i < in.getSizeColumn(); i++) {
                pre = weight(0);
                for(int j(0); j < in.getSizeRow(); j++) {
                    pre += weight(j + 1) * in(i, j);
                }
                epsi = out(i) - pre;
                weight(0) += epsi * 0.1;
                for(int j(0); j < in.getSizeRow(); j++) {
                    weight(j + 1) += in(i, j) * epsi * 0.1;
                }
            }
            if(fabs(epsi) < precision)
                break;
        }
        return weight;
    }


}
