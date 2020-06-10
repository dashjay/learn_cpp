#include <iostream>
#include <vector>

// if we call this with earlyExit
// it will cause memroy leak
void doSomething(bool earlyExit) {
    int *array{new int[ 5 ]{9, 7, 5, 3, 1}};

    if (earlyExit)
        return;
    // do stuff here
    delete[] array; // never called
}

void printLength(const std::vector<int> &array) {
    std::cout << "The length is: " << array.size() << '\n';
}

int main() {

    // vector is much more safer
    // if it gose out of scope
    // vector will clean it self
    std::vector<int> myVector{2, 3, 4, 5, 6, 7};
    printLength(myVector);

    // resize() can help resize your vector
    myVector.resize(5);
    printLength(myVector);

    // ok fine! the redundant elem will get lost;

    // resize is very computationally expensive.
    // try minimize the times you do it.
}
