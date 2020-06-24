#include <cassert>
#include <cstddef>
#include <iostream>

class IntArray {
  private:
    int *m_array{};
    int  m_length{};

  public:
    IntArray(int _length) {
        assert(_length > 0);
        m_array  = new int[ static_cast<std::size_t>(_length) ]{};
        m_length = _length;
    }
    ~IntArray() {
        delete[] m_array;
    }

    void setValue(int index, int value);
    int  getValue(int index);
    int  getLength();
};

int main() {
    IntArray ar{10};
    for (int count{0}; count < ar.getLength(); ++count) {
        ar.setValue(count, count + 1);
    }

    std::cout << "The value of element 5 is: " << ar.getValue(5) << "\n";
}

void IntArray::setValue(int index, int value) {
    this->m_array[ index ] = value;
}

int IntArray::getValue(int index) {
    return this->m_array[ index ];
}

int IntArray::getLength() {
    return this->m_length;
}

