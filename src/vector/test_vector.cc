#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "S21_vector.h"

class Test {
 private:
  std::string name;
  unsigned age;
  int value;

 public:
  Test() : name("noname"), age(0), value(0) {}
  explicit Test(char* n) : name(n), age(0), value(0) {}
  Test(char* n, int a, int v) : name(n), age(a), value(v) {}
  std::string& get_name() { return name; }
  int get_age() { return age; }
  int get_value() { return value; }
  void set_name(char* n) { name = n; }
  void set_age(int a) { age = a; }
  void set_value(int v) { value = v; }
};

TEST(vector_test, default_constructor) {
  s21::Vector<int> v;
  EXPECT_EQ(v.size(), 0);
  EXPECT_TRUE(v.empty());
}

TEST(vector_test, inicilazer_list_constr) {
  s21::Vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> v_std{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(v.size(), 10);
  EXPECT_EQ(v[2], 3);
}

TEST(vectro_test, max_size) {
  s21::Vector<double> v;
  std::vector<double> v_std;
  EXPECT_EQ(v.max_size(), v_std.max_size());
}

TEST(vectro_test, max_size2) {
  s21::Vector<int> v;
  std::vector<int> v_std;
  EXPECT_EQ(v.max_size(), v_std.max_size());
}

TEST(vectro_test, max_size3) {
  s21::Vector<Test> v;
  std::vector<Test> v_std;
  EXPECT_EQ(v.max_size(), v_std.max_size());
}

TEST(vectro_test, erase) {
  s21::Vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  v.erase(&v.at(5));
  EXPECT_EQ(v[5], 7);
  EXPECT_EQ(v[6], 8);
}

TEST(vectro_test, erase1) {
  s21::Vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  v.erase(&v.at(9));
  EXPECT_EQ(v[8], 9);
  EXPECT_EQ(v.size(), 9);
}

TEST(vectro_test, erase2) {
  s21::Vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  v.erase(&v.at(0));
  EXPECT_EQ(v[0], 2);
  EXPECT_EQ(v[8], 10);
}

TEST(vectro_test, end) {
  s21::Vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> v_std{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(*(v.end() - 1), *(v_std.end() - 1));
}

TEST(VectorTest, SizeConstructor) {
  s21::Vector<int> vec(5);
  EXPECT_EQ(vec.size(), 5);
  EXPECT_EQ(vec.capacity(), 5);
  EXPECT_FALSE(vec.empty());
}

TEST(VectorTest, InitListConstructor) {
  s21::Vector<int> vec({1, 2, 3, 4, 5});
  EXPECT_EQ(vec.size(), 5);
  EXPECT_EQ(vec.back(), 5);
  EXPECT_FALSE(vec.empty());
}

TEST(VectorTest, CopyConstructor) {
  s21::Vector<int> vec1({1, 2, 3, 4, 5});
  s21::Vector<int> vec2(vec1);
  EXPECT_EQ(vec1.size(), vec2.size());
  for (size_t i = 0; i < vec1.size(); ++i) {
    EXPECT_EQ(vec1[i], vec2[i]);
  }
}

TEST(VectorTest, MoveConstructor) {
  s21::Vector<int> vec1 = {1, 2, 3};
  s21::Vector<int> vec2 = std::move(vec1);

  EXPECT_EQ(vec1.size(), 0);
  EXPECT_EQ(vec1.capacity(), 0);
  EXPECT_EQ(vec2.size(), 3);
  EXPECT_EQ(vec2[0], 1);
  EXPECT_EQ(vec2[1], 2);
  EXPECT_EQ(vec2[2], 3);
}

TEST(VectorTest, OperatorMove) {
  s21::Vector<int> vec1 = {1, 2, 3};
  s21::Vector<int> vec2 = vec1;

  EXPECT_EQ(vec2.size(), 3);
  EXPECT_EQ(vec2.capacity(), 3);
  EXPECT_EQ(vec2[0], 1);
  EXPECT_EQ(vec2[1], 2);
  EXPECT_EQ(vec2[2], 3);
}

TEST(VectorTest, OperatorIndx) {
  s21::Vector<int> vec = {1, 2, 3};
  EXPECT_EQ(vec[2], 3);
}

TEST(VectorTest, PushBack) {
  s21::Vector<int> vec;
  vec.push_back(42);
  EXPECT_EQ(vec.size(), 1);
  EXPECT_EQ(vec[0], 42);
}

TEST(VectorTest, Shrink_to_fit) {
  s21::Vector<int> vec{1, 2, 3, 4, 5, 6};
  vec.push_back(7);
  vec.shrink_to_fit();
  EXPECT_EQ(vec.size(), 7);
  EXPECT_EQ(vec.size(), vec.capacity());
}

TEST(VectorTest, Insert) {
  std::vector<int> std_vec{1, 2, 3, 4, 5, 6};
  s21::Vector<int> my_vec{1, 2, 3, 4, 5, 6};
  auto std_it = std_vec.insert(std_vec.begin() + 2, 10);
  auto my_it = my_vec.insert(my_vec.begin() + 2, 10);
  EXPECT_EQ(*std_it, *my_it);
  EXPECT_EQ(std_vec.size(), my_vec.size());
  EXPECT_EQ(std_vec.size(), my_vec.size());
  for (size_t i = 0; i < my_vec.size(); ++i) {
    EXPECT_EQ(std_vec[i], my_vec[i]);
  }
}

TEST(VectorTest, Erase) {
  std::vector<int> std_vec{1, 2, 3, 4, 5, 6};
  s21::Vector<int> my_vec{1, 2, 3, 4, 5, 6};
  std_vec.erase(std_vec.begin() + 2);
  my_vec.erase(my_vec.begin() + 2);
  EXPECT_EQ(std_vec.size(), my_vec.size());
  EXPECT_EQ(std_vec.size(), my_vec.size());
  for (size_t i = 0; i < my_vec.size(); ++i) {
    EXPECT_EQ(std_vec[i], my_vec[i]);
  }
}

TEST(VectorTest, PopBack) {
  std::vector<int> std_vec{1, 2, 3, 4, 5};
  s21::Vector<int> my_vec{1, 2, 3, 4, 5};

  std_vec.pop_back();
  my_vec.pop_back();

  EXPECT_EQ(std_vec.size(), my_vec.size());
  for (size_t i = 0; i < my_vec.size(); ++i) {
    EXPECT_EQ(std_vec[i], my_vec[i]);
  }
}

TEST(VectorTest, Clear) {
  std::vector<int> std_vec{1, 2, 3, 4, 5};
  s21::Vector<int> my_vec{1, 2, 3, 4, 5};

  std_vec.clear();
  my_vec.clear();

  EXPECT_EQ(std_vec.size(), my_vec.size());
  EXPECT_EQ(std_vec.empty(), my_vec.empty());
}

TEST(VectorTest, Swap) {
  std::vector<int> std_vec1{1, 2, 3};
  std::vector<int> std_vec2{4, 5, 6};
  s21::Vector<int> my_vec1{1, 2, 3};
  s21::Vector<int> my_vec2{4, 5, 6};

  std_vec1.swap(std_vec2);
  my_vec1.swap(my_vec2);

  EXPECT_EQ(std_vec1.size(), my_vec1.size());
  EXPECT_EQ(std_vec2.size(), my_vec2.size());
  for (size_t i = 0; i < my_vec1.size(); ++i) {
    EXPECT_EQ(std_vec1[i], my_vec1[i]);
  }
  for (size_t i = 0; i < my_vec2.size(); ++i) {
    EXPECT_EQ(std_vec2[i], my_vec2[i]);
  }
}

TEST(VectorTest, FrontBack) {
  std::vector<int> std_vec{1, 2, 3};
  s21::Vector<int> my_vec{1, 2, 3};

  EXPECT_EQ(std_vec.front(), my_vec.front());
  EXPECT_EQ(std_vec.back(), my_vec.back());
}

TEST(VectorTest, ShrinkToFit) {
  std::vector<int> std_vec{1, 2, 3, 4, 5, 6};
  s21::Vector<int> my_vec{1, 2, 3, 4, 5, 6};

  std_vec.shrink_to_fit();
  my_vec.shrink_to_fit();

  EXPECT_EQ(std_vec.size(), my_vec.size());
  EXPECT_EQ(std_vec.capacity(), my_vec.capacity());
  for (size_t i = 0; i < my_vec.size(); ++i) {
    EXPECT_EQ(std_vec[i], my_vec[i]);
  }
}

TEST(VectorTest, Data) {
  std::vector<int> std_vec{1, 2, 3};
  s21::Vector<int> my_vec{1, 2, 3};

  int* std_ptr = std_vec.data();
  int* my_ptr = my_vec.data();

  for (size_t i = 0; i < my_vec.size(); ++i) {
    EXPECT_EQ(std_ptr[i], my_ptr[i]);
  }
}

TEST(VectorTest, Empty) {
  std::vector<int> std_vec;
  s21::Vector<int> my_vec;

  EXPECT_EQ(std_vec.empty(), my_vec.empty());

  std_vec.push_back(1);
  my_vec.push_back(1);

  EXPECT_EQ(std_vec.empty(), my_vec.empty());
}

TEST(VectorTest, AtOutOfRange) {
  std::vector<int> std_vec{1, 2, 3};
  s21::Vector<int> my_vec{1, 2, 3};

  EXPECT_THROW(std_vec.at(10), std::out_of_range);
  EXPECT_THROW(my_vec.at(10), std::out_of_range);
}

TEST(VectorTest, AtOk) {
  std::vector<int> std_vec{1, 2, 3};
  s21::Vector<int> my_vec{1, 2, 3};
  EXPECT_EQ(std_vec.at(2), my_vec.at(2));
}

TEST(VectorTest, MaxSize) {
  s21::Vector<int> my_vec;
  EXPECT_GT(my_vec.max_size(), 0);
}

TEST(VectorTest, Operator) {
  s21::Vector<int> my_vec{1, 4};
  s21::Vector<int> new_vec;
  new_vec = my_vec;
  EXPECT_EQ(my_vec.front(), new_vec.front());
  EXPECT_EQ(my_vec.back(), new_vec.back());
}

TEST(VectorTest, MoveAssignmentOperator) {
  s21::Vector<int> source{1, 2, 3, 4, 5};
  s21::Vector<int> target;

  target = std::move(source);
  EXPECT_EQ(target.size(), 5);
  EXPECT_EQ(target[0], 1);
  EXPECT_EQ(target[4], 5);
  EXPECT_EQ(source.size(), 0);
}

TEST(VectorInsertManyTest, BasicInsertMany1) {
  s21::Vector<int> vec = {1, 2, 5};

  auto it = vec.insert_many(vec.begin() + 2, 3, 4);

  EXPECT_EQ(vec.size(), 5);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(vec[4], 5);
  EXPECT_EQ(*it, 3);
}

TEST(VectorInsertManyTest, InsertMany2) {
  s21::Vector<int> vec = {4, 5, 6};

  auto it = vec.insert_many(vec.begin(), 1, 2, 3);

  EXPECT_EQ(vec.size(), 6);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(vec[4], 5);
  EXPECT_EQ(vec[5], 6);
  EXPECT_EQ(*it, 1);
}

TEST(VectorInsertManyTest, InsertMany3) {
  s21::Vector<int> vec = {1, 2, 3};

  auto it = vec.insert_many(vec.end(), 4, 5, 6);

  EXPECT_EQ(vec.size(), 6);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(vec[4], 5);
  EXPECT_EQ(vec[5], 6);
  EXPECT_EQ(*it, 4);
}

TEST(VectorInsertManyTest, InsertMany4) {
  s21::Vector<int> vec = {1, 2, 6, 7};

  auto it = vec.insert_many(vec.begin() + 2, 3, 4, 5);

  EXPECT_EQ(vec.size(), 7);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(vec[4], 5);
  EXPECT_EQ(vec[5], 6);
  EXPECT_EQ(vec[6], 7);
  EXPECT_EQ(*it, 3);
}

TEST(VectorInsertManyTest, InsertMany5) {
  s21::Vector<int> vec = {1, 3, 4};

  auto it = vec.insert_many(vec.begin() + 1, 2);

  EXPECT_EQ(vec.size(), 4);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(*it, 2);
}

TEST(VectorInsertManyTest, InsertMany6) {
  s21::Vector<int> vec;

  auto it = vec.insert_many(vec.begin(), 1, 2, 3);

  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(*it, 1);
}

TEST(VectorInsertManyTest, InsertMany7) {
  s21::Vector<int> vec = {1, 2, 3};

  auto it = vec.insert_many(vec.begin() + 1);

  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(*it, 2);
}

TEST(VectorInsertManyTest, InsertMany8) {
  s21::Vector<std::string> vec = {"hello", "world"};

  auto it = vec.insert_many(vec.begin() + 1, "beautiful", "test");

  EXPECT_EQ(vec.size(), 4);
  EXPECT_EQ(vec[0], "hello");
  EXPECT_EQ(vec[1], "beautiful");
  EXPECT_EQ(vec[2], "test");
  EXPECT_EQ(vec[3], "world");
  EXPECT_EQ(*it, "beautiful");
}

TEST(VectorInsertManyTest, InsertMany9) {
  s21::Vector<int> vec = {1, 4, 5};
  auto it = vec.insert_many(vec.begin() + 1, 2, 3);
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 4);
}

TEST(VectorInsertManyTest, InsertMany10) {
  s21::Vector<int> vec = {1, 100};

  auto it = vec.insert_many(vec.begin() + 1, 2, 3, 4, 5, 6, 7, 8, 9);

  EXPECT_EQ(vec.size(), 10);
  EXPECT_EQ(vec[0], 1);
  for (int i = 2; i <= 9; ++i) {
    EXPECT_EQ(vec[i - 1], i);
  }
  EXPECT_EQ(vec[9], 100);
  EXPECT_EQ(*it, 2);
}

TEST(VectorInsertManyTest, InsertMany11) {
  s21::Vector<int> vec = {1, 5};

  vec.insert_many(vec.begin() + 1, 2, 3, 4);

  EXPECT_EQ(vec.size(), 5);
  for (int i = 1; i <= 5; ++i) {
    EXPECT_EQ(vec[i - 1], i);
  }
}

TEST(VectorInsertManyTest, InsertMany12) {
  s21::Vector<int> vec;
  vec = {1, 2, 3};
  vec.insert_many(vec.begin() + 1, 10, 20, 30, 40);

  EXPECT_EQ(vec.size(), 7);
  EXPECT_GE(vec.capacity(), 7);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 10);
  EXPECT_EQ(vec[2], 20);
  EXPECT_EQ(vec[3], 30);
  EXPECT_EQ(vec[4], 40);
  EXPECT_EQ(vec[5], 2);
  EXPECT_EQ(vec[6], 3);
}

TEST(VectorInsertManyTest, InsertMany13) {
  s21::Vector<int> vec;
  vec.insert_many(vec.begin(), 10, 20, 30, 40);

  EXPECT_EQ(vec.size(), 4);
  EXPECT_GE(vec.capacity(), 4);
  EXPECT_EQ(vec[0], 10);
  EXPECT_EQ(vec[1], 20);
  EXPECT_EQ(vec[2], 30);
  EXPECT_EQ(vec[3], 40);
}

TEST(VectorInsertManyBackTest, InsertManyBack1) {
  s21::Vector<int> vec;
  vec = {1, 2, 3};
  vec.insert_many_back(10, 20, 30, 40);

  EXPECT_EQ(vec.size(), 7);
  EXPECT_GE(vec.capacity(), 7);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 10);
  EXPECT_EQ(vec[4], 20);
  EXPECT_EQ(vec[5], 30);
  EXPECT_EQ(vec[6], 40);
}

TEST(VectorInsertManyBackTest, InsertManyBack2) {
  s21::Vector<int> vec;
  vec.insert_many_back(10, 20, 30, 40);

  EXPECT_EQ(vec.size(), 4);
  EXPECT_GE(vec.capacity(), 4);
  EXPECT_EQ(vec[0], 10);
  EXPECT_EQ(vec[1], 20);
  EXPECT_EQ(vec[2], 30);
  EXPECT_EQ(vec[3], 40);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}