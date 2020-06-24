#include <iostream>

class Stack {
    int m_stack[ 10 ];
    int m_size;

  public:
    void reset() {
        m_size = -1;
    }
    void push(int a) {
        if (m_size >= 10) {
            return;
        }
        ++m_size;
        m_stack[ m_size ] = a;
    }
    void pop() {
        if (m_size >= 0) {
            --m_size;
        }
    }
    void print() {
        std::cout << "( ";
        for (int i{0}; i <= m_size; i++) {
            std::cout << m_stack[ i ] << " ";
        }
        std::cout << " )";
        std::cout << "\n";
    }
};
int main() {
    Stack stack;
    stack.reset();

    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}
