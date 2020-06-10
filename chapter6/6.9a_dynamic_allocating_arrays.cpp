#include <cstddef> // std::size_t
#include <iostream>
// dynamic allocate array allow us to
// choose an array length at runtime.

int main() {
    std::cout << "Enter a positive integer: ";
    std::size_t length{};
    std::cin >> length;

    int *array{new int[ length ]{}};

    array[ 0 ] = 5;
    delete[] array;
    // when you call new int[length], then length was keep
    // when you call delete[], it knows to delete proper amount.
    // user can not access the size/length.

    auto *arrayInit{new int[ 5 ]{1, 2, 3, 4, 5}};

    char *arrayHello = new char[ 14 ]{"Hello, world!"};
    std::cout << arrayHello << std::endl;


    // how to resize
    // copy and delete the old one?
    // this is error prone
    //
    return 0;
}

