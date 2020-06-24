#include <iostream>

struct DateStruct {
    int year;
    int month;
    int day;
};

class DateClass {
  public:
    int  m_year;
    int  m_month;
    int  m_day;
    void print() {
        std::cout << m_year << "/" << m_month << "/" << m_day << "\n";
    }
};

void print(const DateStruct &date) {
    std::cout << date.year << "/" << date.month << "/" << date.day << "\n";
}
int main() {
    DateStruct today{2020, 6, 20};
    today.day = 21;
    print(today);

    DateClass today2{2020, 6, 20};
    today2.m_day = 21;
    today2.print();
    return 0;
}

