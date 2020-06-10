#include <iostream>

int main() {
    void *ptr;
    // void ptr can point to any type of value
    int    a{1};
    double b{2.0};
    ptr = &a;
    ptr = &b;

    // and when you want to cast dereferenced, you can use static_castt
    double *cast_b = static_cast<double *>(ptr);
    std::cout << *cast_b << std::endl;


    // but if you don't know what it is?
    // no way, you can just do by your self


    // never delete the void pointer
    // because compile don't know how much to delete
    
}
