#ifndef VECTOR_H
#define VECTOR_h

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
  void reserve_more_capacity(size_type size);
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

  bool empty() { return m_size ? false : true; }
  size_type size() { return m_size; }
};
}  // namespace s21

#endif