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
  /*
  S21::list<int> lst1({1, 2, 3, 4, 5, 7});
  std::cout << lst1;
  for (auto i : lst1) cout << i << ' ';
  cout << endl;

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
  lst1.insert(lst1.begin(), 0);
  std::cout << "list after insert " << lst1;
  lst1.push_back(6);
  lst1.push_back(11);
  cout << "push back s21" << lst1;
  lst_std.push_back(6);
  cout << "push back std";
  for (auto i : lst_std) std::cout << i << ' ';
  cout << endl;
  lst1.pop_back();
  cout << "pop back s21" << lst1;
  lst1.push_front(-1);
  cout << "push front s21" << lst1;
  lst1.pop_front();
  cout << "pop front s21" << lst1;
  S21::list<int> lst2{11, 12, 13, 14, 15, 16};
  cout << "list1 " << lst1;
  cout << "list2 " << lst2;
  lst1.swap(lst2);
  cout << "after swap\n";
  cout << "list1 " << lst1;
  cout << "list2 " << lst2;
  */

  std::list<int> lst1;
  std::list<int> lst2{23, 2, 2, 8, 3, 56, 23, 9, 0, 2, -3, 78};
  lst1 = lst2;
  lst1.unique();
  for (auto i : lst1) std::cout << i << ' ';
  cout << endl;
  // lst1.sort();
  // for (auto i : lst1) std::cout << i << ' ';
  // cout << endl;
  S21::list<int> lst_s1{119, 10, 11, 11, 12, 13, 14, 15, 16, 17, 18};
  S21::list<int> lst_s2{119, 10, 11, 12, 13, 14, 15, 16, 17, 18};
  // lst_s1 = lst_s2;
  lst_s1.unique();
  lst_s1.reverse();
  for (auto i : lst_s1) cout << i << ' ';
  cout << endl;
}