#include <gtest/gtest.h>

#include <iostream>

#include "S21_vector.h"

TEST(vector_test, default_constructor) {
  s21::Vector<int> v;
  EXPECT_EQ(v.size(), 0);
  EXPECT_TRUE(v.empty());
}

TEST(vector_test, inicilazer_list_constr) {
  s21::Vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(v.size(), 10);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}