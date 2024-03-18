#include "../ex2/list.h"
#include "list_operations.h"
#include <iostream>

int main() {
  List<char> char_list;
  char entry;

  insert_first('B', char_list);
  insert_last('C', char_list);
  insert_first('A', char_list);

  remove_first(entry, char_list);
  std::cout << "Removed first: " << entry << std::endl;

  remove_last(entry, char_list);
  std::cout << "Removed last: " << entry << std::endl;

  return 0;
}
