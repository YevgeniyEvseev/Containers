namespace S21 {

template <typename T>
class Node {
 private:
  T data;
  Node* Next;
  Node* Prev;
};

template <typename T>
class iterator : public Node {

};

template <typename T>
class S21_queue {
 private:
  /* data */
 public:
  S21_queue(/* args */);
  ~S21_queue();
};

S21_queue::S21_queue(/* args */) {}

S21_queue::~S21_queue() {}

}  // namespace S21