#include <algorithm>
#include <array>
#include <iostream>

bool greater(int a, int b);
bool containsNut(std::string_view str);
void doubleNumber(int &i);
int  main() {
    // std::find
    std::array arr1{1, 23, 4, 67, 8, 9, 21, 123};
    std::cout << "Enter a value to search for and replace with: ";
    int search{};
    int replace{};
    std::cin >> search >> replace;

    auto found{std::find(arr1.begin(), arr1.end(), search)};
    if (found == arr1.end()) {
        std::cout << "Could not find " << search << "\n";
    } else {
        *found = replace;
    }

    for (int i : arr1) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::array<std::string_view, 5> arr2{"apple", "banana", "walnut", "lemon",
                                         "peanut"};

    auto found2{std::find_if(arr2.begin(), arr2.end(), containsNut)};

    if (found2 == arr2.end()) {
        std::cout << "No nuts\n";
    } else {
        std::cout << "Found: " << *found2 << "\n";
    }

    // useing count and count_if
    auto nuts{std::count_if(arr2.begin(), arr2.end(), containsNut)};
    std::cout << "Counted " << nuts << " nut(s)\n";

    std::sort(arr1.begin(), arr1.end(), std::greater<int>{});

    for (int i : arr1) {
        std::cout << i << ' ';
    }
    std::cout << "\n";

    std::for_each(arr1.begin(), arr1.end(), doubleNumber);

    for (int i : arr1) {
        std::cout << i << ' ';
    }
    std::cout << "\n";
    
    // how to skip a iterator
    std::cout << *arr1.begin() <<"'s next is " << *std::next(arr1.begin())<<"\n"; 

}

bool greater(int a, int b) {
    return (a > b);
}
bool containsNut(std::string_view str) {
    return (str.find("nut") != std::string_view::npos);
}
void doubleNumber(int &i) {
    i *= 2;
}
