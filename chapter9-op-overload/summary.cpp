
// 1. overloading assignment(=), subscript([]), function call (()), or member
// selection (->), do so as a member function.
//
// 2. unary opeator, do so as a member function.
//
// 3. binary operator and modifies it's left operand(eg operator+=), do so as a
// member function if you can
//
// 4. binary operator does not modify it's left operand(operator+), do so as a
// normal function or firend function.
//
#include <cstdint>
#include <iostream>
#include <vector>

class Average {
  private:
    std::vector<int>   chain;
    std::int_least32_t sum;
    std::int_least8_t  count;

  public:
    Average &            operator+=(int n);
    friend std::ostream &operator<<(std::ostream &out, Average &avg);
};

std::ostream &operator<<(std::ostream &out, Average &avg) {
    if (avg.count == 1) {
        out << avg.chain[ 0 ] << " / 1 = " << avg.chain[ 0 ];
        return out;
    }
    out << "(";
    out << avg.chain[ 0 ];
    for (size_t i{1}; i < avg.chain.size(); ++i) {
        auto d = avg.chain[ i ];
        out << (d > 0 ? " + " : " - ");
        out << std::abs(d);
    }
    std::cout << ") / " << static_cast<int>(avg.count) << " = "
              << (static_cast<double>(avg.sum) / avg.count);
    return out;
}
Average &Average::operator+=(int n) {
    chain.push_back(n);
    sum += n;
    count += 1;
    return (*this);
}

int main() {
    Average avg{};
    avg += 4;
    std::cout << avg << '\n';

    avg += 8;
    std::cout << avg << '\n';

    avg += 24;
    std::cout << avg << '\n';

    avg += -10;
    std::cout << avg << '\n';

    (avg += 6) += 10;
    std::cout << avg << '\n';

    Average copy{avg};

    std::cout << copy << '\n';
}
