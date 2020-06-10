#include <iostream>

void printSizePtr(int *array);
void printSizeFix(int array[]);
void changeArray(int *array);

int main() {
    int array[ 5 ]{9, 8, 7, 6, 7};

    std::cout << "Address of array[0] is " << &array[ 0 ] << std::endl;

    std::cout << "Address of the array is " << array << std::endl;

    // we can not beleive an array and a pointer to the array are identical
    // you can't get the length of the array from just a ptr

    // we can use a word 'degradation(decays)' to say that
    // an array degradate to a int ptr

    int *myArray{array};

    std::cout << *myArray << std::endl;

    // they are diffrent
    // 1. can't use sizeof to get the sizeof whole array from a ptr;

    std::cout << "sizeof(array): " << sizeof(array) << std::endl;    // 20
    std::cout << "sizeof(myArray):" << sizeof(myArray) << std::endl; // 8

    // 2. when use the address-of operator(&).
    // they are not quite the same

    std::cout << typeid(array).name() << "\n";   // A5_i
    std::cout << typeid(&array).name() << "\n";  // PA5_i
    std::cout << typeid(myArray).name() << "\n"; // Pi

    std::cout << sizeof(array) << "\n";
    printSizePtr(array);
    printSizeFix(array);

    // pass array to function
    // when do this we should know which is copied and which is not;
    // the array will decays into a pointer (copy)
    // but the pointer is pointing to origin value (not copy);
    std::cout << "the first elem of array is " << array[ 0 ] << std::endl;
    changeArray(array);
    std::cout << "the first elem of array is " << array[ 0 ] << std::endl;


    return 0;
}

void printSizePtr(int *array) {
    std::cout << "parameter array* :" << sizeof(array) << "\n";
}
void printSizeFix(int array[]) {
    // warning: sizeof on array function parameter will return size of 'int *'
    // instead of 'int []' [-Wsizeof-array-argument] That means the printSizePtr
    // and printSizeFix function declarations are identical;
    std::cout << "parameter array[] :" << sizeof(array) << "\n";
}

// because weather array[] nor *array can get the length of array
// so we ofen declare the func like this
// void funcname(int *array, int size);

void changeArray(int *array) {
    *array = 5;
}
