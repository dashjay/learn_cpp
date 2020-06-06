#include <cstdlib>
#include <iostream>

static constexpr double fraction{1.0 / (RAND_MAX + 1.0)};

int getRandomNumber(int min, int max) {
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int main() { std::cout << getRandomNumber(1, 100) << std::endl; }
