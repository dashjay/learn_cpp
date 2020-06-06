#include <iostream>
#include <string>

int main() {
    std::cout << "Enter a line";
    std::string line{};
    std::getline(std::cin, line);
    std::cout << line <<std::endl;
}
