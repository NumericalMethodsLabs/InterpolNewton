//
// Created by vadim on 31.03.2021.
//

#include "InterpolNewton.h"

InterpolNewtonErr_e InterpolNewton::Init(std::vector<double> x, std::vector<double> f_x) {
    InterpolNewtonErr_e err = IN_ERR_OK;
    if (x.size() != f_x.size())
        err = IN_ERR_SIZE_ERR;
    else {
        _x = x;
        _f_x = f_x;
        _generate_coefs();
    }
    return err;
}

double InterpolNewton::CalcInPoint(double p) {
    double sum = 0;
    double mult;
    for (int i = 0; i < _divdiff_coefs.size(); ++i) {
        mult = 1;
        for (int j = 0; j < i; ++j) {
            mult *= (p - _x.at(j));
        }
        sum += (mult * _divdiff_coefs.at(i));
    }
    return sum;
}

std::valarray<double> InterpolNewton::CalcInPoints(std::valarray<double> p) {
    std::valarray<double> retv(p.size());

    for (unsigned i = 0; i < p.size(); ++i)
        retv[i] = CalcInPoint(p[i]);

    return retv;
}

double InterpolNewton::_calc_coef(int iter) {
    double res;
    if (iter == 0)
        return _f_x.at(0);
    for (int i = 0; i < _f_x.size() - 1; ++i)
        _f_x.at(i) = (_f_x.at(i + 1) - _f_x.at(i)) / (_x.at(i + iter) - _x.at(i));
    res = _f_x.at(0);
    _f_x.erase(_f_x.end() - 1);
    return res;
}

void InterpolNewton::_generate_coefs() {
    for (int i = 0; i < _x.size(); ++i)
        _divdiff_coefs.push_back(_calc_coef(i));
}