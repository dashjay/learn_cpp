#include <iostream>

struct Person {
    std::string name;
    int         age;
};

int main(int argc, char **argv) {
    Person p;
    p.name      = "dashjay";
    p.age       = 21;
    Person *ptr = &p;
    // when you try to access the value by dot.
    // you will get error. Teahcers told you that
    // pls use -> to access member when you use a ptr
    // but they never tell you why.

    // after about 2 year I know that
    // *ptr.age be supposed to access the age
    // but the .(dot) has a higher priority than
    // The asterisk(*). so it will translate to
    // *(ptr.age), and cause error

    // you can use (*ptr).age
    std::cout << "Name: " << (*ptr).name << " Age: " << (*ptr).age << std::endl;

    // it looks awkward
    // so cpp offers a second member selection operator(->)
    std::cout << "Name: " << ptr->name << " Age: " << ptr->age << std::endl;
}
