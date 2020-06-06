#include <iostream>

void foo(int *p) {
    p = NULL;
}

int main(int args, char **argv) {
    std::cout << args << std::endl;
    std::cout << argv[ 1 ] << std::endl;
    int *p;
    foo(p);
    std::cout << *p << "\n";
    return 0;
}
