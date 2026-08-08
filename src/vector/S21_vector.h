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
  reference operator[](size_type index) {
    if (index >= m_size) throw std::out_of_range("Failure\n");
    return at(index);
  }
  T operator[](size_type index) const {
    if (index >= m_size) throw std::out_of_range("Failure\n");
    return arr[index];
  }
  reference at(size_type pos) {
    if (pos >= m_size) {
      throw std::out_of_range("Failure\n");
    }
    return arr[pos];
  }
  const_reference front() { return *arr; }  // access the first element
  const_reference back() { return *(arr + m_size - 1); }
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
  void shrink_to_fit();

  // Vector Modifiers
  void erase(iterator pos);
  iterator insert(iterator pos, const_reference value);
  void push_back(const_reference value);
  void clear();
  void pop_back() { m_size--; }
  void swap(Vector& other);
  // friend std::ostream& operator<<(std::ostream& os, Vector const& v);

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args) {
    if (empty()) {
      Vector tmp{args...};
      *this = (tmp);
      // for(int i=0; i<tmp.m_size; i++) arr=tmp.arr;
      //  m_capacity=tmp.m_capacity;

      return arr;
    }
    value_type tmps[] = {args...};
    size_type count = sizeof(arr) / sizeof(value_type);
    std::cout << "count=" << count << ' ' << tmps[0] << std::endl;

    m_size += count;
    if (m_capacity <= m_size) {
      reserve(m_capacity * 2);
    }
    iterator tmp;
    for (tmp = end(); tmp != pos; --tmp) {
      if (tmp == begin()) break;
      *(tmp) = *(tmp - count);
      std::cout << *this << std::endl;
    }

    for (int i = 0; i < count; i++) *(tmp + i + 2) = tmps[i];
    return tmp + 2;

    return tmp;
  }
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
  arr = new T[v.m_size];
  for (size_t i = 0; i < v.m_size; i++) {
    arr[i] = v.arr[i];
  }
  m_capacity = v.m_capacity;
  m_size = v.m_size;
}
template <typename T>
Vector<T>::Vector(Vector&& v) {
  arr = v.arr;
  m_size = v.m_size;
  m_capacity = v.m_capacity;
  v.arr = nullptr;
  v.m_capacity = 0;
  v.m_size = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& v) {
  if (&v == this) return *this;
  delete[] arr;
  arr = new T[v.m_size];
  for (size_t i = 0; i < v.m_size; i++) {
    arr[i] = v.arr[i];
  }
  m_capacity = v.m_capacity;
  m_size = v.m_size;
  return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& v) {
  arr = v.arr;
  m_size = v.m_size;
  m_capacity = v.m_capacity;
  v.arr = nullptr;
  v.m_capacity = 0;
  v.m_size = 0;
  return *this;
}

template <typename T>
void Vector<T>::reserve_more_capacity() {
  reserve(m_capacity * 2);
}

template <typename T>
void Vector<T>::reserve(size_type size) {
  if (m_capacity <= size) {
    m_capacity = size;
    T* tmp = new T[m_capacity];
    for (size_t i = 0; i < m_size; i++) {
      tmp[i] = arr[i];
    }
    delete[] arr;
    arr = tmp;
  }
}

template <typename T>
void Vector<T>::shrink_to_fit() {
  if (m_capacity > m_size) {
    reserve(m_capacity);
    m_capacity = m_size;
  }
}

template <typename T>
void Vector<T>::clear() {
  free(arr);
  m_capacity = 0;
  m_size = 0;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::insert(iterator pos,
                                               const_reference value) {
  m_size++;
  if (m_capacity <= m_size) {
    reserve(m_capacity * 2);
  }
  iterator tmp;
  for (tmp = end(); tmp != pos; --tmp) {
    if (tmp == begin()) break;
    *(tmp + 1) = *(tmp);
  }
  *(tmp + 2) = value;
  return tmp + 2;
}

template <typename T>
void Vector<T>::erase(iterator pos) {
  iterator tmp = pos;
  while (tmp != end()) {
    *tmp = *(tmp + 1);
    tmp++;
  }
  m_size--;
}

template <typename T>
void Vector<T>::push_back(const_reference value) {
  if (m_size >= m_capacity) {
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

template <typename T>
void Vector<T>::swap(Vector& other) {
  Vector tmp = other;
  other = *this;
  *this = tmp;
}

}  // namespace s21

#endif