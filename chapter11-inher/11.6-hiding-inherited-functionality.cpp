#include <iostream>

class Base {
  public:
    int m_value;
    int getValue() {
        return m_value;
    }
    Base(int b)
        : m_value{b} {
    }
};

class Derive : public Base {
  private:
    using Base::m_value;

  public:
    int         getValue() = delete;
    std::string getName() {
        return "dj";
    }
    Derive(int v)
        : Base{v} {
    }
};

int main() {
    Base   b(5);
    Derive d(4);
    std::cout << d.getName() << "\n";
    auto newb = static_cast<Base>(d);
    std::cout << newb.getValue() << "\n";
}
