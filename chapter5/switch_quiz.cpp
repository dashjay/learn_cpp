#include <iostream>

void operation(int a, int b, char op) {
    switch (op) {
    case '+':
        std::cout << a << " + " << b << " = " << a + b;
        break;
    case '-':
        std::cout << a << " - " << b << " = " << a - b;
        break;
    case '*':
        std::cout << a << " * " << b << " = " << a * b;
        break;
    case '/':
        std::cout << a << " / " << b << " = " << a / b;
        break;
    case '%':
        std::cout << a << "*" << b << " = " << a * b;
        break;
    default:
        std ::cout << "operator error" << std ::endl;
    }
}

int main() {
    int a, b;
    std::cout << "Enter a number:\n";
    std::cin >> a;
    std::cout << "Enter another number:\n";
    std::cin >> b;
    std::cout << "Enter an operator(+ - * / %):\n";
    char op;
    std::cin >> op;
    operation(a, b, op);
}
