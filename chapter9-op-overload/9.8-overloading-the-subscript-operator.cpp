#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
struct StudentGrade {
    std::string name{};
    char        grade;
};

class GradeMap {
  private:
    std::vector<StudentGrade> m_map{};

  public:
    char &operator[](std::string name);
};
char &GradeMap::operator[](std::string name) {
    auto found{std::find_if(
        m_map.begin(), m_map.end(),
        [ &name ](StudentGrade &grade) { return grade.name == name; })};

    if (found != m_map.end()) {
        return found->grade;
    }

    m_map.push_back({name});
    return m_map.back().grade;
}

int main() {
    GradeMap grade{};
    grade[ "Joe" ]   = 'A';
    grade[ "Frank" ] = 'B';
    std::cout << "Joe has a grade of " << grade[ "Joe" ] << '\n';
    std::cout << "Frank has a grade of " << grade[ "Frank" ] << '\n';

    GradeMap g{};
    char &   K{g[ "K" ]};
    K = 'A';
    char &C{g[ "C" ]};
    C = 'B';

    std::cout << "K = " << K << "\n";
    std::cout << "C = " << C << "\n";
}
