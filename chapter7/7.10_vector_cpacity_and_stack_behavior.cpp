#include <iostream>
#include <vector>

void printStack(const std::vector<int> &stack) {
    for (auto elem : stack) {
        std::cout << elem << " ";
    }
    std::printf("(cap: %lu, len: %lu)\n", stack.capacity(), stack.size());
}

int main() {
    std::vector<int> myVec{1, 2, 3, 4, 5};
    std::cout << "Size of Vect: " << myVec.size() << "\n";
    std::cout << "Cap of Vect: " << myVec.capacity() << "\n";
    myVec = {1, 2, 3};
    std::cout << "Size of Vect: " << myVec.size() << "\n";
    std::cout << "Cap of Vect: " << myVec.capacity() << "\n";
    // after reassign the array
    // the size change to 3 but cap did not;
    // release and reallocate the mem will be a very complex operation;

    std::vector<int> stack;
    printStack(stack);
    stack.push_back(5);
    printStack(stack);

    stack.push_back(3);
    printStack(stack);

    stack.push_back(2);
    printStack(stack);

    std::printf("top: %d\n", stack.back());

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    return 0;
}
