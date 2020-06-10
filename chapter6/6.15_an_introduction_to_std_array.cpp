#include <algorithm>
#include <array>
#include <iostream>
// use array by ptr can be very complicated
// we use array to get it easier
int main() {
    std::array<int, 3> myArray;

    std::array<int, 5> myArray2 = {9, 4, 2, 4, 5};
    std::array<int, 5> myArray3{34, 34, 34, 34, 34};

    // you can't omit the length
    // std::array<int,>a{} <- invalid

    // in cpp 17 we can omit length
    // but we should always

    // you can use a list assign
    myArray = {1, 2, 3};
    myArray = {2, 3};
    for (int m : myArray) {
        std::cout << m << " ";
    }
    std::cout << "\n";
    // besides use the subscript s[x]
    // you can use another way to access it
    myArray.at(0) = 5;
    for (int m : myArray) {
        std::cout << m << " ";
    }
    std::cout << "\n";

    // array will cleanup itself
    // this is what I like most
    std::sort(myArray.begin(), myArray.end());
    for (int m : myArray) {
        std::cout << m << " ";
    }
    std::cout << "\n";
    
    std::sort(myArray.rbegin(), myArray.rend());
    for (int m : myArray) {
        std::cout << m << " ";
    }
    std::cout << "\n";
    //
}
