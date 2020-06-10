#include <algorithm> // for std::sort
#include <iostream>
#include <iterator> // for std::begin and std::end
std::string InputName(int sign) {
    std::string name;
    std::cout << "Enter name #" << sign << ": ";
    std::getline(std::cin, name);
    return name;
}
int main() {
    std::cout << "How many names would you like to enter? ";
    int numName{};
    std::cin >> numName;
    std::cin.ignore(1024, '\n');
    std::string *nameList = new std::string[ numName ]{};
    for (int i = 0; i < numName; i++) {
        nameList[ i ] = InputName(i + 1);
    }
    std::sort(nameList, nameList + numName);
    std::cout << "Here is your sorted list:\n";

    for (int i = 0; i < numName; i++) {
        std::printf("Name #%d: %s\n", i + 1, nameList[ i ].c_str());
        // std::cout << "Name #" << i + 1 << ": " << nameList[ i ] << "\n";
    }

    // I do every ok
    // but forget about delete

    delete []nameList;
}
