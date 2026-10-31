#include <gtest/gtest.h>

#include <iostream>
#include <list>
#include <string>

#include "S21_list.h"

TEST(ListTest, DefaultConstructor) {
  S21::list<int> lst;
  EXPECT_EQ(lst.size(), 0);
  EXPECT_TRUE(lst.empty());
}

TEST(ListTest, SizeConstructor) {
  S21::list<int> lst(5);
  EXPECT_EQ(lst.size(), 5);
  EXPECT_FALSE(lst.empty());
}

TEST(ListTest, InitList) {
  std::list<int> std_lst{1, 2, 3, 4, 5, 6, 7, 8};
  S21::list<int> my_lst{1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(my_lst.size(), std_lst.size());
  EXPECT_FALSE(my_lst.empty());
  auto std_it = std_lst.begin();
  auto my_it = my_lst.begin();
  while (std_it != std_lst.end() && my_it != my_lst.end()) {
    EXPECT_EQ(*std_it, *my_it);
    ++std_it;
    ++my_it;
  }
  EXPECT_EQ(std_it, std_lst.end());
  EXPECT_EQ(my_it, my_lst.end());
}

TEST(ListTest, CopyList) {
  S21::list<int> std_lst{1, 2, 3, 4, 5, 6, 7, 8};
  S21::list<int> my_lst(std_lst);
  EXPECT_EQ(my_lst.size(), 8);
  EXPECT_FALSE(my_lst.empty());
  auto std_it = std_lst.begin();
  auto my_it = my_lst.begin();
  while (std_it != std_lst.end() && my_it != my_lst.end()) {
    EXPECT_EQ(*std_it, *my_it);
    std_it++;
    my_it++;
  }
  EXPECT_EQ(std_it, std_lst.end());
  EXPECT_EQ(my_it, my_lst.end());
}

TEST(ListTest, MoveList) {
  S21::list<int> original{1, 2, 3, 4, 5, 6, 7, 8};
  S21::list<int> moved = std::move(original);
  EXPECT_EQ(moved.size(), 8);
  EXPECT_FALSE(moved.empty());
  EXPECT_EQ(original.size(), 0);
}

TEST(ListTest, SortList) {
  std::list<int> std_lst{9, 4, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  S21::list<int> my_lst{9, 4, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  my_lst.sort();
  std_lst.sort();

  auto std_it = std_lst.begin();
  auto my_it = my_lst.begin();
  while (std_it != std_lst.end() && my_it != my_lst.end()) {
    EXPECT_EQ(*std_it, *my_it);
    ++std_it;
    ++my_it;
  }
  EXPECT_EQ(std_it, std_lst.end());
  EXPECT_EQ(my_it, my_lst.end());
}

TEST(ListTest, SpliceList) {
  std::list<int> std_lst{9, 4, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  std::list<int> std_lst2{1, 2, 3, 4, 5, 6, 7};
  S21::list<int> my_lst{9, 4, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  S21::list<int> my_lst2{1, 2, 3, 4, 5, 6, 7};

  auto std_it = std_lst.begin();
  auto my_it = my_lst.begin();
  std_it++;
  std_it++;
  my_it++;
  my_it++;

  S21::ListConstIterator<int> pos(my_it);  // создаем const_iterator

  std_lst.splice(std_it, std_lst2);
  my_lst.splice(pos, my_lst2);

  // УБЕРИ ПОВТОРНОЕ ОБЪЯВЛЕНИЕ:
  auto std_it2 = std_lst.begin();  // переименовал
  auto my_it2 = my_lst.begin();    // переименовал

  while (std_it2 != std_lst.end() && my_it2 != my_lst.end()) {
    EXPECT_EQ(*std_it2, *my_it2);
    ++std_it2;
    ++my_it2;
  }
  EXPECT_EQ(std_it2, std_lst.end());
  EXPECT_EQ(my_it2, my_lst.end());
}

TEST(ListTest, UniqueList) {
  std::list<int> std_lst{9, 4, 4, 4, 1, 1, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  S21::list<int> my_lst{9, 4, 4, 4, 1, 1, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  std_lst.unique();
  my_lst.unique();
  auto std_it = std_lst.begin();
  auto my_it = my_lst.begin();
  while (std_it != std_lst.end() && my_it != my_lst.end()) {
    EXPECT_EQ(*std_it, *my_it);
    ++std_it;
    ++my_it;
  }
  EXPECT_EQ(std_it, std_lst.end());
  EXPECT_EQ(my_it, my_lst.end());
}

TEST(ListTest, ReverseList) {
  std::list<int> std_lst{9, 4, 4, 4, 1, 1, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  S21::list<int> my_lst{9, 4, 4, 4, 1, 1, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  std_lst.reverse();
  my_lst.reverse();
  auto std_it = std_lst.begin();
  auto my_it = my_lst.begin();
  while (std_it != std_lst.end() && my_it != my_lst.end()) {
    EXPECT_EQ(*std_it, *my_it);
    ++std_it;
    ++my_it;
  }
  EXPECT_EQ(std_it, std_lst.end());
  EXPECT_EQ(my_it, my_lst.end());
}

TEST(ListTest, EraseList) {
  std::list<int> std_lst{9, 4, 4, 4, 1, 1, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  S21::list<int> my_lst{9, 4, 4, 4, 1, 1, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  auto std_er_it = std_lst.begin();
  auto my_er_it = my_lst.begin();
  std_er_it++;
  std_er_it++;
  std_er_it++;
  my_er_it++;
  my_er_it++;
  my_er_it++;
  std_lst.erase(std_er_it);
  my_lst.erase(my_er_it);
  auto std_it = std_lst.begin();
  auto my_it = my_lst.begin();
  while (std_it != std_lst.end() && my_it != my_lst.end()) {
    EXPECT_EQ(*std_it, *my_it);
    ++std_it;
    ++my_it;
  }
  EXPECT_EQ(std_it, std_lst.end());
  EXPECT_EQ(my_it, my_lst.end());
}

TEST(ListTest, EraseList2) {
  std::list<int> std_lst{9, 4, 4, 4, 1, 1, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  S21::list<int> my_lst{9, 4, 4, 4, 1, 1, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  auto std_er_it = std_lst.begin();
  auto my_er_it = my_lst.begin();
  std_lst.erase(std_er_it);
  my_lst.erase(my_er_it);
  auto std_it = std_lst.begin();
  auto my_it = my_lst.begin();
  while (std_it != std_lst.end() && my_it != my_lst.end()) {
    EXPECT_EQ(*std_it, *my_it);
    ++std_it;
    ++my_it;
  }
  EXPECT_EQ(std_it, std_lst.end());
  EXPECT_EQ(my_it, my_lst.end());
}

TEST(ListTest, EraseList3) {
  std::list<int> std_lst{9, 4};
  S21::list<int> my_lst{9, 4};
  auto std_er_it = std_lst.begin();
  auto my_er_it = my_lst.begin();
  std_er_it++;
  my_er_it++;
  std_lst.erase(std_er_it);
  my_lst.erase(my_er_it);
  auto std_it = std_lst.begin();
  auto my_it = my_lst.begin();
  while (std_it != std_lst.end() && my_it != my_lst.end()) {
    EXPECT_EQ(*std_it, *my_it);
    ++std_it;
    ++my_it;
  }
  EXPECT_EQ(std_it, std_lst.end());
  EXPECT_EQ(my_it, my_lst.end());
  
}

TEST(ListTest, InsertList) {
  std::list<int> std_lst{9, 4};
  S21::list<int> my_lst{9, 4};
  auto std_ins_it = std_lst.begin();
  auto my_ins_it = my_lst.begin();
  std_ins_it++;
  my_ins_it++;
  std_lst.insert(std_ins_it, 8);
  my_lst.insert(my_ins_it, 8);
  auto std_it = std_lst.begin();
  auto my_it = my_lst.begin();
  while (std_it != std_lst.end() && my_it != my_lst.end()) {
    EXPECT_EQ(*std_it, *my_it);
    ++std_it;
    ++my_it;
  }
  EXPECT_EQ(std_it, std_lst.end());
  EXPECT_EQ(my_it, my_lst.end());
}

TEST(ListTest, PopbackList) {
  std::list<int> std_lst{9, 4, 4, 4, 1, 1, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  S21::list<int> my_lst{9, 4, 4, 4, 1, 1, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  std_lst.pop_back();
  my_lst.pop_back();
  auto std_it = std_lst.begin();
  auto my_it = my_lst.begin();
  while (std_it != std_lst.end() && my_it != my_lst.end()) {
    EXPECT_EQ(*std_it, *my_it);
    ++std_it;
    ++my_it;
  }
  EXPECT_EQ(std_it, std_lst.end());
  EXPECT_EQ(my_it, my_lst.end());
}

TEST(ListTest, PopfrontList) {
  std::list<int> std_lst{9, 4, 4, 4, 1, 1, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  S21::list<int> my_lst{9, 4, 4, 4, 1, 1, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  std_lst.pop_front();
  my_lst.pop_front();
  auto std_it = std_lst.begin();
  auto my_it = my_lst.begin();
  while (std_it != std_lst.end() && my_it != my_lst.end()) {
    EXPECT_EQ(*std_it, *my_it);
    ++std_it;
    ++my_it;
  }
  EXPECT_EQ(std_it, std_lst.end());
  EXPECT_EQ(my_it, my_lst.end());
}

TEST(ListTest, PushfrontList) {
  std::list<int> std_lst{9, 4, 4, 4, 1, 1, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  S21::list<int> my_lst{9, 4, 4, 4, 1, 1, 2, 1, 6, 2, 5, 5, 2, 1, 1, 9, 0};
  std_lst.push_front(1);
  my_lst.push_front(1);
  auto std_it = std_lst.begin();
  auto my_it = my_lst.begin();
  while (std_it != std_lst.end() && my_it != my_lst.end()) {
    EXPECT_EQ(*std_it, *my_it);
    ++std_it;
    ++my_it;
  }
  EXPECT_EQ(std_it, std_lst.end());
  EXPECT_EQ(my_it, my_lst.end());
}
/*
TEST(S21ListInsertManyTest, InsertMany1) {
  S21::list<int> my_list = {1, 2, 3, 4, 5};
  auto pos = my_list.begin();
  ++pos;
  auto it = my_list.insert_many(pos, 10, 20, 30);

  S21::list<int> expected = {1, 10, 20, 30, 2, 3, 4, 5};
  EXPECT_EQ(my_list.size(), expected.size());

  auto it1 = my_list.begin();
  auto it2 = expected.begin();
  while (it1 != my_list.end() && it2 != expected.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
  EXPECT_EQ(*it, 10);
}

TEST(S21ListInsertManyTest, InsertMany2) {
  S21::list<int> my_list = {4, 5, 6};
  auto it = my_list.insert_many(my_list.begin(), 1, 2, 3);

  S21::list<int> expected = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(my_list.size(), expected.size());

  auto it1 = my_list.begin();
  auto it2 = expected.begin();
  while (it1 != my_list.end() && it2 != expected.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
  EXPECT_EQ(*it, 1);
}

TEST(S21ListInsertManyTest, InsertMany3) {
  S21::list<int> my_list = {1, 2, 3};
  auto it = my_list.insert_many(my_list.end(), 4, 5, 6);

  S21::list<int> expected = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(my_list.size(), expected.size());

  auto it1 = my_list.begin();
  auto it2 = expected.begin();
  while (it1 != my_list.end() && it2 != expected.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
  EXPECT_EQ(*it, 4);
}

TEST(S21ListInsertManyBackTest, InsertMany4) {
  S21::list<int> my_list;
  my_list.insert_many_back(1, 2, 3);

  S21::list<int> expected = {1, 2, 3};
  EXPECT_EQ(my_list.size(), expected.size());

  auto it1 = my_list.begin();
  auto it2 = expected.begin();
  while (it1 != my_list.end() && it2 != expected.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(S21ListInsertManyBackTest, InsertMany5) {
  S21::list<int> my_list = {1, 2, 3};
  my_list.insert_many_back(4, 5, 6);

  S21::list<int> expected = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(my_list.size(), expected.size());

  auto it1 = my_list.begin();
  auto it2 = expected.begin();
  while (it1 != my_list.end() && it2 != expected.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(S21ListInsertManyBackTest, InsertMany6) {
  S21::list<int> my_list = {1, 2};
  my_list.insert_many_back(3);

  S21::list<int> expected = {1, 2, 3};
  EXPECT_EQ(my_list.size(), expected.size());

  auto it1 = my_list.begin();
  auto it2 = expected.begin();
  while (it1 != my_list.end() && it2 != expected.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(S21ListInsertManyFrontTest, InsertMany7) {
  S21::list<int> my_list;
  my_list.insert_many_front(3, 2, 1);

  S21::list<int> expected = {3, 2, 1};
  EXPECT_EQ(my_list.size(), expected.size());

  auto it1 = my_list.begin();
  auto it2 = expected.begin();
  while (it1 != my_list.end() && it2 != expected.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(S21ListInsertManyFrontTest, InsertMany8) {
  S21::list<int> my_list = {4, 5, 6};
  my_list.insert_many_front(1, 2, 3);

  S21::list<int> expected = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(my_list.size(), expected.size());

  auto it1 = my_list.begin();
  auto it2 = expected.begin();
  while (it1 != my_list.end() && it2 != expected.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(S21ListInsertManyFrontTest, InsertMany9) {
  S21::list<int> my_list = {2, 3};
  my_list.insert_many_front(1);

  S21::list<int> expected = {1, 2, 3};
  EXPECT_EQ(my_list.size(), expected.size());

  auto it1 = my_list.begin();
  auto it2 = expected.begin();
  while (it1 != my_list.end() && it2 != expected.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}
  */

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}