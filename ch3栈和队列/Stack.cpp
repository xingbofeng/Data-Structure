/**
 * 栈相关操作：顺序栈
 */
#include <stdio.h>
#include <stdlib.h>

struct stack {
  int* stackItem; // 数据域
  int top; // 栈顶
  int stackSize; // 栈大小
};

/**
 * 初始化栈
 * @param  stack 栈的地址
 * @param  maxN  栈的大小
 * @return       初始化后栈的地址
 */
struct stack* init(struct stack* stack, int maxN) {
  stack->top = -1;
  // 动态生成数组空间
  stack->stackItem = (int*)malloc(maxN * sizeof(int*));
  stack->stackSize = maxN;
  return stack;
}

/**
 * 打印栈
 * @param stack 栈的地址
 */
void printStack(struct stack* stack) {
  for (int i = 0; i <= stack->top; ++i) {
    printf("%d", stack->stackItem[i]);
  }
}

/**
 * 入栈
 * @param stack 栈的地址
 * @param data  入栈数据
 */
void push(struct stack* stack, int data) {
  if (stack->stackSize == stack->top) {
    stack->stackItem = (int*)realloc(stack->stackItem, (++(stack->top)) * sizeof(int*));
    stack->stackItem[stack->top] = data;
    stack->stackSize++;
  } else {
    stack->stackItem[++(stack->top)] = data;
  }
}

/**
 * 出栈
 * @param  stack 栈的地址
 * @return       出栈数据
 */
int pop(struct stack* stack) {
  stack->stackSize--;
  int topData = stack->stackItem[stack->top];
  --(stack->top);
  return topData;
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
  printf("%d", pop(stack));
  printStack(stack);
  return 0;
}