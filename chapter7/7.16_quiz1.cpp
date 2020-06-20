#include <iostream>

int i{};

int getValue() {
    return 0;
}
int main() {
    int       j{}; // can not be implicitly captrued
    const int k{};
    const int v{getValue()}; // can not be implicitly captrued
    [ &j, &v ]() {
        std::cout << i << std::endl;
        std::cout << j << std::endl;
        std::cout << k << std::endl;
        std::cout << v << std::endl;
    }();

    return 0;
}
