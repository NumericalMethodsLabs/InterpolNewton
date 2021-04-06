//
// Created by vadim on 31.03.2021.
//

#ifndef INTERPOLATION_INTERPOLNEWTON_H
#define INTERPOLATION_INTERPOLNEWTON_H

#include <array>
#include <vector>
#include <valarray>

enum InterpolNewtonErr_e {
    IN_ERR_OK = 0U,
    IN_ERR_SIZE_ERR
};

class InterpolNewton {
    std::vector<double> _x;
    std::vector<double> _f_x;
    std::vector<double> _divdiff_coefs;

    double _calc_coef(int iter);

    void _generate_coefs();

public:
    InterpolNewton() = default;

    InterpolNewtonErr_e Init(std::vector<double> x, std::vector<double> f_x);

    double CalcInPoint(double p);

    std::valarray<double> CalcInPoints(std::valarray<double> p);
};

#endif //INTERPOLATION_INTERPOLNEWTON_H
