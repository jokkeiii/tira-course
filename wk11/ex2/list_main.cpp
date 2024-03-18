#include "../../utility/utility.h"
#include "list.h"
#include <iostream>
#include <string>

// convert Error_code enum to string
std::string errorToString(Error_code error) {
  switch (error) {
  case success:
    return "success";
  case fail:
    return "fail";
  case utility_range_error:
    return "utility_range_error";
  case underflow:
    return "underflow";
  case overflow:
    return "overflow";
  case fatal:
    return "fatal";
  case not_present:
    return "not_present";
  case duplicate_error:
    return "duplicate_error";
  case entry_inserted:
    return "entry_inserted";
  case entry_found:
    return "entry_found";
  case internal_error:
    return "internal_error";
  default:
    return "unknown_error";
  }
}

int main() {
  List<int> int_list;
  std::cout << std::boolalpha;
  for (size_t i = 0; i < 8; i++) {
    std::cout << "int_list.insert(" << i << ", " << i + 1 << ")  "
              << errorToString(int_list.insert(i, i + 1)) << std::endl;
  }
  std::cout << "int_list.size()  " << int_list.size() << std::endl;
  std::cout << "int_list.full()  " << int_list.full() << std::endl;
  std::cout << "int_list.empty()  " << int_list.empty() << std::endl;
  int_list.clear();
  std::cout << "int_list.clear()  " << std::endl;

  std::cout << "int_list.size()  " << int_list.size() << std::endl;
  std::cout << "int_list.full()  " << int_list.full() << std::endl;
  std::cout << "int_list.empty()  " << int_list.empty() << std::endl;

  return 0;
}
