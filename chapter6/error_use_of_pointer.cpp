#include <cstddef>
#include <iostream>

void foo(int *p) {
    p = NULL;
    // avoid use the NULL
    // it's a preprocessor macro with an implementation defined valud.
}

int main(int args, char **argv) {
    std::cout << args << std::endl;
    std::cout << argv[ 1 ] << std::endl;
    int *p;
    foo(p);
    std::cout << *p << "\n";

    int *ptr{nullptr};
    return 0;
}
