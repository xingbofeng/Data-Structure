/**
 * 字符串简单模式匹配
 * 方法：从父串第一个字母与子串第一个字母开始比较
 * 如果不相等，则比较父串第二个字母，以此下去
 * 如果父串第二个字母与子串匹配，则比较父串第三个字母和子串第二个字母
 * 一直搜索到子串尾部，一旦匹配则匹配成功
 */
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int stringMatch(string Str, string Pat) {
  int i = 0, j = 0;
  int m = Str.size(), n = Pat.size();
  while(i <= (m - n)) {
    j = 0;
    while(Str[i] == Pat[j]) {
      i++;
      j++;
      if (j == n) {
        return (i - n);
      }
    }
    i = i - j + 1;
  }
  return -1;
}

int main() {
  string a = "1abcd";
  string b = "abc";
  cout << "子串位置为：" << stringMatch(a, b) << endl;
  return 0;
}