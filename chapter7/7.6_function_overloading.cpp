#include <iostream>

// return type are not considered for uniqueness
// it will cause compiler error

// int getRandomVlaue() {
//    return 1;
//}
// double getRandomVlaue() {
//    return 1.1;
//}
// error: functions that differ only in their return type cannot be overloaded

// should use parameter

void print(char *value) {
    std::cout << value << std::endl;
}

void print(int value) {
    std::cout << value << std::endl;
}

struct E {
    int a;
};
void print1(float value) {
    std::cout << value << std::endl;
}
void print1(E e) {
    std::cout << e.a << std::endl;
}
int main() {
    //    (1) if cpp can't match the parameter, it tries to find through
    //    promotion Char, unsigned char, and short is promoted to an int. (char, uchar, short) -> int;
    //    Unsigned short can be promoted to int or unsigned int, depending on the size of an int; (ushort) -> (int,uint);
    //    Float is promoted to double (float) -> (double);
    //    Enum is promoted to int (Enum) -> (int);
    char d[] = "dsdaddasd";
    print('a');
    print(1);
    print(d);
    //    (2)  If no promotion is possible, C++ tries to find a match through
    //    standard conversion. Standard conversions include: 
    //    Any numeric type will match any other numeric type, including unsigned (e.g. int to float)
    //    Enum will match the formal type of a numeric type (e.g. enum to float) Enum -> float
    //    Zero will match a pointer type and numeric type (e.g. 0 to
    //    char*, or 0 to float)  0 -> (char*, float)
    //    A pointer will match a void pointer (xxxx *ptr)->(void *ptr)
    print1('a1');
}

