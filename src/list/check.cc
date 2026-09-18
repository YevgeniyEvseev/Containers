#include <iostream>
#include <list>

#include "S21_list.h"

void func1(S21::list<int> t) {
  S21::list<int> copy_lst = t;
  std::cout << copy_lst;
}

int main() {
  using std::cout;
  using std::endl;
  S21::list<int> lst1({1, 2, 3, 4, 5});
  std::cout << lst1;
  for (auto i : lst1) cout << i;

  func1(lst1);
  std::cout << lst1;
  std::cout << "front" << lst1.front() << endl;
  std::list<int> lst_std({1, 2, 3, 4, 5});
  lst_std.insert(lst_std.end(), 4);
  for (auto i : lst_std) std::cout << i << ' ';
  cout << "end list std " << *(lst_std.end()) << endl;
  S21::ListIterator<int> pos_s = lst1.begin();
  cout << "pos_s " << *pos_s;
  lst1.insert(lst1.end(), 4);
  std::cout << "list after insert " << lst1;
  lst1.push_back(6);
  cout << "push back s21" << lst1;
  lst_std.push_back(6);
  cout << "push back std";
  for (auto i : lst_std) std::cout << i << ' ';
  cout << endl;
}