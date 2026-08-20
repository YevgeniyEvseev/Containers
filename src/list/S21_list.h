namespace S21 {
template <typename T>
class list {
 public:
  struct Node {
    T data;
    Node* Next;
    Node* Prev;
  };

 private:
  Node* front;
  Node* rear;

 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  list() : front(nullptr), rear(nullptr) {}
  list(size_type n) {
    if (n > 0) {
      rear = new Node;
      rear->Next = rear->Prev = nullptr;
      front = rear;
      for (int i = 1; i < n; i++) {
        Node* tmp = front;
        front = new Node;
        front->Next = nullptr;
        front->Prev = tmp;
        tmp->Next = front;
      }
    }
  }
  list(std::initializer_list<value_type> const& items)
      : front(nullptr), rear(nullptr) {
    for (auto item : items) {
      if (rear == nullptr) {
        rear = new Node;
        rear->Next = rear->Prev = nullptr;
        front = rear;
        rear->data = item;
      } else {
        Node* tmp = front;
        front = new Node;
        front->Next = nullptr;
        front->Prev = tmp;
        tmp->Next = front;
        rear->data = item;
      }
    }
  }
};
template <typename T>
std::ostream& operator<<(std::ostream& os, list<T>& lst) {
  while (front->Next != nullptr) {
    Node* tmp = lst->rear os <<
  }
}
}  // namespace S21