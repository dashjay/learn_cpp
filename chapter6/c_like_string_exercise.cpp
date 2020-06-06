#include <cstring>
#include <iostream>
#include <iterator>

int main() {
    // we know the string's length
    // in golang it called len and cap
    char Hello[ 64 ]{"Hello World"};
    // cap
    std::cout << "cap: " << std ::size(Hello) << std::endl;

    // len
    std::cout << "len: " << std::strlen(Hello) << std::endl;

    // not in cpp17
    std::cout << "len: " << sizeof(Hello) / sizeof(Hello[ 0 ]) << std::endl;

    // there is a '\0' at the last of c-like-string's end;
    for (size_t i = 0; i < std::strlen(Hello); i++) {
        std::cout << int(Hello[ i ]) << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < std::size(Hello); i++) {
        std::cout << int(Hello[ i ]) << " ";
    }
    std::cout << "\n";
    // after the 'd' of 'Hello World' there are many 0 at the end;

    // in go we have copy to copy from src slice to dst slice
    // in cpp we often use strcpy to copy from on to aother

    char dst[ 32 ];
    std::strcpy(dst, Hello);
    std::cout << dst << std::endl;

    // we sometime get overflow results.
    char dst2[ 2 ];
    std::strcpy(dst2, Hello);
    std::cout << dst2 << std::endl;

    // we use concat to connect 2 string.
    char temp[]{"Alex"};
    std::strcat(Hello, temp);
    std::cout << Hello << std::endl;

    // but it is dangrous
    std::cout << "before strcat, len of temp: " << strlen(temp)
              << " cap of temp " << std::size(temp) << std::endl;
    std::strcat(temp, Hello);
    std::cout << "after strcat, len of temp: " << strlen(temp)
              << " cap of temp: " << std::size(temp) << std::endl;
    std::cout << temp << std::endl;
    std::cout << temp[ 5 ] << std::endl;

}
