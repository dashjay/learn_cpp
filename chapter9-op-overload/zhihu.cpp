#include <iostream>

class Yuan {
  private:
    int m_value;

  public:
    Yuan(int y)
        : m_value{y} {
    }
    int getValue() {
        return m_value;
    }
};

class Jiao {
  private:
    int m_value;

  public:
    Jiao(int j)
        : m_value{j} {
    }
    Jiao(Yuan &a);

    Jiao &operator=(Yuan &a);

    int getValue() {
        return m_value;
    }

    void print() {
        std::cout << m_value << " 角\n";
    }
};

Jiao::Jiao(Yuan &a) {
    std::cout << "重载拷贝构造\n";
    m_value = a.getValue() * 10;
}

void printJiao(Jiao &a) {
    std::cout << a.getValue() << " 角\n";
}
int main() {
    Yuan y{1}; // 1元
    Jiao j1 = y;
    j1.print();

    Jiao j2{y};
    j2.print();
}
