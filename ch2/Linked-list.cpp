#include <stdio.h>
#include <stdlib.h>
// ��ʼ������ 
struct node {
	int data;
	struct node *next;
};
int main() {
	struct node *head, *p, *q, *t;
	int i, n, a;
	printf("������ٸ���:"); 
	scanf("%d", &n); // �ж��ٸ���
	head = NULL; // �ʼheadΪnull�����ڷ����һ���ڵ� 
	for(i=1;i<=n;i++) {
		printf("�����%d���ڵ��ֵ:", i);
		scanf("%d", &a);
		printf("\n");
		p = (struct node *)malloc(sizeof(struct node)); // ����node �ṹ���С���ڴ�
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
