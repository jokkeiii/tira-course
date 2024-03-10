#include <iostream>

int recursion(int num) {
  if (num <= 1) {
    return 0;
  } else if (num > 1 && (num % 2) == 0) {
    return num + recursion(num / 2);
  } else if (num > 1 && (num % 2) != 0) {
    return recursion((num + 1) / 2) + recursion((num - 1) / 2);
  } else {
    std::cout << "Number can't be negative!" << std::endl;
    return -1;
  }
}

int main() {
  std::cout << recursion(1) << std::endl;
  std::cout << recursion(2) << std::endl;
  std::cout << recursion(3) << std::endl;
  std::cout << recursion(4) << std::endl;
  std::cout << recursion(5) << std::endl;
  std::cout << recursion(6) << std::endl;
  return 0;
}
