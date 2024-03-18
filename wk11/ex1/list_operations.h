#pragma once
#include "../ex2/list.h"

template <class List_entry>
Error_code insert_first(const List_entry &x, List<List_entry> &a_list) {
  // Pre: a_list is initialized, not necessarily containing entries.
  // Post: If the operation is successful, x is the first entry of a_list.
  //       If the operation fails (e.g., due to memory limitations),
  //       an error code is returned.

  return a_list.insert(0, x); // Insert x at position 0
}

template <class List_entry>
Error_code remove_first(List_entry &x, List<List_entry> &a_list) {
  // Pre: a_list is initialized and contains at least one entry.
  // Post: If the operation is successful, the first entry of a_list
  // is removed and copied into x.
  //       If the operation fails (e.g., list is empty), an error code
  //       is returned.

  if (a_list.empty())
    return underflow;         // Error if list is empty
  return a_list.remove(0, x); // Remove the first entry
}

template <class List_entry>
Error_code insert_last(const List_entry &x, List<List_entry> &a_list) {
  // Pre: a_list is initialized, not necessarily containing entries.
  // Post: If the operation is successful, x is the last entry of a_list.
  //       If the operation fails (e.g., due to memory limitations),
  //       an error code is returned.

  int last_position =
      a_list.size(); // The new last position is equal to the current size
  return a_list.insert(last_position, x); // Insert x at the last position
}

template <class List_entry>
Error_code remove_last(List_entry &x, List<List_entry> &a_list) {
  // Pre: a_list is initialized and contains at least one entry.
  // Post: If the operation is successful, the last entry of a_list is
  // removed and copied into x.
  //       If the operation fails (e.g., list is empty), an error code
  //       is returned.

  if (a_list.empty())
    return underflow;
  int last_position = a_list.size() - 1;
  return a_list.remove(last_position, x);
}