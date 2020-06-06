#include <iostream>
#include <typeinfo>
// when declare the function
// I prefer put *(asterisk) besides the int.
// but the clang-format not do this.
int *giveMeFive() {
    int d = 5;
    return &d;
}
int main() {
    // A pointer is a variable that holds a memory address as its value.
    int a = 5;
    std::cout << "value of a is " << a << ", address of a is " << &a
              << std::endl;
    // the explain above are surprisingly simple when explained properly.
    // but sometimes we will hear about other that ptr is devil complex....
    // ...... I was one of them.

    // ptr is just a variable which store other's address
    // but int ptr can just store addrees of int variable...

    int *iPtr{};
    std::cout << "the value of iPtr is " << iPtr << ", address of iPtr is "
              << &iPtr << std::endl;
    // the value of iPtr is 0x0, address of iPtr is 0x7ffee2eb6720
    // the iPtr is a NULL ptr which has never been assign
    // it's value is 0 but itself was store at an address

    // I like put the *(asterisk) besides the variable name.
    // because int* ptr1, ptr2; when declare as this.
    // ptr1 is a pointer of int, while ptr2 just a int value.

    int x{5};
    std::cout << typeid(&x).name() << "\n";
    std::cout << typeid(x).name() << "\n";
    // in g++ or clang++ out Pi and i. it is said that Pointer to int and int.
    

}
