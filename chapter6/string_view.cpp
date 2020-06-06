#include <iostream>
#include <string_view>

int main() {
    std::string_view text{"hello"};
    std::string_view str{text};
    std::string_view more{str};
    std::cout << text << ' ' << str << ' ' << more << '\n';

    // like golang when we use []byte(string)
    // the runtime will malloc new memory to
    // store the string.
    // if we want just to cast the type from
    // string to byte.
    // you can use runtime.StringHeader to do
    // some thing like Cpp string_view
    // but never to modify with this index
    // b[1] = byte('1') will panic
    char             text1[]{"Glod"};
    std::string_view str1{text1};
    std::cout << text1 << std::endl;
    text1[ 1 ] = 'F';
    std::cout << text1 << std::endl;
}
