#include <iostream>
#include <list>

#include "S21_list.h"

void func1(S21::list<int> t) {
  S21::list<int> copy_lst = t;
  std::cout << "copy constr s21 " << copy_lst;
  std::cout << std::endl;
}

int main() {
  using std::cout;
  using std::endl;
  S21::list<int> my_lst{9, 4};
  auto it = my_lst.begin();
  it++;
  my_lst.erase(it);
  for (auto i : my_lst) cout << i << ' ';
  cout << endl;
}
