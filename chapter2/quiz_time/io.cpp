#include "io.h"
#include <iostream>

int readNumber() {
    int in{};
    std::cout << "Please Input a number" << std::endl;
    std::cin >> in;
    return in;
}

void writeAnswer(int ans) { std::cout << "Ans is " << ans << std::endl; }
