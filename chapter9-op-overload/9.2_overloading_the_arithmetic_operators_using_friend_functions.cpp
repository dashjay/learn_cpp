#include <iostream>

class Cents {
  private:
    int m_cents;

  public:
    Cents(int cents) {
        m_cents = cents;
    }
    friend Cents operator+(const Cents &c1, const Cents &c2);
    int          getCents() const {
        return m_cents;
    }
};

Cents operator+(const Cents &c1, const Cents &c2) {
    return Cents(c1.m_cents + c2.m_cents);
}
int main() {
    Cents cents1{6};
    Cents cents2{8};
    Cents cent_sum{cents1 + cents2};
    std::cout << "I have " << cent_sum.getCents() << " cents.\n";
}
