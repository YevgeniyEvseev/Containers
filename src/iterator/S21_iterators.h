namespace S21 {
template <typename T>
class Iterator {
 public:
  T* operator++() { return ++T; }
  T& operator*() { return *T; }
 private:
  T* data;
};
}  // namespace S21