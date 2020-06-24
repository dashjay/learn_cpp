// think every thin in the world have 2 point.
// 1. properties
// 2. methods

#include <string>

class Person {};

void DriveTo(Person &p, std::string something) {
}
int main() {
    Person you;
    DriveTo(you, "work");
    // but in oop you can just do this
    you.DriveTo("work");
}

