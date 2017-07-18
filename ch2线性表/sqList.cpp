/**
 * 顺序表相关操作
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define INCREMENT 10
typedef int ElemType; // 为int型申请别名，便于区分，实际上还是int类型
struct sqList {
  ElemType *elem;
  int length; // 顺序表的长度
  int listsize; // 顺序表分配的存储容量(以sizeof为单位)
};

/**
 * 初始化顺序表
 * @param  list 顺序表指针
 * @return      是否创建顺序表成功
 */
bool initList(struct sqList *list) {
  int num;
  printf("输入顺序表长度：");
  scanf("%d", &num);
  list->elem = (ElemType*)malloc(num * sizeof(ElemType));
  if (!list->elem) {
    return false;
  }

  for (int i = 0; i < num; ++i) {
    printf("输入顺序表第%d项：", i);
    int data;
    scanf("%d", &data);
    list->elem[i] = data;
  }
  list->length = num;
  list->listsize = num;
  return true;
}

/**
 * 销毁顺序表
 * @param list 顺序表指针
 */
void destoryList(struct sqList *list) {
  free(list->elem); // 释放内存
  list->length = 0;
  list->listsize = 0;
  free(list);
}

/**
 * 获取顺序表的length
 * @param  list 顺序表头指针
 * @return      顺序表长度
 */
int getLength(struct sqList *list) {
  return list->length;
}

/**
 * 打印顺序表
 * @param list 顺序表头指针
 */
void printList(struct sqList *list) {
  printf("顺序表的长度为：%d\n顺序表的存储容量为：%d\n", list->length, list->listsize);
  for (int i = 0; i < list->length; ++i) {
    printf("顺序表的第%d项为：%d\n", i, list->elem[i]);
  }
}

/**
 * 向顺序表插入数据
 * @param  list  顺序表数据指针
 * @param  index 插入位置
 * @param  data  插入的数据
 * @return       是否插入成功
 */
bool insertItem(struct sqList *list, int index, ElemType data) {
  ElemType *newBase;
  // index不合法返回false
  if (index < 1 || index > list->length - 1) {
    return false;
  }
  if (list->length >= list->listsize) {
    // 使用realloc函数新分配内存
    newBase = (ElemType *)realloc(list->elem, (list->listsize + INCREMENT) * sizeof(ElemType));
    // 内存分配不成功返回false
    if (!newBase) {
      return false;
    }
    list->elem = newBase;
    list->listsize += INCREMENT;
    list->length++;
  }
  for (int i = list->length - 1; i > index; --i) {
    list->elem[i] = list->elem[i - 1];
  }
  list->elem[index] = data;
  return true;
}

/**
 * 删除顺序表中一个数
 * @param  list  顺序表的数据指针
 * @param  index 删除位置
 * @return       是否删除成功
 */
bool delectItem(struct sqList *list, int index) {
  // index不合法返回false
  if (index < 1 || index > list->length - 1) {
    return false;
  }
  // 删除位置以后的每项左移
  for (int i = index; i < list->length - 1; ++i) {
    list->elem[i] = list->elem[i + 1];
  }
  list->length--;
  return true;
}

/**
 * 合并顺序表的算法
 * @param  list1 指向顺序表一的指针
 * @param  list2 指向顺序表二的指针
 * @return       新的顺序表
 */
struct sqList *mergeLists(struct sqList *list1, struct sqList *list2) {
  int point1 = 0, point2 = 0;
  struct sqList *resultList;
  resultList = (struct sqList *)malloc(sizeof(sqList));
  // 分配内存
  resultList->elem = (ElemType *)malloc((list1->length + list2->length) * sizeof(ElemType));
  resultList->length = list1->length + list2->length;
  resultList->listsize = list1->length + list2->length;
  while (point1 < list1->length && point2 < list2->length) {
    if (list1->elem[point1] < list2->elem[point2]) {
      resultList->elem[point1 + point2] = list1->elem[point1];
      point1++;
    } else {
      resultList->elem[point1 + point2] = list2->elem[point2];
      point2++;
    }
  }
  if (point1 < list1->length) {
    for (int i = point1 + point2; i < list1->length + list2->length; ++i) {
      resultList->elem[i] = list1->elem[i - point2];
    }
  }
  if (point2 < list2->length) {
    for (int i = point1 + point2; i < list1->length + list2->length; ++i) {
      resultList->elem[i] = list2->elem[i - point1];
    }
  }
  return resultList;
}

int main() {
  struct sqList *list1;
  // 结构体也要先分配内存使其初始化
  // 不仅要初始化结构体成员指针，本身结构体指针也需要初始化
  list1 = (struct sqList *)malloc(sizeof(sqList));
  // 创建顺序表
  if (!initList(list1)) {
    printf("创建顺序表失败！");
    exit(0);
  }
  printList(list1);
  // 在顺序表的插入一个节点
  if (!insertItem(list1, 1, 2)) {
    printf("向顺序表插入元素失败");
    exit(0);
  }
  printList(list1);
  // 在顺序表的删除一个节点
  if (!delectItem(list1, 1)) {
    printf("顺序表删除元素失败");
    exit(0);
  }
  printList(list1);
  struct sqList *list2;
  list2 = (struct sqList *)malloc(sizeof(sqList));
  if (!initList(list2)) {
    printf("创建顺序表失败！");
    exit(0);
  }
  struct sqList *list;
  list = (struct sqList *)malloc(sizeof(sqList));
  // 合并两个顺序表
  list = mergeLists(list1, list2);
  printList(list);
  destoryList(list1);
  destoryList(list2);
  destoryList(list);
  return 0;
}