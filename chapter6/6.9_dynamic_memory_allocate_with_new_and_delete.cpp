#include <iostream>

void doSomething();
// why we need dynamic alllocation
// first, when was a program allocate memory.
//
// 1. Static Memory Allocate: when program run, global and static variable will
// allocate and persists throughout the program's life.
//
// 2. Automatic Memory Allocate: when calling function, the parameters, local
// variables and function itself will allocate when block is entered and freed
// when the block is exited;
//
// > above 2 way have something in common:
//
// 1. sizeof variable/array will be known at compile theme.
// 2. All are automaticlly.
//
// when you get external input from file or user
// something get wrong.
//
// when we do not know what's the best size of our parmeters
// it always make a guess the maximum size
// `char name[25];` and we can just hope that enough.
//
// knowing above we ofen dynamically allocate memroy
// the store on heap(not stack). we can allocate a
// very big memory.

int main() {
    int *ptr{new int};
    *ptr = 7;

    // in cpp11we can use uniform init
    int *ptr1{new int{6}};

    int *ptr2{new int(7)};
    // above 2 way can also work.

    // delete single one;
    delete ptr;
    ptr = nullptr;

    // Note that deleting a pointer that is not pointing to dynamically
    // allocated memory may cause bad things to happen.

    // Ddandling Pointers
    // A pointer that is pointing to deallocated memory is called a dangling
    // pointer.

    // dptr and otherPtr are allocate
    int *dptr{new int{}};
    int *otherPtr{dptr};
    // delete ptr and set it to 0;
    delete ptr;
    ptr = nullptr;

    // otherPtrr is now still a dangling pointer !
    //
    // How to do !
    // First, try to aboid having multiple pointers point at the save piece of
    // dynamic memory. If you think that's not ppossible, be clearr about ptr
    // which pointer to "true" memory, and which just access other pointer.
    //
    // Second, when ptr deleted and is going out of scope immediately, set it to
    // nullptr.

    // some times system have no noused memory to give you
    // will throw bad_alloc exception
    // if you write like this
    int *value = new (std::nothrow) int;
    // it will return a nullptr if fail to allocate

    // this can cause memory leak
    doSomething();

    // when assign to another value
    // memory leak
    int  v = 5;
    int *ptr4{new int{}}; // allocate memory
    ptr = &v;             // old address lost, memory leak results

    int *ptr5{new int{}};
    ptr5 = new int{}; // old address lost, memory leak results
}

// this function allocate int, but never frees it using delete.
void doSomething() {
    int *ptr{new int{}};
}
