#include <iostream>
#include <iterator>
int main() {
    char myString[]{"string"};
    int  stringLength{std::size(myString)};
    std::cout << "str: " << myString << std::endl;
    std::cout << "length: " << std::size(myString) << std::endl;
    for (int i = 0; i < stringLength; i++) {
        std::cout << int(myString[i])<<" ";
    }

}
