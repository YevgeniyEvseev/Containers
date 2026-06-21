// #include <stdio.h>

#include <iostream>

#include "../containers.h"
#include "gtest/gtest.h"

TEST(stack_test, default_constructor) {
  s21::stack<int> null_stack;
  EXPECT_EQ(null_stack.size_stack(), 0);
  EXPECT_TRUE(null_stack.empty());
}

TEST(stack_test, constructor) {
  s21::stack<int> st{2, 3, 4};
  EXPECT_EQ(st.pop(), 4);
  EXPECT_EQ(st.pop(), 3);
  EXPECT_EQ(st.pop(), 2);
}

TEST(stack_test, constructor2) {
  int arr[3] = {2, 3, 4};
  s21::stack<int*> st{arr, arr + 1, arr + 2};
  EXPECT_EQ(*st.pop(), 4);
  EXPECT_EQ(*st.pop(), 3);
  EXPECT_EQ(*st.pop(), 2);
  // st.pop();
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}