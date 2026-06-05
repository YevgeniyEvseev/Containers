#include <iostream>

template <typename T>
class stack {
 private:
  struct Node {
    Node* next;
    T data;
  };
  Node* top;
  Node* next;
  size_t size;

 public:
  stack(/* args */);
  ~stack();
};

stack::stack(/* args */) {}

stack::~stack() {}
