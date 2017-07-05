/**
 * 栈相关操作：主要讨论的是顺序栈
 */
#include <stdio.h>
#include <stdlib.h>

struct stack {
  int* stackItem; // 数据域
  int top; // 栈顶
  int stackSize; // 栈大小
};

struct stack* init(struct stack* stack, int maxN) {
  stack->top = -1;
  // 动态生成数组空间
  stack->stackItem = (int*)malloc(maxN * sizeof(int*));
  stack->stackSize = maxN;
  return stack;
}

void printStack(struct stack* stack) {
  for (int i = 0; i <= stack->top; ++i) {
    printf("%d", stack->stackItem[i]);
  }
}

void push(struct stack* stack, int data) {
  if (stack->stackSize == stack->top) {
    stack->stackItem = (int*)realloc(stack->stackItem, (++(stack->top)) * sizeof(int*));
    stack->stackItem[stack->top] = data;
    stack->stackSize++;
  } else {
    stack->stackItem[++(stack->top)] = data;
  }
}

int main() {
  struct stack* stack = (struct stack*)malloc(sizeof(struct stack*));
  int number;
  scanf("%d", &number);
  stack = init(stack, number);
  printStack(stack);
  push(stack, 1);
  push(stack, 2);
  printStack(stack);
  return 0;
}