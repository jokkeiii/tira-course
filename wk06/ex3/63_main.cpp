// 63_main.cpp
#include "extended_queue.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

char analyze_input() {
  string input;
  // read the whole line of input
  getline(cin, input);

  Extended_queue left_part_queue;
  int input_length = input.length();
  // position of colon in the string, -1 means not found
  int colon_position = -1;

  // find the colon position and enqueue the left part characters
  for (int i = 0; i < input_length; ++i) {
    if (input[i] == ':') {
      colon_position = i;
      // stop when we find the first colon
      break;
    } else {
      // enqueue left part characters
      left_part_queue.append(input[i]);
    }
  }

  // if no colon found, return 'N'
  if (colon_position == -1)
    return 'N';

  // process the right part of the input
  int right_part_length = input_length - colon_position - 1;
  int left_part_length = left_part_queue.size();

  // compare lengths of left and right parts
  if (left_part_length > right_part_length)
    return 'L';
  else if (right_part_length > left_part_length)
    return 'R';
  else {
    // lengths are equal, compare the content
    bool is_equal = true;
    for (int i = colon_position + 1; i < input_length; ++i) {
      Queue_entry front_char;
      if (left_part_queue.serve_and_retrieve(front_char) != success ||
          front_char != input[i]) {
        is_equal = false;
        // stop if characters do not match
        break;
      }
    }
    if (is_equal)
      // same content
      return 'S';
    else
      // different content but same length
      return 'D';
  }
}

int main() {
  cout << "Enter input: ";
  char result = analyze_input();
  cout << "Output: " << result << endl;
  return 0;
}
