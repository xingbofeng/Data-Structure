#include <iostream>
#include <vector>
using namespace std;
int main() {
  /**
   * 初始化数组
   */
  int num; // 数组个数
  cin >> num;
  // vector<int> arr(num);
  // malloc动态分配内存，让开辟num 个 int大小的内存空间给arr
  // 也可以使用vector
  int *arr = (int*)malloc(num * sizeof(int));
  for (int i = 0; i < num; ++i) {
    cin >> arr[i];
    // arr.push_back(arr[i]);
  }
  /**
   * 选择排序
   */
  int minIndex;
  for (int i = 0; i < num - 1; ++i) {
    minIndex = i;
    for (int j = i + 1; j < num; ++j) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    int tmp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = tmp;
  }
  for (int i = 0; i < num; ++i) {
    cout << arr[i];
  }
  cout << "" << endl;
  // C++可以用new 创建数组，如果用new 创建的，这里用delect释放内存
  free(arr);
  return 0;
}