#include <iostream>
#include <vector>
class Shape {
  public:
    virtual std::ostream &print(std::ostream &in) const = 0;
    friend std::ostream & operator<<(std::ostream &out, const Shape &s) {
        return s.print(out);
    }
    virtual ~Shape() = default; // why use default ?
};

class Point {
  private:
    double m_x;
    double m_y;
    double m_z;

  public:
    Point(double _x = 0, double _y = 0, double _z = 0)
        : m_x{_x}
        , m_y{_y}
        , m_z{_z} {
    }
    friend std::ostream &operator<<(std::ostream &out, const Point &p) {
        char result[ 64 ];
        std::sprintf(result, "Point(%.1f, %.1f, %.1f)", p.m_x, p.m_y, p.m_z);
        out << result;
        return out;
    }
};

class Triangle : public Shape {
  private:
    Point m_point[ 3 ];

  public:
    virtual std::ostream &print(std::ostream &out) const override {
        out << "Triangle(" << m_point[ 0 ] << ", " << m_point[ 1 ] << ", "
            << m_point[ 2 ] << ")";
        return out;
    }
    // virtual ~Triangle() {
    //}
    Triangle(Point a, Point b, Point c) {
        m_point[ 0 ] = a;
        m_point[ 1 ] = b;
        m_point[ 2 ] = c;
    }
};

class Circle : public Shape {
  private:
    Point  m_center;
    double m_radius;

  public:
    virtual std::ostream &print(std::ostream &out) const override {
        out << "Circle(" << m_center << ", radius " << m_radius << ")";
        return out;
    }
    Circle(Point c, double radius)
        : m_center{c}
        , m_radius{radius} {
    }
    double getRadius() const {
        return m_radius;
    }
};

double getLargestRadius(std::vector<Shape *> v) {
    double largest = 0;
    for (Shape *s : v) {
        Circle *c = dynamic_cast<Circle *>(s);
        if (c && c->getRadius() > largest) {
            largest = c->getRadius();
        }
    }
    return largest;
}
// int main() {
//    Circle c{Point{1, 2, 3}, 7};
//    std::cout << c << '\n';
//    Triangle t{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}};
//    std::cout << t << '\n';
//    return 0;
// }

int main() {
    std::vector<Shape *> v{
        new Circle{Point{1, 2, 3}, 7},
        new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
        new Circle{Point{4, 5, 6}, 3}};
    for (Shape *s : v) {
        std::cout << *s << "\n";
    }
    std::cout << "The Largest radius is: " << getLargestRadius(v) << "\n";
    for (const auto *element : v) {
        delete element;
    }
    return 0;
}
