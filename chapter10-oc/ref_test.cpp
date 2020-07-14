#include <iostream>

int main() {
    int  i{1};
    int &d{i};
    std::cout << typeid(d).name() << "\n";
}
