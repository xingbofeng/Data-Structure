/**
 * 二叉树的链式存储结构
 */

#include <iostream>
#include <stack>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/**
 * 定义二叉树的链式存储结构：二叉链表：一个左节点，一个右节点
 */
typedef struct node {
  char data;
  bool visited;
  struct node* lchild;
  struct node* rchild;
} TNode, *PBT;

/**
 * 按先序输入你的二叉树，当输入为空格，则表示空子树，叶子节点则输入两个空格
 * @param head 根节点
 */
void createBiTree(PBT head) {
  char data;
  data = getchar();
  if (data == ' ') {
    head = NULL;
    return;
  }
  head->data = data;
  head->visited = false;
  head->lchild = (PBT)(malloc(sizeof(TNode)));
  createBiTree(head->lchild);
  head->rchild = (PBT)(malloc(sizeof(TNode)));
  createBiTree(head->rchild);
}

void visitData(PBT node) {
  if (node->data) {
    cout << node->data << " ";
  }
}

bool destoryNode(PBT node) {
  if (node) {
    free(node);
  }
  return true;
}

/**
 * 递归先序遍历
 * @param head 头节点
 */
void preOrderVisit(PBT head) {
  if (!head) {
    return;
  }
  visitData(head);
  if (head->lchild) {
    preOrderVisit(head->lchild);
  }
  if (head->rchild) {
    preOrderVisit(head->rchild);
  }
}

/**
 * 使用栈进行深入优先先序遍历
 * 栈非空或指针非空时进入循环
 * 依次把指针指向左孩子节点，一旦孩子节点为空则退出循环回溯到上一个节点（栈顶为上一个节点，即父节点）
 * 把指针指向父节点的右孩子节点，继续对右孩子节点进行遍历
 * 一旦栈空了，则遍历完毕，退出顶层循环
 * @param head 头结点
 */
void stackPreOrderVisit(PBT head) {
  PBT p = head;
  stack<PBT> myStack;
  while(!myStack.empty() || (p != NULL)) {
    while (p != NULL) {
      visitData(p);
      myStack.push(p);
      p = p->lchild;
    }
    if (!myStack.empty()) {
      p = myStack.top();
      myStack.pop();
      p = p->rchild;
    }
  }
}

/**
 * 使用栈进行深度优先中序遍历(和先序遍历类似，只是输出顺序不同)
 * @param head [description]
 */
void stackinOrderVisit(PBT head) {
  PBT p = head;
  stack<PBT> myStack;
  while(!myStack.empty() || (p != NULL)) {
    while (p != NULL) {
      myStack.push(p);
      p = p->lchild;
    }
    if (!myStack.empty()) {
      p = myStack.top();
      visitData(p);
      myStack.pop();
      p = p->rchild;
    }
  }
}

/**
 * 使用两个栈来进行后序遍历非递归算法
 * 先遍历根节点，再遍历右子树，再遍历左子树，按顺序推入第一个栈
 * 第一个栈出栈推入第二个栈，逆序则是后序遍历
 * @param head
 */
void stackPostOrderVisit(PBT head) {
  PBT p = head;
  stack<PBT> myStack1, myStack2;
  myStack1.push(head);
  while(!myStack1.empty()) {
    PBT current = myStack1.top();
    myStack2.push(current);
    myStack1.pop();
    if (current->lchild) {
      myStack1.push(current->lchild);
    }
    if (current->rchild) {
      myStack1.push(current->rchild);
    }
  }
  while(!myStack2.empty()) {
    visitData(myStack2.top());
    myStack2.pop();
  }
}

/**
 * 递归中序遍历
 * @param head 头节点
 */
void inOrderVisit(PBT head) {
  if (!head) {
    return;
  }
  if (head->lchild) {
    inOrderVisit(head->lchild);
  }
  visitData(head);
  if (head->rchild) {
    inOrderVisit(head->rchild);
  }
}

/**
 * 递归后序遍历
 * @param head 头节点
 */
void postOrderVisit(PBT head) {
  if (!head) {
    return;
  }
  if (head->lchild) {
    postOrderVisit(head->lchild);
  }
  if (head->rchild) {
    postOrderVisit(head->rchild);
  }
  visitData(head);
}

/**
 * 队列实现层次遍历
 * @param head
 */
void levelOrderVisit(PBT head) {
  PBT p = head;
  queue<PBT> myQueue;
  if (head) {
    myQueue.push(p);
    while(!myQueue.empty()) {
      p = myQueue.front();
      visitData(p);
      myQueue.pop();
      if (p->lchild) {
        myQueue.push(p->lchild);
      }
      if (p->rchild) {
        myQueue.push(p->rchild);
      }
    }
  }
}

int main() {
  cout << "按先序输入你的二叉树，当输入为空格，则表示空子树，叶子节点则输入两个空格：" << endl;
  PBT head = (PBT)(malloc(sizeof(TNode)));
  createBiTree(head);
  cout << "先序遍历结果为：";
  preOrderVisit(head);
  cout << endl << "中序遍历结果为：";
  inOrderVisit(head);
  cout << endl << "后序遍历结果为：";
  postOrderVisit(head);
  cout << endl << "广度优先层次遍历结果为：";
  levelOrderVisit(head);
  cout << endl << "先序非递归遍历结果为：";
  stackPreOrderVisit(head);
  cout << endl << "中序非递归遍历结果为：";
  stackinOrderVisit(head);
  cout << endl << "后序非递归遍历结果为：";
  stackPostOrderVisit(head);
  return 0;
}