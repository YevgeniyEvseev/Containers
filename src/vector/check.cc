#include <iostream>
#include <vector>

#include "S21_vector.h"

int main() {
  std::vector<int> std_vec{1, 2, 3, 4, 5, 6};
  s21::Vector<int> my_vec{1, 2, 3, 4, 5, 6};
  auto std_it = std_vec.insert(std_vec.begin() + 2, 10);
  auto my_it = my_vec.insert(my_vec.begin() + 2, 10);
  for (auto it : std_vec) std::cout << it << ' ';
  for (auto it : my_vec) std::cout << it << ' ';
  std::cout << std::endl;
  std::cout << my_vec.size() << ' ' << my_vec.at(10);
}