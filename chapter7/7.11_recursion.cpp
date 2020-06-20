#include <iostream>
#include <vector>
// recursive is not a very good way to do sth.
// but sometimes we have to do so
// we must set a good recersive termination conditions
//

void countDown(int count) {
    std::cout << "Push" << count << "\n";
    if (count > 1) { // this is recersive termination
        countDown(count - 1);
    }
    std::cout << "Pop " << count << "\n";
}

// sumTo
int sumTo(int sumto) {
    if (sumto == 0) {
        return 0;
    } else if (sumto == 1) {
        return 1;
    } else {
        return sumTo(sumto - 1) + sumto;
    }
}
static int call_fib_time = 0;
int        fibonacci(int count) {

    ++call_fib_time;
    if (count == 0) {
        return 0;
    } else if (count == 1) {
        return 1;
    } else {
        return fibonacci(count - 1) + fibonacci(count - 2);
    }
}

static std::vector<int> results{0, 1};

static int call_mem_fib_time = 0;

int memfibonacci(int count) {
    ++call_mem_fib_time;
    if (count < static_cast<int>(std::size(results))) {
        return results[ count ];
    } else {
        results.push_back(memfibonacci(count - 1) + memfibonacci(count - 2));
        return results[ count ];
    }
}

int iter_fibonacci(int count) {
    if (count == 0) {
        return 0;
    } else if (count == 1) {
        return 1;
    } else {
        int res[ 2 ] = {0, 1};
        for (int i = 2; i <= count; ++i) {
            res[ i % 2 ] = res[ (i - 1) % 2 ] + res[ (i - 2) % 2 ];
        }
        return res[ count % 2 ];
    }
}
int main() {
    countDown(5);
    std::cout << "sumTo(100) = " << sumTo(100) << "\n";
    std::cout << "fibonacci(10) = " << fibonacci(10) << " | " << call_fib_time
              << " call in total \n";
    std::cout << "memfibonacci(10) = " << memfibonacci(10) << " | "
              << call_mem_fib_time << " call in total \n";
    std::cout << "iter_fibonacci(10) = " << iter_fibonacci(10) << "\n";
    return 0;
}
