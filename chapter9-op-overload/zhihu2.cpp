#include <iostream>

class MyInt {
  private:
    int m_int;

  public:
    MyInt(int i)
        : m_int{i} {
    }
    MyInt &operator++();
    MyInt &operator--();

    MyInt operator++(int); 
    MyInt operator--(int); 

    friend std::ostream &operator<<(std::ostream &out, const MyInt &d);
};

MyInt &MyInt::operator++() {
    ++m_int;
    return *this;
}

MyInt &MyInt::operator--() {
    --m_int;
    return *this;
}

MyInt MyInt::operator++(int) {
    MyInt temp(m_int);
    ++(*this);
    return temp;
}

MyInt MyInt::operator--(int) {
    MyInt temp(m_int);
    --(*this);
    return temp;
}

std::ostream &operator<<(std::ostream &out, const MyInt &d) {
    out << d.m_int << "\n";
    return out;
}

int main() {
    // MyInt i(10);
    // std::cout << i;
    // std::cout << ++i;
    // std::cout << ++i;
    // std::cout << --i;
    // std::cout << --i;

    
    MyInt j(10);
    std::cout << j;
    std::cout << j++;
    std::cout << j++;
    std::cout << j--;
    std::cout << j--;
}

