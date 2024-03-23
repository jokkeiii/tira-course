#pragma once
#include "../utility/utility.h"

template <typename T> class Queue {
public:
  // standard Queue methods
  Queue();
  bool empty() const;
  Error_code append(const T &item);
  Error_code serve();
  Error_code retrieve(T &item) const;
  // safety features for linked structures
  ~Queue();
  Queue(const Queue &original);
  Queue &operator=(const Queue &original);

protected:
  struct Node {
    T entry;
    Node *next;
    // constructors
    Node() : next(nullptr) {}
    Node(T item, Node *add_on = nullptr) : entry(item), next(add_on) {}
  };
  Node *front, *rear;
};

template <typename T> Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

template <typename T> bool Queue<T>::empty() const { return front == nullptr; }

template <typename T> Error_code Queue<T>::append(const T &item) {
  Node *new_rear = new Node(item);
  if (new_rear == nullptr)
    return overflow;
  if (rear == nullptr)
    front = rear = new_rear;
  else {
    rear->next = new_rear;
    rear = new_rear;
  }
  return success;
}

template <typename T> Error_code Queue<T>::serve() {
  if (front == nullptr)
    return underflow;
  Node *old_front = front;
  front = old_front->next;
  if (front == nullptr)
    rear = nullptr;
  delete old_front;
  return success;
}

template <typename T> Error_code Queue<T>::retrieve(T &item) const {
  if (empty())
    return underflow;
  item = front->entry;
  return success;
}

template <typename T> Queue<T>::~Queue() {
  while (!empty())
    serve();
}

template <typename T>
Queue<T>::Queue(const Queue &original) : front(nullptr), rear(nullptr) {
  Node *temp = original.front;
  while (temp != nullptr) {
    append(temp->entry);
    temp = temp->next;
  }
}

template <typename T> Queue<T> &Queue<T>::operator=(const Queue &original) {
  if (this != &original) {
    while (!empty())
      serve();
    Node *temp = original.front;
    while (temp != nullptr) {
      append(temp->entry);
      temp = temp->next;
    }
  }
  return *this;
}
