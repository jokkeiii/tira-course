#include "Random.h"
#include <chrono>
#include <climits>
#include <iostream>
#include <vector>

void rand(int &data_size, int &search_num) {
  int num;

  Random rand(false);

  // chose to multiply the random_integer by 1 million for the searches to last
  // long enough to be measured with microseconds
  num = rand.random_integer(1, 1000) * 1000000;
  std::cout << "This instance data size is: " << num << std::endl;
  data_size = num;

  num = rand.random_integer(1, num);
  std::cout << "This instance search number is: " << num << std::endl;
  search_num = num;
}

void position_message(const int &search_num, const int &position) {
  if (position == -1)
    std::cout << search_num << " was not found in your list!" << std::endl;
  else
    std::cout << search_num << " was found at position " << position
              << std::endl;

  std::cout << std::endl << std::endl;
}

void create_search_data(std::vector<int> &list, const int &num) {
  std::cout << "Creating the data...\t";
  for (int i = 0; i < num * 2; i++) {
    // insert all odd numbers
    if (i % 2 != 0) {
      list.push_back(i);
    }
  }
  std::cout << "Done!" << std::endl << std::endl;
}

int init(std::vector<int> &data_list, int &search_num, int &loop) {
  int algorithm, num;
  std::cout << "What search algorithm is used. (1) sequential (2) binary (3)"
               " performance: ";
  std::cin >> algorithm;

  if (algorithm == 1 || algorithm == 2) {
    std::cout << "Hello! Give size of vector data: ";
    std::cin >> num;

    create_search_data(data_list, num);

    std::cout << "Now give integer which to search for: ";
    std::cin >> num;

  } else {
    std::cout << "How many times to loop for: ";
    std::cin >> num;

    loop = num;
  }

  search_num = num;
  return algorithm;
}

int binary_search(const std::vector<int> &list, const int &target) {
  std::cout << "Binary search started...\t";
  int top = list.size() - 1, bottom = 0, position, count = 0;

  while (bottom <= top) {
    position = bottom + (top - bottom) / 2;
    count++;

    if (list[position] == target) {
      std::cout << "Done!" << std::endl;
      std::cout << "Comparisons done: " << count << std::endl << std::endl;
      return position;
    } else if (list[position] < target)
      bottom = ++position;
    else
      top = --position;
  }

  std::cout << "Done!" << std::endl;
  std::cout << "Comparisons done: " << count << std::endl << std::endl;
  return -1;
}

int sequential_search(const std::vector<int> &list, const int &target) {
  std::cout << "Sequential search started...\t";
  int count = 0;
  for (size_t i = 0; i < list.size(); i++) {
    count++;
    if (list[i] == target) {
      std::cout << "Done!" << std::endl;
      std::cout << "Comparisons done: " << count << std::endl << std::endl;
      return i;
    }
  }
  std::cout << "Done!" << std::endl;
  std::cout << "Comparisons done: " << count << std::endl << std::endl;
  return -1;
}

int search_performance_showdown(const std::vector<int> &data,
                                const int &search_num) {
  int position;
  auto start_seq = std::chrono::steady_clock::now();
  position = sequential_search(data, search_num); // NOLINT
  auto end_seq = std::chrono::steady_clock::now();

  auto start_bin = std::chrono::steady_clock::now();
  position = binary_search(data, search_num);
  auto end_bin = std::chrono::steady_clock::now();

  auto elapsed_seq = std::chrono::duration_cast<std::chrono::microseconds>(
      end_seq - start_seq);
  auto elapsed_bin = std::chrono::duration_cast<std::chrono::microseconds>(
      end_bin - start_bin);

  std::cout << "Elapsed time with sequential search: " << elapsed_seq.count()
            << " microseconds" << std::endl;
  std::cout << "Elapsed time with binary search: " << elapsed_bin.count()
            << " microseconds" << std::endl;
  return position;
}

int main() {
  int position, algorithm, search_num, loop, size;
  std::vector<int> data;

  algorithm = init(data, search_num, loop);

  if (algorithm == 1) {
    position = sequential_search(data, search_num);
    position_message(search_num, position);
  } else if (algorithm == 2) {
    position = binary_search(data, search_num);
    position_message(search_num, position);
  } else if (algorithm == 3) {
    std::cout << "Looping performance mode for " << loop << " time(s)!"
              << std::endl
              << std::endl;
    for (int i = 0; i < loop; i++) {
      rand(size, search_num);
      create_search_data(data, size);
      position = search_performance_showdown(data, search_num);
      position_message(search_num, position);
    }
  } else {
    std::cout << "No algorithm for the selected number!" << std::endl;
  }

  return 0;
}