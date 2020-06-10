#include <iostream>

int main() {
    // a pointer to a const value:
    // is a (non-const) pointer to a const value;
    const int  value = 5;
    const int *ptr   = &value;
    // if int *ptr = &value will compile error;

    int        value2 = 5;
    const int *ptr2   = &value2;
    // this is also okay;
    // you can assign to value2
    // but you can't assgin to ptr2
    value2 = 7;
    // *ptr2 = 8 // this compiler error

    const int *ptr3 = &value2;
    int        value3{3};
    ptr3 = &value3;
    // this is okay
    // const int represent that value is const
    // can't be assign
    // but itself(ptr) not only readable;
    // it can be assgin to another value;
    int *const ptr4 = &value2;
    // we must init with value
    // and can not assign to other
    // ptr4 = &value3; this will compiler error;

    *ptr4 = 2; // because value is still non-const

    // finally we can declare a const point to const balue
    const int *const ptr5 = &value;
}
