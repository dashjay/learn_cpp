#include <bitset>
#include <iostream>

int main() {
    std::bitset<8> bits{0b0000'0001};
    bits.set(4);
    bits.flip(3);
    bits.reset(3);
    std::cout << "All the bits: " << bits << std::endl;
    return 0;
}
