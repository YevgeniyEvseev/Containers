#include <iostream>

#include "S21_list.h"

int main() {
  S21::list<int> lst1({1, 2, 3, 4, 11, 45, 33, 45, 2, -9});
  std::cout << lst1;
  S21::list<int> copy_lst(lst1);
  std::cout << copy_lst;
  lst1.sort();
  std::cout << lst1;
  lst1.unique();
  std::cout << lst1;
}