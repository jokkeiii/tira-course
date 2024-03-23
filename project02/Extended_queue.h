#pragma once
#include "../utility/utility.h"
#include "Queue.h"

template <typename T> class Extended_queue : public Queue<T> {
public:
  bool full() const;
  int size() const;
  void clear();
  Error_code serve_and_retrieve(T &item);
};

template <typename T> int Extended_queue<T>::size() const {
  typename Queue<T>::Node *window = this->front;
  int count = 0;
  while (window != nullptr) {
    window = window->next;
    count++;
  }
  return count;
}

template <typename T> bool Extended_queue<T>::full() const {
  typename Queue<T>::Node *temp = new (std::nothrow) typename Queue<T>::Node;
  if (temp == nullptr) {
    return true;
  } else {
    delete temp;
    return false;
  }
}

template <typename T> void Extended_queue<T>::clear() {
  while (this->serve() != underflow)
    ;
}

template <typename T>
Error_code Extended_queue<T>::serve_and_retrieve(T &item) {
  if (this->empty()) {
    return underflow;
  }
  this->retrieve(item);
  this->serve();
  return success;
}
