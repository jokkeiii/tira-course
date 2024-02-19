// stack.h
#pragma once
#include "utility.h"

typedef double Stack_entry;

struct Node {
  Stack_entry entry;
  Node *next;

  Node(Stack_entry item, Node *add_on = nullptr) : entry(item), next(add_on) {}
};

class Stack {
public:
  Stack();
  ~Stack(); // Destructor to free memory
  bool empty() const;
  Error_code pop();
  Error_code top(Stack_entry &item) const;
  Error_code push(const Stack_entry &item);

private:
  Node *top_node; // Pointer to the top of the stack
};
