/**
 * 字符串的顺序存储结构
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct {
  char *pch; // 指向字符数组的指针
  int length; // 串的长度
} String, *Pstr;

/**
 * 初始化字符串
 * @param  n
 * @return 指向字符串的指针
 */
Pstr init(int n) {
  Pstr pstr = (Pstr)malloc(sizeof(Pstr));
  if (!pstr) {
    cout << "为串分配内存失败" << endl;
  }
  char* pch = (char*)malloc(n * sizeof(char));
  if (pch) {
    pstr->pch = pch;
    pstr->length = n;
  } else {
    cout << "为字符数组分配内存失败" << endl;
    free(pstr);
    pstr = NULL;
  }
  return pstr;
}

/**
 * 把src字符串的值赋值给dest，如果dest非空，则先释放其内存
 * @param  dest 目标字符串
 * @param  src  源字符串
 * @return      赋值后的新字符串
 */
Pstr assign(Pstr dest, Pstr src) {
  int n = src->length;
  dest->length = n;
  // 先释放源串内存
  if (dest->pch) {
    free(dest->pch);
  }
  dest->pch = (char*)malloc((n + 1) * sizeof(char));
  if (!dest->pch) {
    cout << "分配空间失败" << endl;
    exit(0);
  }
  int i;
  for (i = 0; i < n; ++i) {
    dest->pch[i] = src->pch[i];
  }
  dest->pch[i] = '\0';
  return dest;
}

/**
 * 字符串的连接，把字符串2连接到字符串1的后面
 * @param  str1 字符串1
 * @param  str2 字符串2
 * @return      连接后的字符串
 */
Pstr contcate(Pstr str1, Pstr str2) {
  Pstr tmp;
  tmp = (Pstr)malloc(sizeof(Pstr));
  tmp->pch = (char*)malloc((str1->length + str2->length + 1) * sizeof(char));
  assign(tmp, str1);
  int i;
  str1->length = str1->length + str2->length;
  str1->pch = (char *)malloc((str1->length + 1) * sizeof(char));
  if (!str1->pch) {
    cout << "分配空间失败" << endl;
    exit(0);
  }
  for (i = 0; i < tmp->length; ++i) {
    str1->pch[i] = tmp->pch[i];
  }
  for (i = 0; i < str2->length; ++i) {
    str1->pch[tmp->length + i] = str2->pch[i];
  }
  str1->pch[tmp->length + i] = '\0';
  free(tmp->pch);
  free(tmp);
  return str1;
}

int main() {
  Pstr string1 = init(3);
  string1->pch = "123";
  Pstr string2 = init(3);
  string2 = assign(string2, string1);
  cout << "复制字符串1到字符串2:";
  cout << string2->pch << endl;
  cout << "连接字符串1和字符串2:";
  cout << (contcate(string1, string2))->pch << endl;
  return 0;
}