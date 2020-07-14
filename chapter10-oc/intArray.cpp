#include "intArray.h"
#include <iostream>

int main() {
    IntArray array{5, 4, 3, 2, 1};
    for (int count{0}; count < array.getLength(); ++count) {
        std::cout << array[ count ] << ' ';
    }
}
