#include "queue.h"
#include "../../utility/utility.h"

Queue::Queue()
/*
Post: The Queue is initialized to be empty.
*/
{
  front = rear = NULL;
}

Error_code Queue::append(const Queue_entry &item)
/*
Post: Add item to the rear of the Queue and return a code of success
      or return a code of overflow if dynamic memory is exhausted.
*/
{
  Node *new_rear = new Node(item);
  if (new_rear == NULL)
    return overflow;
  if (rear == NULL)
    front = rear = new_rear;
  else {
    rear->next = new_rear;
    rear = new_rear;
  }
  return success;
}

Error_code Queue::serve()
/*
Post: The front of the Queue is removed.  If the Queue
      is empty, return an Error_code of underflow.
*/
{
  if (front == NULL)
    return underflow;
  Node *old_front = front;
  front = old_front->next;
  if (front == NULL)
    rear = NULL;
  delete old_front;
  return success;
}

bool Queue::empty() const {
  if (front == NULL)
    return true;
  return false;
}

Error_code Queue::retrieve(Queue_entry &item) const {
  /*
Post: The front of the Queue retrieved to the output
      parameter item. If the Queue is empty return an Error_code of underflow.
*/
  if (empty())
    return underflow;
  item = front->entry;
  return success;
}

Queue::~Queue() {
  /*
Post: Queue is emptied using serve.
*/
  while (serve() != underflow)
    ;
}

Queue::Queue(const Queue &original) : front(NULL), rear(NULL) {
  Node *temp = original.front;

  while (temp != NULL) {
    append(temp->entry);
    temp = temp->next;
  }
}

void Queue::operator=(const Queue &original) {
  if (this != &original) {
    while (serve() != underflow)
      ;

    Node *temp = original.front;
    while (temp != NULL) {
      append(temp->entry);
      temp = temp->next;
    }
  }
}
