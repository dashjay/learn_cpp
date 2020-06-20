#include <array>
#include <iostream>
struct Student {
    std::string name;
    int         age;
};
auto StudentCmp{
    [](const Student &a, const Student &b) { return (a.age < b.age); }};

int main() {
    std::array<Student, 8> arr{{{"Albert", 3},
                                {"Ben", 5},
                                {"Christine", 2},
                                {"Dan", 8}, // Dan has the most points (8).
                                {"Enchilada", 4},
                                {"Francis", 1},
                                {"Greg", 3},
                                {"Hagrid", 5}}

    };
    auto maxStudent = std::max_element(arr.begin(), arr.end(), StudentCmp);
    std::cout << maxStudent->name << " is the best student"
              << "\n";
}
