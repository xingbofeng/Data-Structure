#include <iostream>
#include <vector>
using namespace std;
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
   * 冒泡排序
   */
  for (int i = 0; i < num; ++i) {
    for (int j = 0; j < num - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
  for (int i = 0; i < num; ++i) {
    cout << arr[i];
  }
  cout << "" << endl;
  free(arr);
  return 0;
}