/**
 * 队列相关操作：顺序表实现循环队列
 */
#include <stdio.h>
#include <stdlib.h>

struct dequeue {
  int* dequeueItem; // 动态分配存储空间，循环队列的数据域
  int front; // 队首
  int rear; // 队尾
  int length; // 队长
};

struct dequeue* init(struct dequeue* dequeue, int maxN) {
  dequeue->front = 0;
  dequeue->rear = 0;
  // 动态生成队列空间
  dequeue->dequeueItem = (int*)malloc(maxN * sizeof(int*));
  dequeue->length = maxN;
  return dequeue;
}

void printDequeue(struct dequeue* dequeue) {
  printf("队长为：%d\n队首指针为：%d\n队尾指针为：%d\n", (dequeue->rear - dequeue->front) % dequeue->length, dequeue->front, dequeue->rear);
  for (int i = dequeue->front; i < dequeue->rear % dequeue->length; ++i) {
    printf("第%d项为：%d\n", i, dequeue->dequeueItem[i]);
  }
}

bool isEmpty(struct dequeue* dequeue) {
  return dequeue->front == dequeue->rear;
}

bool isFull(struct dequeue* dequeue) {
  return (dequeue->rear + 1) % dequeue->length == dequeue->front;
}

void push(struct dequeue* dequeue, int data) {
  if (isFull(dequeue)) {
    printf("队列满");
    exit(0);
  }
  dequeue->dequeueItem[dequeue->rear] = data;
  dequeue->rear = (dequeue->rear + 1) % dequeue->length;
}

int shift(struct dequeue* dequeue) {
  if (isEmpty(dequeue)) {
    printf("队列空");
    exit(0);
  }
  int result = dequeue->dequeueItem[dequeue->front];
  dequeue->front = (dequeue->front + 1) % dequeue->length;
  return result;
}


int main() {
  struct dequeue* dequeue = (struct dequeue*)malloc(sizeof(struct dequeue*));
  int number;
  printf("输入共队列最大长度：");
  scanf("%d", &number);
  dequeue = init(dequeue, number);
  printDequeue(dequeue);
  push(dequeue, 1);
  push(dequeue, 2);
  printDequeue(dequeue);
  printf("出队项为：%d\n", shift(dequeue));
  printDequeue(dequeue);
  free(dequeue->dequeueItem);
  free(dequeue);
  return 0;
}