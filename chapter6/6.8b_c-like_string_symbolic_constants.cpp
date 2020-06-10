#include <iostream>

const char *getName();
int         main() {
    char *myName{"Dashjay"};
    // above will cause warning
    // ISO C++11 does not allow conversion from string literal to 'char *'
    std::cout << myName << std::endl;
    const char *myName1{"Dashjay"};
    // above will not
    std::cout << myName1 << std::endl;

    // when use const symbolic
    // the compiler will put the string lit to
    // some where readonly and return a ptr to it.
    const char *name1{"Alex"};
    const char *name2{"Alex"};

    std::cout << "address of name1 is " << (void *) name1 << "\n";
    std::cout << "address of name2 is " << (void *) name2 << "\n";
    // address of name1 is 0x104dd7f2c
    // address of name2 is 0x104dd7f2c
    // because of the compiler optimizaion ……

    // with knowledge above
    // we can know the const string lit
    // will be store at somewhere
    // they will not destroy at the end
    // of block, eg: getName()

    std::cout << getName() << "\n";
    // above op show you that the
    // Alex will not be destoy after function returnd

    // cout << for char
    int         nArray[ 5 ]{9, 7, 5, 3, 1};
    char        cArray[]{"Hello!"};
    const char *name{"Alex"};

    std::cout << nArray << '\n'; // nArray will decay to type int*
    std::cout << cArray << '\n'; // cArray will decay to type char*
    std::cout << name << '\n';   // name is already type char*
    // 0x7ffee23526e0
    // Hello!
    // Alex
    char c{ 'Q' };
    std::cout << &c;
}

const char *getName() {
    return "Alex";
}
