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
  stack(stack&& s) : top(s.top), size(s.size) { s = nullptr; }
  stack& operator=(stack&& s);
  stack& operator=(const stack& s);
  ~stack();

  const T& top_stack() { return top.data; }
  bool empty() { return top == nullptr; }
  size_t size_stack() { return size; }
  void push(const T& value) {
    Node* tmp = new Node;
    tmp->data = value;
    tmp->next = top;
    top = tmp;
    size++;
  }
  T pop();
  void swap(stack& other);
};

template <typename T>
T stack<T>::pop() {
  if (top == nullptr) std::out_of_range("size=0");
  Node* tmp;
  if (top->next != nullptr) tmp = top->next;
  T res = top->data;
  delete top;
  top = tmp;
  return res;
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
  return *this;
}

template <typename T>
stack<T>::stack(std::initializer_list<T> const& items) {
  for (const auto& item : items) {
    push(item);
  }
}

template <typename T>
stack<T>::stack(const stack& s) {
  copy_stack(s);
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
  if (top != nullptr) do {
      Node* tmp = top->next;
      delete top;
      top = tmp;
    } while (top != nullptr);
}

template <typename T>
void stack<T>::swap(stack& other) {
  stack& tmp(*this);
  *this = other;
  other = tmp;
}