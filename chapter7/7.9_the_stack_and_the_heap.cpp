#include <iostream>

// program typically divided into few different areas
// 1. code segment(text segment) [read-only]
// 2. bss segment(uninitialized data segment), where zero-initialized global and
// static variables are stored
// 3. data segment(initialized data segment), where initialized global and
// static variables are stored.
// 4. heap, where dynamically allocated varables are allocated from.
// 5. call stack ,where function parameters, local variables, and other
// function-related information are stored.

// heap also known as free store
// 1. slow
// 2. you should always deallocated them
// 3. dereference a pointer is slower than accessing a variable directly
// 4. large

// stack
// data structure is a programming mechanism for organizing data.
//
//
// stack overflow
//
// stack
// 1. fast
// 2. mem allocated on the stack stay just in scoop, destroyed when it is popped off the stack
// 3. mem allocated on the stack is known at compile time, it can be accessd directly through a variable
// 4. should not call funtion with large arrays and memory....
int main() {
    int stack[ 10000000 ];
    std::cout << "hi";
    return 0;
}
