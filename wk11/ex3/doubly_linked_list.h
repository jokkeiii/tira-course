template <class Node_entry> struct Node {
  Node_entry entry;
  Node<Node_entry> *next;
  Node<Node_entry> *back;

  Node() : next(nullptr), back(nullptr) {}

  // constructor with entry and optional links
  Node(Node_entry new_entry, Node<Node_entry> *link_back = nullptr,
       Node<Node_entry> *link_next = nullptr)
      : entry(new_entry), back(link_back), next(link_next) {}
};
