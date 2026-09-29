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
  bool operator>(const ListIterator& other) {
    return point->data > other.point->data;
  }
  ListIterator<T> operator+(int n) {
    for (int i = 0; i < n; i++) {
      point = point->Next;
    }
    return *this;
  }
  T& getdata() { return point->data; }
  Node<T>* get_point() { return point; }
};

template <typename T>
class ListConstIterator {
 private:
  const Node<T>* point;

 public:
  ListConstIterator(Node<T>* nd) : point(nd) {}
  ListConstIterator(ListIterator<T> list_iter) : point(list_iter.get_point()) {}
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
  bool operator>(const ListConstIterator& other) const {
    return point->data > other.point->data;
  }
  ListConstIterator<T> operator+(int n) {
    for (int i = 0; i < n; i++) point++;
    return *this;
  }
  T& getdata() { return point->data; }
  Node<T>* get_point() const { return const_cast<Node<T>*>(point); }
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
    end_l->Next = nullptr;
    front_n->Next = end_l;
    end_l->Prev = front_n;
    end_l->data = n++;
  }

  void delete_node(Node<T>* item) {
    if (item == front_n) {
      front_n = item->Prev;
    }
    if (item == rear) {
      rear = item->Next;
      item->Next->Prev = nullptr;
    } else if (item->Next == nullptr) {
      std::logic_error("delete of end node is not impossible");
    } else {
      item->Next->Prev = item->Prev;
      item->Prev->Next = item->Next;
    }
    delete item;
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
    ListIterator<T> end_i = l.front_n->Next;
    size_t count = 0;
    for (; i != end_i; i++) {
      create_node(i.getdata());
      count++;
    }
    // front_n->Next->data = count;
    //  create_end_node(count);
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
  iterator end() {
    if (front_n == nullptr) return nullptr;
    return front_n->Next;
  }

  bool empty() { return (rear == nullptr && front_n == nullptr); }

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
    pos_node->Prev = tmp;
    if (pos_node->Next == nullptr) {
      pos_node->data++;
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
  void pop_back() { delete_node(front_n); }
  void push_front(const_reference value) { insert(begin(), value); }
  void pop_front() { delete_node(rear); }
  void swap(list& other) {
    Node<T>* tmp = other.front_n;
    other.front_n = front_n;
    front_n = tmp;
    tmp = other.rear;
    other.rear = rear;
    rear = tmp;
  }
  void merge(list& other) {
    S21::list<int> res;
    int end_loop = 0;
    ListIterator<T> tmp = other.begin();
    ListIterator<T> end_iter = end();
    for (ListIterator<T> i = begin(); i != end_iter; i++) {
      while (i > tmp) {
        insert(i, *tmp);
        tmp++;
      }
    }
    end_iter = other.end();
    while (tmp != end_iter) {
      push_back(*tmp);
      tmp++;
    }
  }

  void splice(ListConstIterator<T> pos, list& other) {
    Node<T>* begin_loop = pos.get_point();
    // Node<T>* last_node = begin_loop;
    for (Node<T>* i = other.rear; i != other.front_n->Next; i = i->Next) {
      insert(begin_loop, i->data);
    }
  }

  void swap_node(Node<T>* a, Node<T>* b) {
    T tmp = a->data;
    a->data = b->data;
    b->data = tmp;
  }

  void reverse() {
    if (rear == nullptr) return;
    Node<T>* left = rear;
    Node<T>* right = front_n;
    while (left != right) {
      swap_node(left, right);
      left = left->Next;
      if (left == right) break;
      right = right->Prev;
    }
  }
  void unique() {
    T tmp = rear->data;
    for (Node<T>* i = rear->Next; i != front_n->Next; i = i->Next) {
      if (i->data == tmp) {
        Node<T>* noda_tmp = i->Prev;
        delete_node(i);
        i = noda_tmp;
      } else {
        tmp = i->data;
      }
    }
  }
  void sort(){
    
  }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, list<T>& lst) {
  if (lst.empty()) return os;
  ListIterator<T> tmp = lst.begin();
  ListIterator<T> end_i = lst.end();
  for (tmp = lst.begin(); tmp != end_i; tmp++) {
    os << *tmp << ' ';
  }
  os << std::endl;
  return os;
}
}  // namespace S21