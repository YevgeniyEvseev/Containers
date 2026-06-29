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

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}