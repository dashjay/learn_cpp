#ifndef UTIL_CALCULATOR_H
#define UTIL_CALCULATOR_H

#include "singleton.h"
#include "../definition/error_code.h"
#include <limits>
#include <cmath>

class Calculator : public Singleton<Calculator>
{
public:
    template<typename ValueType>
    ValueType ValueTypeMax(ValueType)
    {
        return std::numeric_limits<ValueType>::max();
    }

    int Exp2(double &exp2, const double &val);
};

#endif