#include <algorithm>
#include <functional>
#include <iostream>
int foo() // code starts at memory address 0x002717f0
{
    return 5;
}

// typedef make our function look smart

using comparisonFcn = std::function<bool(int, int)>;
bool ascending(int x, int y);

void selectionSort(int *array, int size, comparisonFcn compFcn = ascending) {
    for (int startIndex{0}; startIndex < (size - 1); ++startIndex) {
        int PtrIndex{startIndex};

        for (int currentIndex{startIndex + 1}; currentIndex < size;
             ++currentIndex) {
            if (compFcn(array[ PtrIndex ], array[ currentIndex ])) {
                PtrIndex = currentIndex;
            }
        }
        std::swap(array[ startIndex ], array[ PtrIndex ]);
    }
}

bool ascending(int x, int y) {
    return x > y;
}

bool descending(int x, int y) {
    return x < y;
}

void printArray(int *array, int size) {
    for (int index{0}; index < size; ++index) {
        std::cout << array[ index ] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << reinterpret_cast<void *>(foo)
              << '\n'; // we meant to call foo(), but instead we're
                       // printing foo itself!
    // pointer to function
    int (*funcPtr)(){foo};

    // implicit dereference is ok
    std::cout << (*funcPtr)() << std::endl;
    std::cout << funcPtr() << std::endl;

    // but the default value will not work when making a function call with a
    // function ptr;
    int array[]{4, 5, 7, 4, 3, 7, 8, 3, 4324, 578, 42, 65};

    int len = std::size(array);
    selectionSort(array, len, descending);
    printArray(array, len);

    selectionSort(array, len);
    printArray(array, len);
    return 0;
}
