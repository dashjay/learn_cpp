#include <iostream>

inline int min(int x, int y) {
    return x > y ? y : x;
}

int main() {
    std::cout << min(5, 6) << std::endl;
    // std::cout << (5 > 6 ? 6 : 5) << std::endl;
}

