#include <iostream>

int main() { int arr[10] = {8, 4, 21, 7, 5, 0, 43, -3, 9, 7}; }

void merge_sort(int* arr, int begin, int end) {
  int l = end - begin;
  int l_left = l / 2;
  int l_right = end - l / 2;
  int left[l_left] = {0};
  int right[l_right] = {0};
  int index = begin;
  for (int i = 0; i < l / 2; i++) {
    left[i] = arr[index++];
  }
  for (int i = 0; i < end - l / 2; i++) {
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

void merge(int* arr, int lenght){
    
}