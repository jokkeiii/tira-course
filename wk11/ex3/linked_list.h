template <class Node_entry> struct Node {
  Node_entry entry;
  Node<Node_entry> *next;

  // default constructor
  Node() : next(nullptr) {}

  // constructor with entry and optional link
  Node(Node_entry new_entry, Node<Node_entry> *link = nullptr)
      : entry(new_entry), next(link) {}
};
