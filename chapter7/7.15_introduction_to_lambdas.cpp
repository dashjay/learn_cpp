#include <algorithm>
#include <array>
#include <iostream>

bool containsNut(std::string_view str);
int  main() {

    std::array<std::string_view, 5> arr2{"apple", "banana", "walnut", "lemon",
                                         "peanut"};

    auto found2{std::find_if(
        arr2.begin(), arr2.end(), [](std::string_view str) -> bool {
            return (str.find("nut") != std::string_view::npos);
        })};

    if (found2 == arr2.end()) {
        std::cout << "No nuts\n";
    } else {
        std::cout << "Found: " << *found2 << "\n";
    }

    // it looks like a very complex long function
    // make my confused
    auto ContainNut{[](std::string_view str) -> bool {
        return (str.find("nut") != std::string_view::npos);
    }};
    auto found3{std::find_if(arr2.begin(), arr2.end(), ContainNut)};
    if (found3 == arr2.end()) {
        std::cout << "No nuts\n";
    } else {
        std::cout << "Found: " << *found3 << "\n";
    }

    // we can use function
    std::function<bool(std::string_view str)> ContainNutFunc{ContainNut};

    // or we can use function ptr
    bool (*CountainNutPtr)(std::string_view){ContainNut};

    // afterDoing that we can call them use a
    std::cout << "is welnut has nut? -> " << ContainNutFunc("welnut") << "\n";
    std::cout << "is welnut has nut? -> " << CountainNutPtr("welnut") << "\n";

    // can we call lambda directly
    std::cout << "is welnut has nut? -> " << ContainNut("welnut") << "\n";

    /*
     * In actuality, lambdas aren’t functions (which is part of how they avoid
     * the limitation of C++ not supporting nested functions). They’re a special
     * kind of object called a functor. Functors are objects that contain an
     * overloaded operator() that make them callable like a function.
     * */
    auto print{[](auto valueToPrint) {
        static int callCount{0};
        std::cout << callCount++ << ": " << valueToPrint << "\n";
    }};

    print("1");
    print("2");
    print(3);
    print(4);
    print(5.0);

    // in lambdas
    // we could not use a specified return type
    // compiler could determin itself
    auto divide{[](int x, int y) { return x / y; }};

}

bool containsNut(std::string_view str) {
    return (str.find("nut") != std::string_view::npos);
}
