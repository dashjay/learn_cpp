#include <cstdint>
#include <iostream>

#define CINT(x) static_cast<int>(x)

class Something {
    int    m_v1;
    double m_v2;
    char   m_v3;

  public:
    Something(int _v1 = 1, double _v2 = 2.2, char _v3 = '3')
        : m_v1{_v1}
        , m_v2{_v2}
        , m_v3{_v3} {
    }
    void print() {
        std::cout << "Something(" << m_v1 << ", " << m_v2 << ", " << m_v3
                  << ")\n";
    }
};

class RGBA {
    using uint8 = std::uint8_t;
    uint8 m_red;
    uint8 m_green;
    uint8 m_blue;
    uint8 m_alpha;

  public:
    RGBA(uint8 _red = 255, uint8 _green = 255, uint8 _blue = 255,
         uint8 _alpha = 255)
        : m_red(_red)
        , m_green(_green)
        , m_blue(_blue)
        , m_alpha(_alpha) {
    }
    void print() {
        std::cout << "r=" << CINT(m_red) << " g=" << CINT(m_green)
                  << " b=" << CINT(m_blue) << " a=" << CINT(m_alpha) << "\n";
    }
};

int main() {
    Something a{1, 2.1};
    a.print();

    RGBA teal{0, 127, 127};
    teal.print();
}

