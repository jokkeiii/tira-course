// extended_queue.h
#pragma once
#include "queue.h"

class Extended_queue : public Queue {
public:
  bool full() const;
  int size() const;
  void clear();
  Error_code print_queue() const;
  Error_code serve_and_retrieve(Queue_entry &item);
};