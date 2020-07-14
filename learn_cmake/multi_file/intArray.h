#include <cassert>
#include <iostream>

class IntArray {
  private:
    int  m_length{};
    int *m_data{};

  public:
    IntArray() = default;
    IntArray(int length)
        : m_length{length}
        , m_data{new int[ length ]{}} {
    }
    IntArray(std::initializer_list<int> list)
        : IntArray(static_cast<int>(list.size())) {

        int idx{0};
        for (auto elem : list) {
            m_data[ idx ] = elem;
            ++idx;
        }
    }
    ~IntArray() {
        delete[] m_data;
    }
    IntArray(const IntArray &) = delete;
    IntArray &operator=(const IntArray &list) = delete;
    IntArray &operator=(std::initializer_list<int> list) {
        int length{static_cast<int>(list.size())};
        if (length != m_length) {
            delete[] m_data;
            m_length = length;
            m_data   = new int[ length ]{};
        }
        int idx{0};
        for (auto elem : list) {
            m_data[ idx ] = elem;
            ++idx;
        }
        return (*this);
    }
    int &operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[ index ];
    }
    int getLength() const {
        return m_length;
    }
};

