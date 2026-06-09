#include <iostream>

template <typename T>
class stack {
 private:
  struct Node {
    Node* next;
    T data;
  };
  Node* top;
  size_t size;
  stack& copy_stack(const stack& s);

 public:
  stack() : top(nullptr), size(0) {}
  stack(std::initializer_list<T> const& items);
  stack(const stack& s);
  stack(stack&& s) : top(s.top), size(s.size) { s = nullptr };
  stack& operator=(stack&& s);
  stack& operator=(const stack& s);
  ~stack();

  const T& top() { return top; }
  bool empty() { return top == nullptr; }
  size_type size() { return size; }
  void push(const T& value) {
    Node* tmp = new Node;
    tmp->data = value;
    tmp->next = top;
    top = tmp;
    size++;
  }
  T& pop();
  void swap(stack& other);
};

template <typename T>
T& stack<T>::pop() {
  Node* tmp;
  if (top.next != nullptr) tmp = top->next;
  T res = top->data;
  delete top;
  top = tmp;
  return T;
}

template <typename T>
stack<T>& stack<T>::copy_stack(const stack& s) {
  do {
    Node* tmp = new Node;
    tmp->next = top;
    tmp->data = s.top->data;
    top = tmp;
    size++;
    s.top = s.top->next;
  } while (s.top != nullptr);
  return *this
}

template <typename T>
stack<T>::stack(std::initializer_list<T> const& items) {
  size = 0;
  for (items.begin; items.end; items++) {
    Node* tmp = new Node;
    tmp->next = top;
    tmp->data = items;
    top = tmp;
    size++;
  }
}

template <typename T>
stack<T>::stack(const stack& s) {
  return copy_stack(s);
}

template <typename T>
stack<T>& stack<T>::operator=(stack&& s) {
  if (this != &s) {
    top = s.top;
    size = s.size;
    s.top = nullptr;
    s.size = 0;
  }
  return *this;
}

template <typename T>
stack<T>& stack<T>::operator=(const stack& s) {
  if (this != &s) {
    this.~stack();
    *this = copy_stack(s);
  }
  return *this;
}

template <typename T>
stack<T>::~stack() {
  do {
    Node* tmp = top->next;
    delete top;
    top = tmp;
  } while (top != nullptr)
}

template <typename T>
void stack<T>::swap(stack& other) {
  
}