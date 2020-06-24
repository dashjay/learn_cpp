// 1. class bundle data and function
//
// 2. access apecifier (public private protected)
//
// 3. encapsulation
//
// 4. constractors
//
// 5. member initializer
//
// 6. static member
//
// 7. desctructors
//
// 8. this pointer
//
// 9. const member function
//
// 10. friend functions
//
// 11. anonymous class
//
#include <cmath>
#include <iostream>

class Point2d {
  private:
    double m_x{0.0};
    double m_y{0.0};

  public:
    Point2d(double _x = 0.0, double _y = 0.0)
        : m_x{_x}
        , m_y{_y} {
    }
    void print() {
        std::printf("Point2d(%.1f, %.1f)\n", m_x, m_y);
    }
    friend double distanceTo(Point2d &from, Point2d &to);
};
double distanceTo(Point2d &from, Point2d &to) {
    return std::sqrt((from.m_x - to.m_x) * (from.m_x - to.m_x) +
                     (from.m_y - to.m_y) * (from.m_y - to.m_y));
}
int main() {
    Point2d first{};
    Point2d second{3.0, 4.0};
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceTo(first, second)
              << '\n';
    return 0;
}
