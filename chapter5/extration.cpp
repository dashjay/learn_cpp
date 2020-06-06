#include <iostream>

double getDouble() {
    while (true) {
        std::cout << "Enter a double value: ";
        double x{};
        std::cin >> x;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        } else {
            std::cin.ignore(32767, '\n');
            return x;
        }
    }
}

char getOperator() {
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op{};
    std::cin >> op;
    return op;
}

void printResult(double x, char operation, double y) {
    switch (operation) {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    }
}

int main() {
    double x{getDouble()};
    char   operation{getOperator()};
    double y{getDouble()};

    printResult(x, operation, y);

    return 0;
}