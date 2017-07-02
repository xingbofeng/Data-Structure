#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
};

/**
 * 初始化链表
 * @return [struct node *] 返回指向head的指针
 */
struct node *initList() {
	int n; // 多少项
	printf("输入共多少个节点：");
	scanf("%d", &n);
	struct node *headNode, *currentNode, *preNode;
	headNode = NULL;
	int eachData; // 输入data值
	for (int i = 1; i <= n; ++i) {
		printf("输入第%d个节点的值：", i);
		scanf("%d", &eachData);
		currentNode = (struct node *)malloc(sizeof(struct node));
		currentNode->data = eachData;
		currentNode->next = NULL;
		if (headNode == NULL) {
			// 第一次把head指向第一个节点
			headNode = currentNode;
		} else {
			// 第2~n次，把上一个节点的next指针指向当前节点
			preNode->next = currentNode;
		}
		// 保存当前节点上下文，下一次使用
		preNode = currentNode;
	}
	return headNode;
}

/**
 * 打印链表内容
 * @param headNode 头指针
 */
void printList(struct node *headNode) {
	struct node *currentNode = headNode;
	printf("链表内容为：");
	while (currentNode != NULL) {
		printf("->%d", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("\n");
}

/**
 * 翻转链表
 * @param  headNode 头指针
 * @return headNode 翻转后的头指针
 */
struct node *reverseList(struct node *headNode) {
	// 少于两个节点没有翻转的必要
	if (NULL == headNode || NULL == headNode->next) {
		return headNode;
	}
	struct node *currentNode, *preNode, *nextNode;
	// 要改变headNode的指向，先用preNode暂存headNode
	preNode = headNode;
	currentNode = headNode->next;
	// headNode变为尾节点，next指向NULL
	headNode->next = NULL;
	// currentNode不是NULL时，进入循环
	while (currentNode) {
		// 暂存nextNode，下次使用
		nextNode = currentNode->next;
		// 循环中当前节点的next指向前一个节点
		currentNode->next = preNode;
		// 再更新preNode和currentNode
		preNode = currentNode;
		currentNode = nextNode;
	}
	// 最后的指向为：currentNode为空指针,因为结束了while循环,而preNode才是头指针
	headNode = preNode;
	return headNode;
}

void destoryList(struct node *headNode) {
	struct node *currentNode = headNode;
	while (currentNode != NULL) {
		free(currentNode);
		currentNode = currentNode->next;
	}
	printf("成功还原链表内存！");
}

/**
 * 向链表中插值
 * @param  headNode 头指针
 * @param  index    位置
 * @param  data     数据
 * @return          是否插入成功
 */
bool insertNode(struct node *headNode, int index, int data) {
	// nextNode用于暂存currentNode的next节点,newNode是新插入的节点
	struct node *currentNode = headNode, *nextNode, *newNode;
	// 初始化newNode
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->data = data;
	int location = 0;
	while (currentNode != NULL) {
		if (index == location) {
			printf("%d\n", location);
			nextNode = currentNode->next;
			currentNode->next = newNode;
			newNode->next = nextNode;
			return true;
		} else {
			location++;
			currentNode = currentNode->next;
		}
	}
	return false;
}

/**
 * 删除链表的某个节点
 * @param  headNode 头指针
 * @param  index    位置
 * @return          是否删除成功
 */
bool removeNode(struct node *headNode, int index) {
	struct node *currentNode = headNode;
	for (int i = 0; i < index; ++i) {
		if (currentNode == NULL) {
			return false;
		}
		currentNode = currentNode->next;
	}
	currentNode->next = currentNode->next->next;
	free(currentNode->next);
	return true;
}

struct node *mergeLists(struct node *list1, struct node *list2) {
	struct node *currentNode = list1, *preNode;
	while (currentNode != NULL) {
		preNode = currentNode;
		currentNode = currentNode->next;
	}
	preNode->next = list2;
	return list1;
}

int main() {
	struct node *headNode;
	// 初始化链表
	printf("初始化链表1\n");
	headNode = initList();
	printList(headNode);
	// 翻转链表
	printf("翻转后的");
	headNode = reverseList(headNode);
	printList(headNode);
	// 链表插入
	int insertIndex, insertData;
	printf("以此输入插入节点的index和data：");
	scanf("%d%d", &insertIndex, &insertData);
	if (insertNode(headNode, insertIndex, insertData)) {
		printf("插入后的");
		printList(headNode);
	} else {
		printf("插入失败，位置超出！");
	}
	int removeIndex;
	printf("以此输入删除节点的index：");
	scanf("%d", &removeIndex);
	if (removeNode(headNode, removeIndex)) {
		printf("删除后的");
		printList(headNode);
	} else {
		printf("删除失败，位置超出！");
	}
	printList(headNode);
	// 合并链表
	printf("初始化链表2\n");
	struct node *headNode2 = initList();
	headNode = mergeLists(headNode, headNode2);
	printList(headNode);
	// 销毁链表
	destoryList(headNode);
	return 0;
}
