/**
 * 哈夫曼树(又称最优二叉树)
 * 哈夫曼树共n个叶子节点，2n-1个节点
 * 权值越大，距离根节点越近
 * 并且只有度为0或2的节点
 * 使用一维数组线性存储哈夫曼树
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

typedef struct {
  int weight; // 哈夫曼树权重
  int parent; // 父节点下标
  int lchild; // 左孩子下标
  int rchild; // 右孩子下标
} TNode, *PHT;

/**
 * 选择权重最小的两个数，在构造哈夫曼树的过程中调用它
 * @param pht 哈夫曼数组
 * @param n   当前构建到的位置
 * @param pa  指向int型的指针，用于暂存最小值的数组下标
 * @param pb  指向int型的指针，用于暂存次小值的数组下标
 */
void selectSubtree(PHT pht, int n, int *pa, int *pb) {
  int id, ida = -1, idb = -1; // ida存放权重最小的结点下标
  int wa = INT_MAX, wb = INT_MAX; // wa最小值，wb次小值
  for (int id = 0; id <= n; ++id) {
    // 选择没有父节点的子树或叶子节点
    if (pht[id].parent == -1) {
      // 如果比最小值还要小，则次小值保存为当前最小值，改变当前最小值的信息
      if (pht[id].weight < wa) {
        idb = ida;
        wb = wa;
        ida = id;
        wa = pht[id].weight;
        // 如果比最小值大但是比次小值小，则更新次小值
      } else if (pht[id].weight < wb) {
        idb = id;
        wb = pht[id].weight;
      }
    }
  }
  *pa = ida; // 更新传入的指针，即最大最小值的数组下标
  *pb = idb; // 更新传入的指针，即最大最小值的数组下标
  return;
}

/**
 * 创建哈夫曼树
 * @param  weights 一个所有叶子节点的权重数组
 * @param  n       叶子节点个数
 * @return         一个指针，指向哈夫曼树的顺序存储结构
 */
PHT createHtree(int weights[], int n) {
  PHT pht;
  int i, lc, rc, ntotal = (2 * n) - 1;
  pht = (PHT)malloc(ntotal * sizeof(TNode));
  // 哈夫曼树的树节点初始化
  for (i = 0; i < ntotal; ++i) {
    // 先把所有叶子节点装到1~n里
    pht[i].weight = (i < n) ? weights[i] : 0;
    pht[i].lchild = -1;
    pht[i].rchild = -1;
    pht[i].parent = -1;
  }
  // 构建哈夫曼树的过程
  for (int i = n; i < ntotal; ++i) {
    selectSubtree(pht, (i-1), &lc, &rc);
    pht[lc].parent = i;
    pht[rc].parent = i;
    pht[i].lchild = lc;
    pht[i].rchild = rc;
    pht[i].weight = pht[lc].weight + pht[rc].weight;
  }
  return pht;
}

int main() {
  int num;
  int* weights;
  cout << "输入哈夫曼树节点数量：";
  cin >> num;
  weights = (int*)malloc(sizeof(int) * num);
  createHtree(weights, num);
  return 0;
}