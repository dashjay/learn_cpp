#include <iostream>
#include <string>
// reference type

void PrintElements(int (&arr)[ 4 ]);
void changeToSix(int &ref);
int  main() {
    int  value{5};
    int &ref{value};
    // when decleare like above
    // we should say "address" of it means "reference to"
    int &z{ref};
    // this is als
    size_t size = sizeof(z);
    std::cout << "sizeof ref is " << size << "\n";

    // l-value and r-value
    // means that l-value can put on left to be
    // assigned by other value
    // value is not just value, it could be a expression
    // like (x + 2), it is a r-value, because we can not
    // assign to r-value

    // NOTE: const variables are considered non-modifiable l-values.
    // reference must be initialized
    // int &invaludRef  <- like this is invalid

    // 1. reference can't assign to r-value
    // 2. reference target can not be change, if you try to change a refvalue's
    // target, it will assign target value to origin reference value.
    int value1{5};
    int value2{6};

    int &ref1{value1}; // ref1 -> value1

    ref1 = value2; // value2 -> ref1 -> value1
    // the value1 will be asgin inderectly to value2

    // when ref as function parameters
    changeToSix(value1);
    // you need not to tranfer the parameter with a
    // opre(&).
    //
    int arr[]{1, 2, 3, 4};
    PrintElements(arr);


    // what difference between ref and ptr;

}

void changeToSix(int &ref) {
    ref = 6;
}

void PrintElements(int (&arr)[ 4 ]) {
    int length{static_cast<int>(std::size(arr))};

    for (int i{0}; i < length; i++) {
        std::cout << arr[ i ] << "\n";
    }
}
