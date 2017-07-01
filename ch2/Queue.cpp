#include <stdio.h>
#include <stdlib.h>

struct queue {
  int data[100]; // 队列数据
  int head; // 队首
  int tail; // 队尾
};

void push(struct queue *q, int data) {
  q->data[q->tail] = data;
  q->tail++;
}

int shift(struct queue *q) {
  int index = q->head;
  q->head++;
  return q->data[index];
}

int main() {
  /**
   * 初始化队列
   */
  struct queue *q;
  // 一定要申请内存空间，否则发生溢出
  q = (struct queue *)malloc(sizeof(struct queue));
  q->head = 1;
  q->tail = 1;
  // 往队列插入9个数据
  int data[3];
  for (int i = 0; i < 3; ++i) {
    scanf("%d", &data[i]);
    push(q, data[i]);
  }
  /**
   * 遍历队列，出队
   */
  while(q->head < q->tail) {
    printf("%d\n", shift(q));
  }
  return 0;
}