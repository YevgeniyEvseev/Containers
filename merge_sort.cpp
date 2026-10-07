#include <iostream>

void merge_sort(int* arr, int begin, int average, int end);
void merge(int* arr, int lenght);

int main() {
  int arr[1] = {6};
  // merge_sort(arr, 6, 8);
  merge(arr, 1);
  for (auto i : arr) std::cout << i << ' ';
  std::cout << std::endl;
}

void merge_sort(int* arr, int begin, int average, int end) {
  int l_left = average - begin;
  int l_right = end + 1 - l_left - begin;
  if (l_right <= 0 || l_left <= 0) return;
  int left[l_left] = {0};
  int right[l_right] = {0};
  int index = begin;
  for (int i = 0; i < l_left; i++) {
    left[i] = arr[index++];
  }
  for (int i = 0; i < l_right; i++) {
    right[i] = arr[index++];
  }
  int i_left = 0;
  int i_right = 0;
  index = begin;
  while (i_left < l_left && i_right < l_right) {
    if (left[i_left] <= right[i_right])
      arr[begin++] = left[i_left++];
    else
      arr[begin++] = right[i_right++];
  }
  while (i_left < l_left) {
    arr[begin++] = left[i_left++];
  }
  while (i_right < l_right) {
    arr[begin++] = right[i_right++];
  }
}

void merge(int* arr, int lenght) {
  int i = 0;
  int index = 0;
  for (i = 2; i < lenght; i *= 2) {
    index = 0;
    int l = i / 2;
    while (index < lenght) {
      int index_end = index + i - 1;
      if (index_end > lenght) {
        index_end = lenght - 1;
      }
      merge_sort(arr, index, index + l, index_end);
      index += i;
    }
    if (index - lenght != i)
      merge_sort(arr, index - i, index - i + l, lenght - 1);
  }
  if (index - lenght != i) merge_sort(arr, 0, i / 2, lenght - 1);
}