#include <iostream>

int recursion(int num) {
  if (num == 0) {
    return 0;
  } else if (num > 0 && (num % 2) == 0) {
    return recursion(num / 2);
  } else if (num > 0 && (num % 2) != 0) {
    return 1 + recursion(num - 1);
  } else {
    std::cout << "Number can't be negative!" << std::endl;
    return -1;
  }
}

int main() {
  std::cout << recursion(1) << std::endl;
  std::cout << recursion(2) << std::endl;
  std::cout << recursion(3) << std::endl;
  std::cout << recursion(99) << std::endl;
  std::cout << recursion(100) << std::endl;
  std::cout << recursion(128) << std::endl;
  return 0;
}
