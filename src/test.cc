#include <iostream>

int main() {
  const int N = 5;
  char str[N] = "less";

  for (int num : str) {
    std::cout << str << ' ';
  }
}