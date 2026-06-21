#include <gtest/gtest.h>

#include <iostream>

#include "S21_vector.h"

TEST(vector_test, default_constructor) {
  s21::Vector<int> v;
  EXPECT_EQ(v.size(), 0);
  EXPECT_TRUE(v.empty());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}