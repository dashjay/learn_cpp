#include <iostream>
#include <vector>
int factorial(int t) {
    if (t == 0) {
        return 1;
    } else {
        return factorial(t - 1) * t;
    }
}

int recursive_cut(int num) {
    if (num == 0) {
        return 0;
    } else {
        return recursive_cut(num / 10) + num % 10;
    }
}

void print_bin(int num) {
    if (num == 0) {
        std::cout << "0";
        return;
    } else if (num == 1) {
        std::cout << "1";
        return;
    } else {

        int temp = num / 2;
        print_bin(temp);
        if (temp * 2 < num) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }
}

void printBinary(int x) {
    if (x == 0) {
        return;
    }

    printBinary(x / 2);

    std::cout << x % 2;
}

int main() {
    std::cout << "factorial(3) = " << factorial(3) << "\n";
    std::cout << "recurse_cut(93427) = " << recursive_cut(93427) << std::endl;
    std::cout << "print_bin(10) = ";
    printBinary(10);
    std::cout << "\n";
}

