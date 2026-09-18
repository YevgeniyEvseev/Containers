#define MAX_SIZE 9223372036854775807

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
  Node<T>* operator++() { return point = point->Next; }
  Node<T>* operator++(int) { return point = point->Next; }
  Node<T>* operator--() { return point = point->Prev; }
  T& operator*() { return point->data; }
  bool operator==(ListIterator& other) { return (point == other.point); }
  bool operator!=(ListIterator& other) { return point != other.point; }
  T& getdata() { return point->data; }
  Node<T>* get_point() { return point; }
};

template <typename T>
class ListConstIterator {
 private:
  const Node<T>* point;

 public:
  ListConstIterator(Node<T>* nd) : point(nd) {}
  Node<T>* operator++() const { return point = point->Next; }
  Node<T>* operator++(int) const { return point = point->Next; }
  Node<T>* operator--() const { return point = point->Prev; }
  T& operator*() { return point->data; }
  bool operator==(const ListConstIterator& other) const {
    return (point == other.point);
  }
  bool operator!=(const ListConstIterator& other) const {
    return !(point == other.point);
  }
};

template <typename T>
class list {
 private:
  Node<T>* front_n;
  Node<T>* rear;

  void create_node(T& item) {
    if (rear == nullptr) {
      rear = new Node<T>;
      rear->Next = rear->Prev = nullptr;
      front_n = rear;
      rear->data = item;
      front_n->data = item;
    } else {
      Node<T>* tmp = new Node<T>;
      tmp->Next = nullptr;
      tmp->Prev = front_n;
      tmp->data = item;
      front_n->Next = tmp;
      front_n = tmp;
    }
  }

  void create_end_node(size_t n) {
    Node<T>* end_l = new Node<T>;
    front_n->Next = end_l;
    end_l->Prev = front_n;
    end_l->data = n++;
  }

 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
  typedef ListIterator<T> iterator;

  list() : front_n(nullptr), rear(nullptr) {}
  list(size_type n) {
    if (n > 0) {
      rear = new Node<T>;
      rear->Next = rear->Prev = nullptr;
      front_n = rear;
      for (int i = 1; i < n; i++) {
        Node<T>* tmp = front_n;
        front_n = new Node<T>;
        front_n->Next = nullptr;
        front_n->Prev = tmp;
        tmp->Next = front_n;
      }
      create_end_node(n);
    }
  }
  list(std::initializer_list<value_type> const& items)
      : front_n(nullptr), rear(nullptr) {
    size_t count = 0;
    for (auto item : items) {
      create_node(item);
      count++;
    }
    create_end_node(count);
  }

  list(const list& l) : front_n(nullptr), rear(nullptr) {
    ListIterator<T> i = l.rear;
    ListIterator<T> end_i = nullptr;
    size_t count = 0;
    for (; i != end_i; i++) {
      create_node(i.getdata());
      count++;
    }
    create_end_node(count);
  }

  list(list&& l) {
    front_n = l.front_n;
    rear = l.rear;
    l.rear = nullptr;
    l.front_n = nullptr;
  }

  ~list() { clear(); }

  list<T>& operator=(list&& l) {
    rear = l.rear;
    front_n = l.front_n;
    l.rear = nullptr;
    l.front_n = nullptr;
    return *this;
  }

  const_reference front() { return front_n->data; }
  const_reference back() { return rear->data; }

  iterator begin() { return ListIterator(rear); }
  iterator end() { return front_n->Next; }

  bool empty() { return (rear == nullptr && front = nullptr); }

  size_type size() {
    size_type i = 0;
    Node<T>* tmp = rear;
    while (tmp != nullptr) {
      i++;
      tmp = tmp->Next;
    }
    return i;
  }

  size_type max_size() { return MAX_SIZE / sizeof(T); }

  void clear() {
    bool loop = true;
    Node<T>* tmp = rear;
    Node<T>* i = tmp;
    while (i != nullptr) {
      i = i->Next;
      delete tmp;
      tmp = i;
    }
    rear = nullptr;
    front_n = nullptr;
  }

  iterator insert(iterator pos, const_reference value) {
    Node<T>* tmp = new Node<T>;
    Node<T>* pos_node = pos.get_point();
    tmp->data = value;
    tmp->Next = pos_node;
    tmp->Prev = pos_node->Prev;
    if (pos_node->Prev != nullptr) {
      pos_node->Prev->Next = tmp;
    } else {
      rear = tmp;
    }
    if (pos_node->Next != nullptr) {
      pos_node->Next->Prev = tmp;
    } else {
      front_n = tmp;
    }
    return tmp;
  }

  void erase(iterator pos) {
    Node<T>* tmp = pos.get_point();
    tmp->Next->Prev = tmp->Prev;
    tmp->Prev->Next = tmp->Next;
    delete tmp;
  }

  void push_back(const_reference value) { insert(end(), value); }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, list<T>& lst) {
  ListIterator<T> tmp = lst.begin();
  ListIterator<T> end_i = lst.end();
  for (tmp = lst.begin(); tmp != end_i; tmp++) {
    os << *tmp << ' ';
  }
  os << std::endl;
  return os;
}
}  // namespace S21