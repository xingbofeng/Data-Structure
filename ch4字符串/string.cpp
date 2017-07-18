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
 * @param  n [description]
 * @return   [description]
 */
Pstr init(int n) {
  Pstr pstr = (Pstr)malloc(sizeof(Pstr));
  if (!pstr) {
    cout << "为串分配内存失败" << endl;
  }
  char* pch = (char*)malloc(sizeof(char*));
  if (pch) {
    pstr->pch = pch;
    pstr->length = 0;
  } else {
    cout << "为字符数组分配内存失败" << endl;
    free(pstr);
    pstr = NULL;
  }
  return pstr;
}

int main() {
  init(0);
  return 0;
}