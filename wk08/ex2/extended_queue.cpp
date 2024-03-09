#include "extended_queue.h"
#include "../../utility/utility.h"
#include "../ex1/queue.h"

int Extended_queue::size() const
/*
Post: Return the number of entries in the Extended_queue.
*/
{
  Node *window = front;
  int count = 0;
  while (window != NULL) {
    window = window->next;
    count++;
  }
  return count;
}

bool Extended_queue::full() const {
  Node *temp = new (std::nothrow) Node;
  if (temp == NULL) {
    return true;
  } else {
    delete temp;
    return false;
  }
}

void Extended_queue::clear() {
  while (serve() != underflow)
    ;
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item) {
  if (empty()) {
    return underflow;
  }
  retrieve(item);
  serve();
  return success;
}
