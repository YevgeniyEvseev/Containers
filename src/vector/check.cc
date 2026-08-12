#include <iostream>
#include <vector>

#include "S21_vector.h"

int main() {
  s21::Vector<int> vec = {1, 3, 4};

  auto it = vec.insert_many(vec.begin() + 1, 2);

  std::cout << vec;
}