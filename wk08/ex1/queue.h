#pragma once
#include "../../utility/utility.h"

typedef char Queue_entry;

struct Node {
  //  data members
  Node_entry entry;
  Node *next;
  //  constructors
  Node();
  Node(Node_entry item, Node *add_on = NULL);
};

class Queue {
public:
  //  standard Queue methods
  Queue();
  bool empty() const;
  Error_code append(const Queue_entry &item);
  Error_code serve();
  Error_code retrieve(Queue_entry &item) const;
  //  safety features for linked structures
  ~Queue();
  Queue(const Queue &original);
  void operator=(const Queue &original);

protected:
  Node *front, *rear;
};