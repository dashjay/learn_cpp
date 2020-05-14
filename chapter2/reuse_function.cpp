#include <iostream>
using namespace std;

int get_value_from_user() {
  int d{};
  cout << "Enter an integer" << endl;
  cin >> d;
  return d;
}

int main() {
  int a{get_value_from_user()};
  int b{get_value_from_user()};
  cout << a << " + " << b << " = " << a + b << endl;
  cout << a << " - " << b << " = " << a - b << endl;
}
