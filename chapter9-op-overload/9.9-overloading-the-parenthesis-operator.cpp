#include <cassert>
#include <iostream>
#include <string>

// std::string::substr
class MyString {
  private:
    std::string m_value;

  public:
    MyString(std::string _v)
        : m_value{_v} {
    }
    std::string operator()(int i, int j) {
        assert(i + j <= static_cast<int>(m_value.length()) &&
               "MyString::operator(int, int): SubString is out of range");
        std::string e{};
        for (int count{0}; count < j; ++count) {
            e += m_value[ static_cast<std::string::size_type>(i + count) ];
        }
        return e;
    }
};

int main() {
    MyString string{"Hello, world!"};
    std::cout << string(7, 5)
              << '\n'; // start at index 7 and return 5 characters

    return 0;
}
