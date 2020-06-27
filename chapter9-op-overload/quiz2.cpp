#include <cassert>
#include <iostream>
class IntArray {
  private:
    int *m_value{nullptr};
    int  m_length;

  public:
    IntArray(int length) {
        assert(length > 0 && "IntArray length should be a positive integer");
        m_length = length;
        m_value  = new int[ length ];
    }
    IntArray(const IntArray &arr) {
        std::cout << "Call Copy Custruct" << std::endl;
        m_length = arr.m_length;
        m_value  = new int[ m_length ];
        for (int count{0}; count < m_length; ++count) {
            m_value[ count ] = arr.m_value[ count ];
        }
    }
    ~IntArray() {
        delete[] m_value;
    }
    IntArray &operator=(IntArray &assign) {
        std::cout << "Call Assign" << std::endl;
        if (this == &assign) {
            return (*this);
        }
        delete[] this->m_value;
        this->m_length = assign.m_length;
        this->m_value  = new int[ this->m_length ];
        for (int i{0}; i < m_length; ++i) {
            m_value[ i ] = assign.m_value[ i ];
        }
        return (*this);
    }
    int &operator[](int x) {
        return m_value[ x ];
    }
    friend std::ostream &operator<<(std::ostream &out, IntArray &p);
};
std::ostream &operator<<(std::ostream &out, IntArray &p) {
    for (int i{0}; i < p.m_length; ++i) {
        out << p.m_value[ i ] << " ";
    }
    return out;
}
IntArray fillArray() {
    IntArray a(5);

    a[ 0 ] = 5;
    a[ 1 ] = 8;
    a[ 2 ] = 2;
    a[ 3 ] = 3;
    a[ 4 ] = 6;

    return a;
}

int main() {
    IntArray a{fillArray()};
    std::cout << a << "\n";
    auto &ref{a};
    a = ref;
        IntArray b(1);
        b = a;
    std::cout << b << "\n";
    return 0;
}
