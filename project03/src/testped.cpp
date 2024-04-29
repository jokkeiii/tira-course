#include "Random.h"
#include <chrono>
#include <iostream>
#include <utility>
#include <vector>

int partition(std::vector<int> &list, const int &low, const int &high) {
  int pivot = list[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    // if current element is smaller than or equal to pivot
    if (list[j] <= pivot) {
      // increment index of smaller element
      i++;
      // swap the values
      std::swap(list[i], list[j]);
    }
  }
  std::swap(list[i + 1], list[high]);
  // return pivot index
  return (i + 1);
}

void quicksort(std::vector<int> &list, const int &low, const int &high) {
  if (low < high) {
    int part_index = partition(list, low, high);

    // separate the list into two parts and recursively sort them
    quicksort(list, low, part_index - 1);
    quicksort(list, part_index + 1, high);
  }
}

void print_data(const std::vector<int> &list, const int &print_size) {
  std::cout << "Printing first " << print_size << " numbers from the beginning"
            << std::endl;
  for (int i = 0; i < print_size; i++) {
    std::cout << list[i] << " ";
    if (i % 14 == 0 && i != 0) {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl << std::endl;
}

int insertion_sort(std::vector<int> &list) {
  std::cout << "Insertion sort started...\t";
  for (long unsigned int i = 0; i < list.size(); i++) {
    int key = list[i];
    int j = i - 1;

    while (j >= 0 && list[j] > key) {
      list[j + 1] = list[j];
      j = j - 1;
    }
    list[j + 1] = key;
  }
  std::cout << "Done!" << std::endl << std::endl;
  return 0;
}

void create_sort_data(std::vector<int> &list, const int &data_size) {
  std::cout << "Creating the data...\t";
  Random rand(false);
  for (int i = 0; i < data_size * 2; i++) {
    list.push_back(rand.random_integer(1, 10000));
  }
  std::cout << "Done!" << std::endl << std::endl;
}

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

int init(std::vector<int> &data_list, int &search_num, int &loop,
         int &print_size) {
  int algorithm, num;
  std::cout << "What data algorithm to use:\n\t(1) sequential search,\n"
               "\t(2) binary search,\n\t(3) search performance,\n"
               "\t(4) insertion sort or\n\t(5) quicksort\n:";
  std::cin >> algorithm;
  print_size = 0;
  std::cout << std::endl;

  if (algorithm == 1 || algorithm == 2) {
    std::cout << "Give size of vector data: ";
    std::cin >> num;

    create_search_data(data_list, num);

    std::cout << "Now give integer which to search for: ";
    std::cin >> num;

    search_num = num;
  } else if (algorithm == 3) {
    std::cout << "How many times to loop for: ";
    std::cin >> num;

    loop = num;
  } else if (algorithm == 4 || algorithm == 5) {
    std::cout << "Give size of vector data: ";
    std::cin >> num;

    create_sort_data(data_list, num);

    std::cout << "Now give size of data to be shown: ";
    std::cin >> num;

    long unsigned int temp_num = num;

    while (temp_num > data_list.size() || temp_num < 0) {
      std::cout
          << "Number has to be smaller or equal to data size and larger than 0."
          << std::endl;
      std::cout << "Now give size of data to be shown: ";
      std::cin >> num;
      temp_num = num;
    }
    print_size = num;
  }

  return algorithm;
}

int binary_search(const std::vector<int> &list, const int &target,
                  const bool &extra_info) {
  std::cout << "Binary search started...\t";
  int top = list.size() - 1, bottom = 0, position, count = 0;

  while (bottom <= top) {
    position = bottom + (top - bottom) / 2;
    count++;

    if (list[position] == target) {
      std::cout << "Done!" << std::endl;
      if (extra_info)
        std::cout << "Comparisons done: " << count << std::endl << std::endl;
      return position;
    } else if (list[position] < target)
      bottom = ++position;
    else
      top = --position;
  }

  std::cout << "Done!" << std::endl;
  if (extra_info)
    std::cout << "Comparisons done: " << count << std::endl << std::endl;
  return -1;
}

int sequential_search(const std::vector<int> &list, const int &target,
                      const bool &extra_info) {
  std::cout << "Sequential search started...\t";
  int count = 0;
  for (size_t i = 0; i < list.size(); i++) {
    count++;
    if (list[i] == target) {
      std::cout << "Done!" << std::endl;
      if (extra_info)
        std::cout << "Comparisons done: " << count << std::endl << std::endl;
      return i;
    }
  }
  std::cout << "Done!" << std::endl;
  if (extra_info)
    std::cout << "Comparisons done: " << count << std::endl << std::endl;
  return -1;
}

int search_performance_showdown(const std::vector<int> &data,
                                const int &search_num) {
  int position;
  auto start_seq = std::chrono::steady_clock::now();
  position = sequential_search(data, search_num, true); // NOLINT
  auto end_seq = std::chrono::steady_clock::now();

  auto start_bin = std::chrono::steady_clock::now();
  position = binary_search(data, search_num, true);
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
  int position, algorithm, search_num, loop, size, print_size;
  std::vector<int> data;

  algorithm = init(data, search_num, loop, print_size);

  if (algorithm == 1) {
    position = sequential_search(data, search_num, false);
    position_message(search_num, position);
  } else if (algorithm == 2) {
    position = binary_search(data, search_num, false);
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
  } else if (algorithm == 4) {
    print_data(data, print_size);
    insertion_sort(data);
    print_data(data, print_size);
  } else if (algorithm == 5) {
    print_data(data, print_size);
    int data_size = data.size();
    std::cout << "Quicksort started...\t";
    quicksort(data, 0, data_size - 1);
    std::cout << "Done!" << std::endl << std::endl;
    print_data(data, print_size);
  } else {
    std::cout << "No algorithm for the selected number!" << std::endl;
    std::cout << "Exiting..." << std::endl;
  }
  return 0;
}