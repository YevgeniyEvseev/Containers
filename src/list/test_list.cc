#include <iostream>

#include "S21_list.h"

int main() {
  S21::list<int> lst1({1, 2, 3, 4});
  std::cout << lst1;
  S21::list<int> copy_lst(lst1);
  std::cout << copy_lst;
}