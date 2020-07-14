#include <iostream>

template <typename T> class Pair1 {
  private:
    T m_value[ 2 ];

  public:
    Pair1(T v1, T v2) {
        m_value[ 0 ] = v1;
        m_value[ 1 ] = v2;
    }
    T first() const {
        return this->m_value[ 0 ];
    }
    T second() const {
        return this->m_value[ 1 ];
    }
};

int main() {
    Pair1<int> p1(5, 8);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(2.3, 4.5);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}
