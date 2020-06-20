#include <functional>
#include <iostream>
int getInteger() {
    std::cout << "Enter an integer: ";
    int x;
    std::cin >> x;
    return x;
}

char getOp() {
    char op;
    do {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    } while (op != '+' && op != '-' && op != '*' && op != '/');
    return op;
}

int add(int x, int y) {
    return x + y;
}

int substract(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    return x / y;
}
using artihmeticFcn = std::function<int(int, int)>;

artihmeticFcn getArithmeticFunction(char op) {
    switch (op) {
    default:
    case '+':
        return add;
    case '-':
        return substract;
    case '*':
        return multiply;
    case '/':
        return divide;
    }
}

int main() {
    int  x{getInteger()};
    char op{getOp()};
    int  y{getInteger()};
    std::printf("%d %c %d = %d", x, op, y, getArithmeticFunction(op)(x, y));
    return 0;
}
