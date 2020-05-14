#include <iostream>

int main(){
    int a = 5, b= 6; //copy initialization
    int c( 7 ), d( 8 ); // derect initialization
    int e{ 9 }, f{ 10 }; //brace initialization -> preferred

    std::cout << c << d << std::endl;
}
