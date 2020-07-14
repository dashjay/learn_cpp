#include <iostream>

template <typename T1, typename T2> class Pair {
  private:
    T1 m_x;
    T2 m_y;

  public:
    Pair(T1 v1, T2 v2)
        : m_x{v1}
        , m_y{v2} {
    }
    T1 first() const {
        return this->m_x;
    }
    T2 second() const {
        return this->m_y;
    }
};

template <typename T> class StringValuePair : public Pair<std::string, T> {
  public:
    StringValuePair(const std::string &key, const T &value)
        : Pair<std::string, T>(key, value) {
    }
};

int main() {
    Pair<int, double> p1(5, 6.7);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(2.3, 4);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    StringValuePair<int> svp("Hello", 5);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}
