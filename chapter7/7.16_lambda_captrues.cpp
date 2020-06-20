#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <string_view>

int main() {
    std::array<std::string_view, 4> arr{"apple", "banana", "walnut", "lemon"};

    std::cout << "search for: ";

    std::string search{};
    std::cin >> search;

    auto found{
        std::find_if(arr.begin(), arr.end(), [ search ](std::string_view str) {
            return (str.find(search) != std::string_view::npos);
        })};

    if (found == arr.end()) {
        std::cout << "Not found\n";
    } else {
        std::cout << "Found " << *found << '\n';
    }

    std::array areas{100, 25, 121, 40, 56};

    int width{};
    int height{};

    std::cout << "Enter width and height: ";
    std::cin >> width >> height;
    auto found1{std::find_if(areas.begin(), areas.end(),
                             // we can use {} to create a value in capture list
                             [ userArea{width * height} ](int knownArea) {
                                 return (userArea == knownArea);
                             })};

    if (found1 == areas.end()) {
        std::cout << "I don't know this area :( \n";
    } else {
        std::cout << "Area found :)\n";
    }

    return 0;
}
