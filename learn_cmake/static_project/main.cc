#include "util/calculator.h"
#include "definition/error_code.h"
#include <iostream>

int main()
{
    double a{ 0 };
    std::cin >> a;
    double exp2{ 0 };
    int ret_val = Calculator::GetInstance().Exp2(exp2, a);
    if (ret_val != exit_success)
    {
        return ret_val;
    }
    std::cout << exp2 << std::endl;
    return exit_success;
}