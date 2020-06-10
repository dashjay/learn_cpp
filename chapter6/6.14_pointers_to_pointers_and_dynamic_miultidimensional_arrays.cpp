#include <iostream>

int getSingleIndex(int row, int col, int numberOfColumnsInArray);
int main() {
    int   a      = 0;
    int * ptr    = &a;
    int **ptrptr = &ptr;

    std::cout << **ptrptr << std::endl;

    // ptr of ptr, it's not something complex

    // int **ptrptr1 = &&a;
    // above is invalid
    int **ptrptr1 = nullptr;

    // arrays of pointers;

    // init a int* array which size is 10
    int **array = new int *[ 10 ];
    // in above the every elem int* is not initialized
    // if we want to new a int multidimention array
    // we can use auto

    auto array1 = new int[ 10 ][ 5 ];
    // but this can only work when 10 ,5 is a constant

    // when we want to use variable to create multifimensional_arrays like this,
    // it will be more complicated
    int   x{5};
    int   y{10};
    int **mArray = new int *[ y ];
    for (int count{0}; count < y; ++count) {
        mArray[ count ] = new int[ x ];
    }
    for (int i{0}; i < x; ++i) {
        for (int j{0}; j < y; j++) {
            std::cout << mArray[ i ][ j ] << " ";
        }
        std::cout << "\n";
    }

    // if you do this
    // when you delete, you shold also use a loop
    for (int i{0}; i < x; i++) {
        delete[] mArray[ i ];
    }
    delete[] mArray;

    // the declare(new) and delete are also very
    // complex. So we suggest that declare one two
    // dementional array as an one-dementional array.

    // do this instead

    int *OneArray = new int[ 50 ];

    OneArray[ getSingleIndex(9, 4, 5) ] = 3;
    // an array with size 5 * 10
    for (int i{0}; i < 10; i++) {
        for (int j{0}; j < 5; j++) {
            std::cout << OneArray[ getSingleIndex(i, j, 5) ] << " ";
        }
        std::cout << "\n";
    }
}

int getSingleIndex(int row, int col, int numberOfColumnsInArray) {
    return (row * numberOfColumnsInArray) + col;
}
