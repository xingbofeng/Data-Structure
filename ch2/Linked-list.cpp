#include <stdio.h>
#include <stdlib.h>
// 初始化链表 
struct node {
	int data;
	struct node *next;
};
int main() {
	struct node *head, *p, *q, *t;
	int i, n, a;
	printf("输入多少个数:"); 
	scanf("%d", &n); // 有多少个数
	head = NULL; // 最开始head为null，便于分配第一个节点 
	for(i=1;i<=n;i++) {
		printf("输入第%d个节点的值:", i);
		scanf("%d", &a);
		printf("\n");
		p = (struct node *)malloc(sizeof(struct node)); // 分配node 结构体大小的内存
		p->data = a;
		p->next = NULL;
		if(head == NULL) {
			head = p;
		} else {
			q->next = p;
		}
		q = p;
	}
	t = head;
	while(t!=NULL) {
		printf("%d", t->data);
		t = t->next;
	}
}
