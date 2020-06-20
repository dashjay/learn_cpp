#include <iostream>

int foo(int i) {
    return (i + 1);
}

int *allocateArray(int size) {
    return new int[ size ];
}

int main(){
    int x{1};
    x = foo(x);


    int s{128};
    int *myArr = allocateArray(s); 

    delete[] myArr;
}
