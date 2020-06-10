#include <array>
#include <iostream>
#include <iterator>
int main() {
    // we can use an ptr for iterator
    std::array data1{1, 2, 3, 4, 5, 6};

    auto begin{&data1[ 0 ]};
    auto end(begin + std::size(data1));

    for (auto ptr{begin}; ptr != end; ++ptr) {
        std::cout << *ptr << ' ';
    }
    std::cout << "\n";

    // stdlib's iterator

    auto begin1{data1.begin()};
    auto end1{data1.end()};

    for (auto ptr{begin1}; ptr != end1; ++ptr) {
        std::cout << *ptr << ' ';
    }
    std::cout << "\n";

    auto begin2{std::begin(data1)};
    auto end2{std::end(data1)};

    for (auto ptr{begin2}; ptr != end2; ++ptr) {
        std::cout << *ptr << ' ';
    }
    std::cout << "\n";
    
    // if the iterator point a deleted elem
    // it called dangling iteraotr
    // dereference will cause undefined behavior
}
