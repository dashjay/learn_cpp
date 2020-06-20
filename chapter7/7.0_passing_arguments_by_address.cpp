#include <iostream>
#define PRINT std::cout << i << std::endl;
// passing by value
void foo_val(int i) {
    i += 1;
    // will not change the origin value;
}

// passing by reference;
void foo_ref(int &i) {
    i += 1;
}

// passing by ptr
void foo_ptr(int *i) {
    *i += 1;
    // will change the
}

void foo_ptr_ref(int *&i) {
    i = nullptr;
}

int main() {
    // use passing value

    int i{6};
    PRINT
    foo_val(i);
    PRINT
    foo_ref(i);
    PRINT
    foo_ptr(&i);
    PRINT
    int *ptr{&i};
    foo_ptr_ref(ptr);
    PRINT
    std::cout << *ptr << std::endl;
}
