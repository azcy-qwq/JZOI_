#include <iostream>

int main() {
  int a;
  std::cout << std::boolalpha << (a < 0 || a == 0 || a > 0);
  return 0;
}