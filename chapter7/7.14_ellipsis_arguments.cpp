#include <cstdarg>
#include <iostream>

// should never use ellipsis
// ..... never
double findAverage(int count, ...) {
    double  sum = 0;
    va_list list;
    va_start(list, count);

    for (int arg = 0; arg < count; ++arg) {
        sum += va_arg(list, int);
    }
    va_end(list);

    return sum / count;
}

double findAverage_1(int start, ...) {
    double  sum = start;
    va_list list;
    va_start(list, start);

    int count = 1;
    while (true) {
        int arg = va_arg(list, int);
        if (arg == -1) {
            break;
        }
        sum += arg;
        count++;
    }
    va_end(list);
    return sum / count;
}

int main() {
    std::cout << findAverage(5, 4, 4, 4, 3, 3) << "\n";
    std::cout << findAverage_1(3, 4, 5, 6, 7, -1) << "\n";

}
