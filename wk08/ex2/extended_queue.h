#pragma once
#include "../../utility/utility.h"
#include "../ex1/queue.h"

class Extended_queue : public Queue {
public:
  bool full() const;
  int size() const;
  void clear();
  Error_code serve_and_retrieve(Queue_entry &item);
};