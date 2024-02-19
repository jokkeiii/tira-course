// stack.cpp
#include "stack.h"
#include "utility.h"

Stack::Stack() : top_node(nullptr) {}

Stack::~Stack() {
  while (!empty()) {
    pop();
  }
}

bool Stack::empty() const { return top_node == nullptr; }

Error_code Stack::push(const Stack_entry &item) {
  Node *new_top = new Node(item, top_node);
  if (new_top == nullptr)
    return overflow;
  top_node = new_top;
  return success;
}

Error_code Stack::pop() {
  if (empty())
    return underflow;
  Node *old_top = top_node;
  top_node = old_top->next;
  delete old_top;
  return success;
}

Error_code Stack::top(Stack_entry &item) const {
  if (empty())
    return underflow;
  item = top_node->entry;
  return success;
}
