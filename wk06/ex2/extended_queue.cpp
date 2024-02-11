// extended_queue.cpp
#include "extended_queue.h"

bool Extended_queue::full() const { return count >= maxqueue; }

int Extended_queue::size() const
/*
Post:   Return the number of entries in the Extended_queue.
*/
{
  return count;
}

void Extended_queue::clear() {
  count = 0;
  rear = maxqueue - 1;
  front = 0;
}

Error_code Extended_queue::print_queue() const {
  if (count <= 0)
    return underflow;

  for (int i = 0; i < count; i++) {
    cout << entry[i] << endl;
  }

  return success;
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item) {
  if (empty())
    return underflow;

  // retrieve the front item
  Error_code result = retrieve(item);
  if (result != success)
    return result; // if failed, return the error code

  // serve the front
  return serve(); // return the serve result
}
