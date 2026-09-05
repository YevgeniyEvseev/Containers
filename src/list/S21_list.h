namespace S21 {

template <typename T>
struct Node {
  T data;
  Node* Next;
  Node* Prev;
};

template <typename T>
class ListIterator {
 private:
  Node<T>* point;

 public:
  ListIterator(Node<T>* nd) : point(nd) {}
  Node<T>* operator++() { return point->Next; }
  Node<T>* operator--() { return point->Prev; }
  T& operator*() { return point->data; }
  bool operator==(ListIterator& other) { return (point == other.point); }
  bool operator!=(ListIterator& other) { return !(point == other.point); }
};

template <typename T>
class list {
 private:
  Node<T>* front;
  Node<T>* rear;

 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
  typedef ListIterator<T> iterator;

  list() : front(nullptr), rear(nullptr) {}
  list(size_type n) {
    if (n > 0) {
      rear = new Node<T>;
      rear->Next = rear->Prev = nullptr;
      front = rear;
      for (int i = 1; i < n; i++) {
        Node<T>* tmp = front;
        front = new Node<T>;
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
        rear = new Node<T>;
        rear->Next = rear->Prev = nullptr;
        front = rear;
        rear->data = item;
        front->data = item;
      } else {
        Node<T>* tmp = new Node<T>;
        tmp->Next = nullptr;
        tmp->Prev = front;
        tmp->data = item;
        front->Next = tmp;
        front = tmp;
      }
    }
  }
  iterator begin() { return ListIterator(rear); }
  iterator end() { return ListIterator(front); }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, list<T> lst) {
  ListIterator<T> end_iter = lst.end();
  for (ListIterator<T> i = lst.begin(); i != end_iter; ++i) {
    os << *i << ' ';
  }
  os << std::endl;
  return os;
}
}  // namespace S21