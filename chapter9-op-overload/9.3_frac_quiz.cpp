#include <iostream>

class Frac {
    int m_numerator;
    int m_denominator;

  public:
    Frac(int _n = 0, int _d = 1)
        : m_numerator{_n}
        , m_denominator{_d} {
        reduce();
    }
    void print() const {
        std::cout << m_numerator << "/" << m_denominator << "\n";
    }
    void reduce() {
        int m_gcd = gcd(m_numerator, m_denominator);
        m_numerator /= m_gcd;
        m_denominator /= m_gcd;
    }
    static int gcd(int a, int b) {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }
    friend Frac operator*(int a, Frac &b);
    friend Frac operator*(Frac &a, int b);
    friend Frac operator*(const Frac &a, const Frac &b);
};

Frac operator*(int a, Frac &b) {
    return Frac{a * b.m_numerator, b.m_denominator};
}
Frac operator*(Frac &a, int b) {
    return Frac{b * a.m_numerator, a.m_denominator};
}
Frac operator*(const Frac &a, const Frac &b) {
    return Frac{a.m_numerator * b.m_numerator,
                a.m_denominator * b.m_denominator};
}

int main() {
    Frac f1{1, 4};
    f1.print();
    Frac f2{2, 8};
    f2.print();
    Frac f3{f1 * f2};
    f3.print();
}
