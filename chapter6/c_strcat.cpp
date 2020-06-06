#include <cstring>
#include <iostream>

int main() {
    char temp[]{"Alex"};
    char Hello[ 64 ]{"Hello World"};
    std::cout << "ptr is " << (void *) &temp[ 0 ] << std::endl;
    std::strcat(temp, Hello);
    std::cout << "std::strlen():" << std::strlen(temp)
              << " std::size():" << std::size(temp) << std::endl;
    std::cout << "after cat:" << temp << std::endl;
    for (size_t i = 0; i < std::strlen(temp); i++) {
        std::cout << "ptr of temp[" << i << "] is" << (void *) &temp[ i ]
                  << " char -> " << temp[ i ] << std::endl;
    }

    for (size_t i = 0; i < std::strlen(Hello);  i++) {
        std::cout << "ptr of Hello[" << i << "] is" << (void *) &Hello[ i ]
                  << " char -> " << Hello[ i ] << std::endl;
    }
}
