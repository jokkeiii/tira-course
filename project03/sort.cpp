#include <iostream>
#include <vector>

void init(std::vector<int> &list, const int &num) {
  for (size_t i = 0; i < num * 2; i++) {
    // insert all odd numbers
    if (i % 2 != 0) {
      list.push_back(i);
      // std::cout << i << std::endl; // debug
    }
  }
}

// int menu()

int binary_search(const std::vector<int> &list, const int &target) {
  int top = list.size() - 1, bottom = 0, position;

  while (bottom <= top) {
    int position = bottom + (top - bottom) / 2;

    if (list[position] == target)
      return position;
    else if (list[position] < target)
      bottom = ++position;
    else
      top = --position;
  }

  return -1;
}

int sequential_search(const std::vector<int> &list, const int &target) {
  for (size_t i = 0; i < list.size(); i++) {
    if (list[i] == target)
      return i;
  }
  return -1;
}

int main() {
  int num, position, algorithm;
  std::vector<int> data;

  std::cout << "Hello! Give size of vector data: ";
  std::cin >> num;

  init(data, num);

  std::cout << "Now give integer which to search for: ";
  std::cin >> num;

  std::cout << "What search algorithm is used. (1) sequential (2) binary: ";
  std::cin >> algorithm;

  if (algorithm == 1)
    position = sequential_search(data, num);
  else if (algorithm == 2)
    position = binary_search(data, num);
  else {
    // std::cout
  }

  if (position == -1)
    std::cout << num << " was not found in your list!" << std::endl;
  else
    std::cout << num << " was found at position " << position << std::endl;

  return 0;
}