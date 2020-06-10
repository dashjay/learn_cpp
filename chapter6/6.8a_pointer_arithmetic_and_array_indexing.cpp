#include <algorithm>
#include <iostream>
#include <iterator> // for std::begin and std::end
// if we have a int ptr
// we can use ptr + 1 to represent the value next to ptr (if it is a array [or
// not]);

int *find(int *begin, int *end, int target);
bool isVowel(char ch) {
    switch (ch) {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
        return true;
    default:
        return false;
    }
}

int main() {
    int  value{7};
    int *ptr{&value};

    std::cout << ptr << "\n";
    std::cout << ptr + 1 << "\n";
    std::cout << ptr + 2 << "\n";
    std::cout << ptr + 3 << "\n";
    /*
     *
    0x7ffee8c076fc
    0x7ffee8c07700
    0x7ffee8c07704
    0x7ffee8c07708
     *
     */
    // above will print address after ptr
    // these address defer by 4
    // a int is 4 byte on my machine

    short  value1{7};
    short *ptr1{&value1};

    std::cout << ptr1 << "\n";
    std::cout << ptr1 + 1 << "\n";
    std::cout << ptr1 + 2 << "\n";
    std::cout << ptr1 + 3 << "\n";
    /*
     *
    0x7ffee17e76ee
    0x7ffee17e76f0
    0x7ffee17e76f2
    0x7ffee17e76f4
    * ee + 2 = f0
    */

    // we can use the std::count_if to get the number of vowel ...
    char myName[]{"Dashjay"};
    auto numVowel{std::count_if(std::begin(myName), std::end(myName), isVowel)};
    std::cout << myName << " has " << numVowel << " Vowels\n";

    int arr[]{2, 5, 4, 10, 8, 20, 16, 40};
    // Search for the first element with value 20.
    int *found{find(std::begin(arr), std::end(arr), 20)};

    // If an element with value 20 was found, print it.
    if (found != std::end(arr)) {
        std::cout << *found << '\n';
    }

    return 0;
}

int *find(int *begin, int *end, int target) {
    for (int *b{begin}; b != end; ++b) {
        if (*b == target) {
            return b;
        } else {
            std::cout << "Compare " << *b << " With " << target << std::endl;
        }
    }
    return end;
}
