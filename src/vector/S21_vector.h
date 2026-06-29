#ifndef VECTOR_H
#define VECTOR_h

#define MAX_SIZE 9223372036854775807

#include <initializer_list>
#include <iostream>
#include <utility>

namespace s21 {
template <typename T>
class Vector {
 private:
  T* arr;
  size_t m_size;
  size_t m_capacity;

 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

 private:
  void reserve_more_capacity();
  // public methods
 public:
  // default constructor (simplified syntax for assigning values to attributes)
  Vector() : m_size(0U), m_capacity(0U), arr(nullptr) {}
  // parametrized constructor for fixed size vector (explicit was used in order
  // to avoid automatic type conversion)
  explicit Vector(size_type n)
      : m_size(n), m_capacity(n), arr(n ? new T[n] : nullptr) {}
  // initializer list constructor (allows creating lists with initializer lists,
  // see main.cpp)

  Vector(std::initializer_list<value_type> const& items);
  Vector(const Vector& v);
  Vector(Vector&& v);
  Vector& operator=(Vector&& v);
  Vector& operator=(const Vector& v);
  // Element access
  reference operator[](size_type index) { return at(index); }
  T operator[](size_type index) const { return arr[index]; }
  reference at(size_type pos) { return arr[pos]; }
  const_reference front() { return *arr; }  // access the first element
  const_reference back() { return *(arr + m_size); }
  T* data() { return arr; }

  // Vector Iterators
  iterator begin() { return arr; }  // returns an iterator to the beginning
  iterator end() { return arr + m_size; }

  // Capacity

  bool empty() { return m_size ? false : true; }
  size_type size() { return m_size; }
  size_type max_size() { return MAX_SIZE / sizeof(T); }
  void reserve(size_type size);
  size_type capacity() { return m_capacity; }

  void push_back(const_reference value);
  // friend std::ostream& operator<<(std::ostream& os, Vector const& v);
};

template <typename T>
Vector<T>::Vector(std::initializer_list<value_type> const& items)
    : m_size(0), m_capacity(items.size()), arr(new T[items.size()]) {
  for (const auto item : items) {
    push_back(item);
  }
}

template <typename T>
Vector<T>::Vector(const Vector& v) {
  arr = new T[v.size()];
  for (size_t i = 0; i < v.size(); i++) {
    arr[i] = v.arr[i];
  }
  m_capacity = v.m_capacity;
  m_size = v.m_size;
}
template <typename T>
Vector<T>::Vector(Vector&& v) {
  this = v;
  v = nullptr;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& v) {
  if (*v == this) return *this;
  delete[] arr;
  arr = new T[v.size()];
  for (size_t i = 0; i < v.m_size(); i++) {
    arr[i] = v.arr[i];
  }
  m_capacity = v.m_capacity;
  m_size = v.m_size;
  return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& v) {
  this = v;
  v = nullptr;
  return *this;
}

template <typename T>
void Vector<T>::reserve_more_capacity() {
  reserve(m_capacity * 2);
}

template <typename T>
void Vector<T>::reserve(size_type size) {
  if (m_capacity < size) {
    m_capacity = size;
    T* tmp = arr;
    delete[] arr;
    arr = tmp;
  }
}

template <typename T>
void Vector<T>::push_back(const_reference value) {
  if (m_size > m_capacity) {
    reserve_more_capacity();
  }
  arr[m_size++] = value;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Vector<T>& v) {
  for (int i = 0; i < v.size(); i++) {
    os << v[i] << ' ';
  }
  return os;
}

}  // namespace s21

#endif