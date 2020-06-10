#include <iostream>

// lift time of reference

int main() {

    // express 2+3 is destroyed at the end of this statement;
    std::cout << 2 + 3 << "\n";

    // this way 2+3 is destroyed at the end of the statement, but ref has a
    // reference to 2+3;
    const int &ref{2 + 3};

    std::cout << ref;
}
