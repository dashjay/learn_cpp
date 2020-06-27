#include <cstddef>
#include <iostream>

class FixedPoint2 {
  private:
    int_least16_t m_nonf;
    int_least8_t  m_f;

  public:
    FixedPoint2(int_fast16_t _nonf, int_fast8_t _f)
        : m_nonf{_nonf}
        , m_f{_f} {
    }
    operator double() const {
        return m_nonf + static_cast<double>(m_f) / 100.0;
    }
    friend std::ostream &operator<<(std::ostream &out, FixedPoint2 &p);
};

std::ostream &operator<<(std::ostream &out, FixedPoint2 &p) {
    out << static_cast<double>(p.m_nonf) + static_cast<double>(p.m_f) / 100;
    return out;
}
int main() {
    FixedPoint2 a{34, 56};
    std::cout << a << '\n';

    auto d = static_cast<double>(a);
    std::cout << d << "\n";
}
