/**
 * 栈相关操作：主要讨论的是顺序栈
 */
#include <stdio.h>
#include <stdlib.h>

struct stack {
  int* base; // 栈底指针
  int* top; // 栈顶指针
  int stacksize; // 栈大小，多少个sizeof struct stack*
};

struct stack* init() {
  // 初始化一个栈
  struct stack* stack;
  stack = (struct stack*)malloc(sizeof(struct stack*));
  int* p = NULL; // 声明一个指针，指向栈顶也指向栈底
  // p = (int*)malloc(sizeof(int*));
  // 为栈分配指定的内存
  stack->base = p;
  stack->top = p;
  stack->stacksize = 0;
  return stack;
}

void printStack(struct stack* stack) {
  // int* p;
  // p = (int*)malloc(sizeof(int*));
  // p = stack->base;
  // while (p) {
  //   printf("%d", *p);
  //   p++;
  // }
  for (int i = 0; i < stack->stacksize; ++i) {
    printf("%d", *stack->base);
    stack->base++;
  }
}

void push(struct stack* stack, int data) {
  // 如果栈满，realloc内存
  if (stack->top - stack->base >= stack->stacksize) {
    stack->base = (int*)realloc(stack->base, (stack->stacksize + 1) * sizeof(int*));
  }
  stack->top++;
  stack->stacksize++;
  stack->top = &data;
  // int* p = (int*)malloc(sizeof(int*));
}

int main() {
  struct stack* stack;
  stack = (struct stack*)malloc(sizeof(struct stack*));
  stack = init();
  printStack(stack);
  push(stack, 2);
  // printf("%d", *stack->top);
  printStack(stack);
  return 0;
}