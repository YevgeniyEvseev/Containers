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
  S21::list<int> my_list;
  my_list.insert_many_back(1, 2, 3);

  S21::list<int> expected = {1, 2, 3};
  // my_list.size(); expected.size();

  auto it1 = my_list.begin();
  auto it2 = expected.begin();
  while (it1 != my_list.end() && it2 != expected.end()) {
    //  EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
  // for (auto i : my_lst) cout << i << ' ';
  // cout << endl;
}
