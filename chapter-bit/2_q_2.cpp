#include <bitset>
#include <iostream>

std::bitset<4> rotl(std::bitset<4> bits) {
    bool leftbit = bits[ 3 ];
    bits <<= 1;
    std::bitset<4> setter = {0b0001};
    if (leftbit) {
        bits |= setter;
    }
    return bits;
}
int main() {
    std::bitset<4> bits1{0b0001};
    std::cout << rotl(bits1) << '\n';

    std::bitset<4> bits2{0b1001};
    std::cout << rotl(bits2) << '\n';

    return 0;
}
