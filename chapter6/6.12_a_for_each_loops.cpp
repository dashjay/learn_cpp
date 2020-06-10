#include <iostream>

// for each loop

int main() {
    constexpr int fibonacci[]{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    for (int fab : fibonacci) {
        std::cout << fab << ' ';
    }
    std::cout << "\n";

    // remember that the for-each-loop will copy the value
    // so we ofen use reference;
    for (auto &fab : fibonacci) {
        std::cout << fab << ' ';
    }
    std::cout << "\n";
    return 0;
}
