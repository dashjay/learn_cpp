// 1. function args can be passed by value, reference or address.
//  - remember trying to pass const reference or address if possible
//
// 2. value can be return by value, reference or address.
//  - return by value are common
//  - return by reference or address can work with dynamically cllocated data
//
// 3. compiler will use inline function by it self
//
// 4. function overload allow us to create function with the same name, but work
// with distinct parameter nums.
//
// 5. default argument must be all at right
//
// 6. function pointers allow us to pass a function to another function.
// which can help customizing the behavior of a function
//
// 7. dynamic memory is allocated on the heap
//
// 8. recursive function is a function that calls itself.
// all of them need a termination condition.
//
// 9. errors
//  - syntax error
//  - semanic error
//      - logic errors
//      - violated assumptions
//
// 10. ellipsis allow you to pass avariable number of arguments to a function.
// ellipsis arguments suspend type checking,
//
// 10. lambda functions are functions that can be nested inside other functions.

#include <iostream>

double max(const double a, const double b) {
    return (a > b ? a : b);
}

void swap(int &a, int &b) {
    int temp = a;
    a        = b;
    b        = temp;
}
int &getLargestElement(int *arr, int size) {
    int *largest{arr};
    for (int *idx{arr + 1}; idx != (arr + size); ++idx) {
        if (*idx > *largest) {
            largest = idx;
        }
    }
    return *largest;
}
int main() {
    std::cout << max(5.5, 6.6) << std::endl;
    int a = 1;
    int b = 2;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    int *arr = new int[ 10 ]{1, 2, 3, 4, 5, 4, 3, 2, 1};
    for (int i{0}; i < 10; i++) {
        std::cout << arr[ i ] << " ";
    }
    std::cout << "\n";
    int &largest = getLargestElement(arr, 10);
    std::cout << "largest: " << largest << ", ptr: " << (void *) (&largest)
              << std::endl;
    largest = 100;
    for (int i{0}; i < 10; i++) {
        std::cout << arr[ i ] << " , ptr: " << (void *) (&arr[ i ])
                  << std::endl;
    }
    std::cout << "\n";
}
