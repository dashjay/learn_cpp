#include <iostream>

class MyInt {
  private:
    int m_value;

  public:
    MyInt(int _v)
        : m_value{_v} {
    }
    friend MyInt operator+(MyInt a, int b);
    int          getV() {
        return m_value;
    }
    void print() {
        std::cout << m_value << std::endl;
    }
};

MyInt operator+(MyInt a, int b) {
    return MyInt{a.getV() + b};
}

int main() {
    MyInt a{10};
    MyInt b{20};
    int   f = 1;
    MyInt d = a + f;
    d.print();
}
