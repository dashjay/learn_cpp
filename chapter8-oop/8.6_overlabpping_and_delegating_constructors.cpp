#include <iostream>

// deledate constructor

class Employee {
    int a;
    int b;

  public:
    Employee(int _a, int _b)
        : a{_a}
        , b{_b} {
        std::cout << "Employee Created.\n";
    }
    Employee(int _b)
        : Employee{0, _b} {
        std::cout << "Employee Fuck Created.\n";
    }
};

int main() {
    Employee d1{1, 2};
    Employee d2{3};
}
