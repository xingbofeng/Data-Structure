#include <iostream>
#include <vector>
using namespace std;
void qsort(int arr[], int low, int high) {
  int i = low, j = high;
  int x = arr[i];
  if (low < high) {
    while(i < j) {
      // 从后往前，找到第一个小于等于x的数，交换首尾
      while(arr[j] > x && i < j) {
        j--;
      }
      arr[i] = arr[j];
      // 从前往后，找到第一个大于x的数，交换首尾
      while(arr[i] <= x && i < j) {
        i++;
      }
      arr[j] = arr[i];
    }
    // 最后让中间位置的等于x
    arr[i] = x;
    // 递归
    qsort(arr, low, i - 1);
    qsort(arr, j + 1, high);
  } else {
    // 递归结束条件
    return;
  }
}
int main() {
  /**
   * 初始化数组
   */
  int num; // 数组个数
  cin >> num;
  int *arr = (int*)malloc(num * sizeof(int));
  for (int i = 0; i < num; ++i) {
    cin >> arr[i];
  }
  /**
   * 快速排序
   */
  qsort(arr, 0, num);
  for (int i = 0; i < num; ++i) {
    cout << arr[i];
  }
  cout << "" << endl;
  free(arr);
  return 0;
}